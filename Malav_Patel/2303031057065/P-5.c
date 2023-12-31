#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct
{
    int height;
    int index;
} StackElement;
int largestRectangleArea(int *heights, int heightsSize)
{
    int maxArea = 0;
    StackElement *stack = malloc(sizeof(StackElement) * (heightsSize + 1));
    int stackTop = -1;
    for (int i = 0; i <= heightsSize; i++)
    {
        int currentHeight = (i == heightsSize) ? 0 : heights[i];
        while (stackTop >= 0 && stack[stackTop].height > currentHeight)
        {
            int poppedHeight = stack[stackTop].height;
            stackTop--;
            int width = (stackTop < 0) ? i : (i - stack[stackTop].index - 1);
            maxArea = MAX(maxArea, width * poppedHeight);
        }
        stackTop++;
        stack[stackTop].height = currentHeight;
        stack[stackTop].index = i;
    }
    free(stack);
    return maxArea;
}
int main()
{

    int heights[] = {2, 1, 5, 6, 2, 3};
    int heightsSize = sizeof(heights) / sizeof(heights[0]);
    int result = largestRectangleArea(heights, heightsSize);
    printf("The largest rectangle area is: %d\n", result);
    return 0;
}
