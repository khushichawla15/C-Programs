#include <stdio.h>

int binarySearch(int arr[], int n, int item) 
{
    int low = 0, high = n - 1, mid;

    while (low <= high) 
	{
        mid = (low + high) / 2;

        if (arr[mid] == item)
            return mid;
        else if (arr[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, i, item, arr[100], result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &item);

    result = binarySearch(arr, n, item);

    if (result != -1)
        printf("Element found at position %d\n", result + 1);
    else
        printf("Element not found\n");

    return 0;
}
