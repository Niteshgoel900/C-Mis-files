/*  COP 3502C Final term Assignment 1 This program is written by: Nitesh Goel */
//  main.c
//  Final Term Assignment 1
//
//  Created by Nitesh Goel on 7/13/19.
//  Copyright © 2019 Nitesh Goel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct coordinates
{
    int x;
    int y;
} s;

// Function prototypes
void merge(s arr[], int l, int m, int r);
void mergeSort(s arr[], int l, int r);
int binarySearch(s arr[], int x, int y, int len);
int Compare_coordinate(s L, s R);

int main(void)
{
    int n, i, x, y;
    FILE *openfile = fopen("in.txt", "r"); // Opens in.txr
    fscanf(openfile, "%d", &n); // We have to scan the first element to determine the size of the array
    s *arr; // Creating an struct array
    arr=(s*)malloc(sizeof(s)*n); // Allocating memory for the array will need to free later
    
    //Now we have to create a for loop in order to store all the coordinates into the array
    for(i=0; i<n; i++)
    {
        fscanf(openfile, "%d" "%d", &x, &y);
        arr[i].x = x;
        arr[i].y = y;
    }
    
    mergeSort(arr,0, n-1);
    
    FILE *out_file= fopen("out.txt", "w");
    
    // This loop is to store each coordinate into the out_file
    for(i=0; i<n; i++)
    {
        fprintf(out_file, "%d %d\n", arr[i].x, arr[i].y);
    }
    
    fclose(out_file); // We no longer need the file open as merge sort has been completed and written
    
    printf("\"Sorted and output written\"\n");
    
    while(1) // This is an infinite loop
    {
        int e, o, z;
        printf("Search input (x y):");
        scanf("%d %d", &e,&o);
        
        if(e == -999 && o == -999 ) // This is the only condition that will break the loop
        {
            exit(0);
        }
        
        z = binarySearch(arr, e, o, n); // We need to store the binarysearch in a variable as it return 1 or -1
        
        if(z == -1)
        {
            printf("Output: Not Found\n");
        }
        else
            printf("Output: Found at record %d\n", z+1);
    }
    
    return 0;
}


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(s *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create struct arrays */
    s L[n1];
    s R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (Compare_coordinate(L[i], R[i]))
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


int Compare_coordinate(s L, s R)
{
    if( L.x < R.x)
    {
        return 1;
    }
    
    else if(L.x == R.x)
    {
        if(L.y < R.y)
        {
            return 1;
        }
        else if (L.y == R.y)
        {
            return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}


/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(s arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


int binarySearch(s arr[], int x, int y, int len)
{
    int l = 0, h = len - 1;
    int mid;
    s search;
    search.x = x;
    search.y = y;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid].x == x && arr[mid].y == y)
            return mid;
        // If item greater, ignore left half
        if (Compare_coordinate(arr[mid],search))
            l = mid + 1;
        // If item is smaller, ignore right half
        else
            h = mid - 1;
    }
    // if we reach here, then element was
    // not present
    return -1;
}
