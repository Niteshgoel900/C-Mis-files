/*  COP 3502C Final term Assignment 2 This program is written by: Nitesh Goel */
//  main.c
//  Final Term Assignment 1
//
//  Created by Nitesh Goel on 7/22/19.
//  Copyright © 2019 Nitesh Goel. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
FILE *out_file;


struct tree_node {
    char name[MAX];
    struct tree_node *left;
    struct tree_node *right;
}*node;

void preorder(struct tree_node *ptr, FILE *out_file);
void inorder(struct tree_node *ptr, FILE *out_file);
void postorder(struct tree_node *ptr, FILE *out_file);
struct tree_node* insert(struct tree_node *root, char  *element);
int search(struct tree_node *current_ptr, char *val);
int CountBefore(struct tree_node* root,  char  searchKey[]);
struct tree_node* delete_num(struct tree_node* root, char *value);
struct tree_node* findNode(struct tree_node *current_ptr, char *value);
struct tree_node* parent(struct tree_node *root, struct tree_node *node);
struct tree_node* minVal(struct tree_node *root);
struct tree_node* maxVal(struct tree_node *root);
int isLeaf(struct tree_node *node);
int hasOnlyLeftChild(struct tree_node *node);
int hasOnlyRightChild(struct tree_node *node);



int main(void)
{
    int num_elements,num_search,num_delete, i;
    int x;
    char name[MAX];
    
    FILE *openfile = fopen("in.txt", "r");
    fscanf(openfile, "%d %d %d", &num_elements, &num_search, &num_delete);
    
    FILE *out_file= fopen("out.txt", "w");
    
    for (i = 0; i < num_elements; i++)
    {
        fscanf(openfile, "%s", name);
        node=insert(node, name);
    }
    
    fprintf(out_file, "Pre Order: ");
    preorder(node, out_file);
    fprintf(out_file,"\nIn Order: ");
    inorder(node, out_file);
    fprintf(out_file,"\nPost Order: ");
    postorder(node, out_file);
    fprintf(out_file,"\n");
    
    fprintf(out_file,"\nSearch Phase:\n");
    for (i = 0; i < num_search; i++)
    {
        fscanf(openfile, "%s", name);
        x = search(node, name);
        if(x == 1)
        {
            fprintf(out_file,"%s: Found, Items before: %d\n",name, CountBefore(node, name));
        }
        else
        {
            fprintf(out_file,"%s: Not found, Items before: 0\n", name);
        }
    }
    
    fprintf(out_file,"\nDelete Phase:\n");
    for (i = 0; i < num_delete; i++)
    {
        fscanf(openfile, "%s", name);
        x = search(node, name);
        if(x == 1)
        {
            fprintf(out_file,"%s: deleted\n", name);
            node = delete_num(node,name);
        }
        else
        {
            fprintf(out_file,"%s: Does not exist in BST\n", name);
        }
    }
    
    fprintf(out_file,"\n");
    fprintf(out_file,"Pre Order: ");
    preorder(node, out_file);
    fprintf(out_file,"\nIn Order: ");
    inorder(node, out_file);
    fprintf(out_file,"\nPost Order: ");
    postorder(node, out_file);
    fprintf(out_file,"\n");
    
    
    return 0;
    fclose(out_file);
}

void preorder(struct tree_node *ptr, FILE *out_file)
{
    if (node == NULL)
    {
        fprintf(out_file,"The BST in empty");
        return;
    }// End of if condition
    if (ptr != NULL)
    {
        fprintf(out_file,"%s ", ptr->name);
        preorder(ptr->left, out_file);
        preorder(ptr->right, out_file);
    }
}

void inorder(struct tree_node *ptr, FILE *out_file)
{
    if (node == NULL)
    {
        fprintf(out_file,"The BST in empty");
        return;
    }
    // Only traverse the node if it's not null.
    if (ptr != NULL)
    {
        inorder(ptr->left, out_file);
        fprintf(out_file,"%s ", ptr->name);
        inorder(ptr->right, out_file);
    }
}

void postorder (struct tree_node *ptr, FILE *out_file)
{
    if (node == NULL)
    {
        fprintf(out_file,"The BST in empty");
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left, out_file);
        postorder(ptr->right, out_file);
        fprintf(out_file,"%s ", ptr->name);
    }
}


struct tree_node* insert(struct tree_node *node, char  *element)
{
    struct tree_node *ptr;
    ptr = (struct tree_node*)malloc(sizeof(struct tree_node));
    ptr->left = NULL;
    ptr->right = NULL;
    strcpy(ptr->name, element);
    
    if (node == NULL)
        return ptr;
    else
    {
        if (strcmp(element, node->name)>0)
        {
            if (node->right != NULL)
                node->right = insert(node->right, element);
            else
                node->right = ptr;
        }
        else
        {
            if (node->left != NULL)
                node->left = insert(node->left, element);
            else
                node->left = ptr;
        }
        return node;
    }
}


int search(struct tree_node *node, char name[])
{
    // Check if there are nodes in the tree.
    if (node != NULL)
    {
        // Found the value at the root.
        if (strcmp(node->name, name) == 0)
            return 1;
        
        // Search to the left.
        if (strcmp(node->name, name) > 0)
            
            return search(node->left, name);
        
        // Or...search to the right.
        else
            return search(node->right, name);
    }
    else
        return -1;
}


int CountBefore(struct tree_node* root, char searchKey[])
{
    int i = 0;
    if(root != NULL)
    {
        if(strcmp(root->name, searchKey)<0)
            i++;
        
        i = i + CountBefore(root->left, searchKey);
        i = i + CountBefore(root->right, searchKey);
    }
    return i;
}


struct tree_node* delete_num(struct tree_node* root, char *value) {
    
    struct tree_node *delnode, *new_del_node, *save_node;
    struct tree_node *par;
    char *save_val;
    
    delnode = findNode(root, value); // Get a pointer to the node to delete.
    
    par = parent(root, delnode); // Get the parent of this node.
    
    // Take care of the case where the node to delete is a leaf node.
    if (isLeaf(delnode)) {
        
        // Deleting the only node in the tree.
        if (par == NULL) {
            free(root); // free the memory for the node.
            return NULL;
        }
        
        // Deletes the node if it's a left child.
        if (strcmp(value, par->name) < 0 )
        {
            free(par->left); // Free the memory for the node.
            par->left = NULL;
        }
        
        // Deletes the node if it's a right child.
        else {
            free(par->right); // Free the memory for the node.
            par->right = NULL;
        }
        
        return root; // Return the root of the new tree.
    }
    
    // Take care of the case where the node to be deleted only has a left
    // child.
    if (hasOnlyLeftChild(delnode)) {
        
        // Deleting the root node of the tree.
        if (par == NULL) {
            save_node = delnode->left;
            free(delnode); // Free the node to delete.
            return save_node; // Return the new root node of the resulting tree.
        }
        
        // Deletes the node if it's a left child.
        if (strcmp(value, par->name) < 0 )
        {
            save_node = par->left; // Save the node to delete.
            par->left = par->left->left; // Readjust the parent pointer.
            free(save_node); // Free the memory for the deleted node.
        }
        
        // Deletes the node if it's a right child.
        else {
            save_node = par->right; // Save the node to delete.
            par->right = par->right->left; // Readjust the parent pointer.
            free(save_node); // Free the memory for the deleted node.
        }
        
        return root; // Return the root of the tree after the deletion.
    }
    
    // Takes care of the case where the deleted node only has a right child.
    if (hasOnlyRightChild(delnode)) {
        
        // Node to delete is the root node.
        if (par == NULL) {
            save_node = delnode->right;
            free(delnode);
            return save_node;
        }
        
        // Delete's the node if it is a left child.
        if (strcmp(value, par->name) < 0 )
        {
            save_node = par->left;
            par->left = par->left->right;
            free(save_node);
        }
        
        // Delete's the node if it is a right child.
        else {
            save_node = par->right;
            par->right = par->right->right;
            free(save_node);
        }
        return root;
    }
    
    // Find the new physical node to delete.
    new_del_node = minVal(delnode->right);
    //save_val = new_del_node->name;
    
    strcpy(save_val,new_del_node->name);
    
    delete_num(root, save_val);  // Now, delete the proper value.
    
    // Restore the data to the original node to be deleted.
    //delnode->name = save_val;
    
    strcpy(delnode->name,save_val);
    
    return root;
}

struct tree_node* findNode(struct tree_node *current_ptr, char *value)
{
    if (current_ptr != NULL)
    {
        // Found the value at the root.
        if (strcmp(current_ptr->name, value) == 0)
            return current_ptr;
        // Search to the left.
        if (strcmp(value, current_ptr->name) < 0)
            return findNode(current_ptr->left, value);
        // Or...search to the right.
        else
            return findNode(current_ptr->right, value);
    }
    else
        return NULL; // No node found.
}

struct tree_node* parent(struct tree_node *root, struct tree_node *node)
{
    // Take care of NULL cases.
    if (root == NULL || root == node)
        return NULL;
    // The root is the direct parent of node.
    if (root->left == node || root->right == node)
        return root;
    // Look for node's parent in the left side of the tree.
    if (strcmp(node->name, root->name) < 0)
        return parent(root->left, node);
    // Look for node's parent in the right side of the tree.
    else if (strcmp(node->name, root->name) > 0)
        return parent(root->right, node);
    return NULL; // Catch any other extraneous cases.
}

struct tree_node* minVal(struct tree_node *root)
{
    // Root stores the minimal value.
    if (root->left == NULL)
        return root;
    // The left subtree of the root stores the minimal value.
    else
        return minVal(root->left);
}

struct tree_node* maxVal(struct tree_node *root)
{
    // Root stores the maximal value.
    if (root->right == NULL)
        return root;
    // The right subtree of the root stores the maximal value.
    else
        return maxVal(root->right);
}
// Returns 1 if node is a leaf node, 0 otherwise.
int isLeaf(struct tree_node *node)
{
    return (node->left == NULL && node->right == NULL);
}

// Returns 1 if node has a left child and no right child.
int hasOnlyLeftChild(struct tree_node *node)
{
    return (node->left!= NULL && node->right == NULL);
}

// Returns 1 if node has a right child and no left child.
int hasOnlyRightChild(struct tree_node *node)
{
    return (node->left== NULL && node->right != NULL);
}
