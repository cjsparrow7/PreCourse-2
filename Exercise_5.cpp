#include <bits/stdc++.h> 
using namespace std; 
  
// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function is same in both iterative and recursive*/
int partition(int arr[], int l, int h) 
{ 
    //Do the comparison and swapping here
    int temp = arr[h];
    int i = (l - 1);
 
    for (int j = l; j < h; j++) 
    {
        if (arr[j] <= temp) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
} 
  
/* A[] --> Array to be sorted,  
l --> Starting index,  
h --> Ending index */
void quickSortIterative(int arr[], int l, int h) 
{ 
    //Try to think that how you can use stack here to remove recursion.

    // Create a stack.
    int stack[h - l + 1];
 
    // Initialize top of stack.
    int top = -1;
 
    // Push initial values of l and h to stack.
    stack[++top] = l;
    stack[++top] = h;
 
    // Keep popping from stack while is not empty.
    while (top >= 0) 
    {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
 
        // Set pivot element at its correct position.
        int pivot = partition(arr, l, h);
 
        // Elements on right side of pivot, are pushed to right side of the stack.
        if (pivot + 1 < h) 
        {
            stack[++top] = pivot + 1;
            stack[++top] = h;
        }

        // Elements on left side of pivot, are pushed to left side of the stack.
        if (pivot - 1 > l) 
        {
            stack[++top] = l;
            stack[++top] = pivot - 1;
        }
    }
} 
  
// A utility function to print contents of arr 
void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 }; 
    int n = sizeof(arr) / sizeof(*arr); 
    quickSortIterative(arr, 0, n - 1); 
    printArr(arr, n); 
    return 0; 
} 