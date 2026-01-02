#include <stdio.h>

int linearSearch(int arr[], int n, int item) 
{
    int i;
    for (i = 0; i < n; i++) 
	{
        if (arr[i] == item)
            return i;
    }
    return -1;
}

int main() 
{
    int n, i, item, arr[100], result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &item);

    result= linearSearch(arr, n, item);

    if (result != -1)
        printf("Element found at position %d\n", result + 1);
    else
        printf("Element not found\n");

    return 0;
}
