#include <stdio.h>
#include <string.h>

void reversestr(char *arr, int start, int end) {
    if (start >= end) return;
    char temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reversestr(arr, start + 1, end - 1);
}

int main(void) {
    char arr[50];
    printf("Enter a string: ");
    fgets(arr, sizeof(arr), stdin);
    int size= strlen(arr)-1;
    reversestr(arr, 0, size);
    printf("Reversed string: %s\n", arr);

    return 0;
}
