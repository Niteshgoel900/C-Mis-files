/* COP 3502C Midterm Assignment Two This program is written by: Nitesh Goel */
//
//  main.c
//  Assignment 2
//
//  Created by Nitesh Goel on 6/17/19.
//  Copyright © 2019 Nitesh Goel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// This is the struct that will be used to create a doubly linked list
typedef struct node{
    int data;
    struct node *next, *prev; // This allows use to be able to go back and fourth in a linked list
}node;

node *root = NULL; // We are instalizing the head of the list aka root
node *last = NULL; // We are keeping track of the rear of the list before the root

//The role of this function is to create a linked list
void create_list(int n)
{
    int i = 0;
    node *temp = NULL; // This is the new node to be inserted
    node *t = NULL;
    for (i = 0; i < n; i++) // This is adding n amount of nodes
    {
        temp = (node*)malloc(sizeof(node)); //Will have to free temp later on in code to prevent memory leak
        temp->data = i+1;
        temp->next = NULL;
        if(root != NULL)
        {
            t = root;
            while(t->next!=NULL)
                t = t->next;
            t->next = temp;
        }
        else // If there is nothing in the root
        {
            root = temp;
        }
    }
    temp->next=root;
    last = t->next; // This is setting the last node of the linked list to the root thus creating a circular linked list
    free(temp); // Freeing dynamically allocated memory in line 29
}


void josephus(int n, int k)
{
    int i=0;
    
    node *t = root; // This will allow us to access the created linked list
    node *temp = NULL;
    
    while(n-->1) // Loop till 1 remaining
    {
        for(i=0; i<k-1; i++)
        {
            temp = t;
            //printf("-------------------");
            //printf("\ntemp[%d] %d\n",i, temp->data);
            t = t->next;
        }
        temp->next = t->next;
        //printf("temp->next: %d \n",temp->next->data);
        t = temp->next;
        // printf("t: %d\n",t->data);
        // printf("-------------------");
        
    }
    root = t; // Printing the last one reamining
    printf("The winning position is %d\n",root->data);
}



int main(void)
{
    int numpeople;
    int position_killed;
    
    printf("Number of people in the circle:");
    scanf("%d", &numpeople);
    printf("Number of people skipped:");
    scanf("%d", &position_killed);
    
    create_list(numpeople);
    josephus(numpeople, position_killed);
    
    return 0;
}
