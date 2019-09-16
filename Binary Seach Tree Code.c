typedef struct bstNode {
 struct bstNode *left, *right;
 int data;
} bstNode;

//This code it to check how many elements in the tree are divisable by value
int countDiv(bstNode *root, int value){
  if(root == NULL)
    return 0;
  int res = countDiv(root->left, value)+countDiv(root->right, value);
  if(root->data % value == 0)
    res++; 
    return res;
}


// This is to count total nodes in an BST
int count(bstNode* root){
  
  if (root == NULL)
    return 0;

int res = count(root->right) + count(root->left);
res++;
return res;
}

// This function will count number of even values
int even_numbers(bstNode* root){
  
  if (root == NULL)
    return 0;

int res = count(root->right) + count(root->left);

if(root->data % 2 == 0)
//if(root->data % 2 != 0) for odd
//if(root->data % target == 0) to see how many same value in BST 
{
  res++;
}
return res;
}


// This function tells if the target is in the BST

int search(bstNode *root, char* target)
{
  if(root == NULL)
    return 0;
  
  int cmp = strcmp(target, root->str);
  
  if (cmp < 0)
    return search(root->left, target);

  else if (cmp > 0)
    return search(root->right, target);
  
  return 1;
}


// This function return smallest leaf nodes

/*typedef struct bstNode {
 int data;
 struct bstNode *left;
 struct bstNode *right;
} bstNode;*/


bstNode* find_min_leaf(bstNode* root) {
  
  if(root == NULL)
    return NULL;

  if(root->left==NULL && root->right==NULL)
    return root;

  if(root->left!=NULL)
    return find_min_leaf(root->left);
  
  return find_min_leaf(root->right);
}