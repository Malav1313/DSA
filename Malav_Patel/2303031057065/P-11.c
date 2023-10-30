#include <stdio.h>
#include <string.h>
void main()
{
    char str1[100] = "Malav Patel\n";
    char str2[100] = "2303031057065\n";
    char str[100];
    strcat(str1, str2);
    printf("%s", str1);
}
