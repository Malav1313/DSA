#include <stdio.h>
#include <string.h>
int main()
{
    // char str[10];
    char str1[100] = "aeibc";
    char str2[100] = "my nam";
    int i, n;
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' || str1[i] == 'A' || str1[i] == 'E' ||
            str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U')
        {
            count3++;
        }
        else
        {
            count++;
        }
    }
    printf("consonants is %d \n", count);
    printf("Vowels is %d \n", count3);
    printf("Malav Patel\n");
}