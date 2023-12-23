#include <stdio.h>
#include <stdlib.h>
struct interval
{
    int start;
    int end;
};
int CompareIntervals(const void *a, const void *b)
{
    return ((struct interval *)a)->start - ((struct interval *)b)->start;
}
void mergeIntervals(struct interval intervals[], int n)
{
    if (n <= 0)
        return;
    qsort(intervals, n, sizeof(struct interval), CompareIntervals);
    int resultIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (intervals[resultIndex].end >= intervals[i].start)
        {
            intervals[resultIndex].end = intervals[i].end > intervals[resultIndex].end ? intervals[i].end : intervals[resultIndex].end;
        }
        else
        {

            resultIndex++;
            intervals[resultIndex] = intervals[i];
        }
    }
    printf("merged intervals :\n");
    for (int i = 0; i <= resultIndex; i++)
    {
        printf("[ %d,%d]", intervals[i].start, intervals[i].end);
    }
    printf("\n");
}
int main()
{
    struct interval intervals[] = {{1, 3}, {2, 16}, {9, 3}, {15, 19}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    mergeIntervals(intervals, n);
    return 0;
}
