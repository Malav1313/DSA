#include <stdio.h>
// Function to find and print the Next Greater Element for each element
void printNGE(int arr[], int size)
{
    int nextGreater[size]; // Array to store NGE for each element
    int stack[size];       // Stack to keep track of indices
    for (int i = 0; i < size; i++)
    {
        nextGreater[i] = -1; // Initialize as -1, indicating no NGE found yet
    }
    int top = -1; // Initialize the stack top
    // Process each element in the array
    for (int i = 0; i < size; i++)
    {
        // Check if the stack is not empty and the current element is greater
        // than the element at the index stored in the stack
        while (top >= 0 && arr[i] > arr[stack[top]])
        {
            nextGreater[stack[top]] = arr[i]; // Set NGE for the element in the stack
            top--;                            // Pop the element from the stack
        }
        // Push the current element's index onto the stack
        stack[++top] = i;
    }
    // Print the NGE for each element
    for (int i = 0; i < size; i++)
    {
        printf("NGE for %d = %d\n", arr[i], nextGreater[i]);
    }
}
int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Next Greater Elements:\n");
    printNGE(arr, size);
    return 0;
}
