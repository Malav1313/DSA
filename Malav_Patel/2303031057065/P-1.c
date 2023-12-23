#include <stdio.h>
#include <string.h>

    // Function to swap two digits in a string
    void swap(char *str, int i, int j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    // Function to find the smallest number greater than num with the same set of digits
    void findNextNumber(char *num) {
        int n = strlen(num);
        int i;
    // Find the rightmost digit that is smaller than the digit to its right
        for (i = n - 2; i >= 0; i--) {
            if (num[i] < num[i + 1]) {
            break;
        }
    }
    // If no such digit is found, then there is no next number
    if (i == -1) {

    printf("No greater number with the same set of digits.\n");
    return;
    
    }

    // Find the smallest digit on the right side of num[i] that is greater than num[i]

    int smallestGreater = i + 1;

    for (int j = i + 2; j < n; j++) {
        if (num[j] > num[i] && num[j] < num[smallestGreater]) {
        smallestGreater = j;
        }
    }

    // Swap the digits at positions i and smallestGreater

    swap(num, i, smallestGreater);

    // Sort the digits to the right of i in ascending order

    for (int j = i + 1; j < n - 1; j++) {
        for (int k = i + 1; k < n - 1; k++) {
            if (num[k] > num[k + 1]) {
                swap(num, k, k + 1);
            }
        }
    }

    printf("The next greater number with the same set of digits: %s\n", num);
}

int main() {
    char num[20];
    printf("Enter a number: ");
    scanf("%s", num);
    findNextNumber(num);
    return 0;
}
