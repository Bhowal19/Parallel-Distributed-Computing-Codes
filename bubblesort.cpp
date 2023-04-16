#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int BubbleSort(int arr[], int n)
{
    int nr = 0, changes = 1, tmp;
    while (changes)
    {
#pragma omp parallel private(tmp)
        {
            nr++;
            changes = 0;
#pragma omp for reduction(+ \: changes)
            for (int i = 0; i < n - 1; i += 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    tmp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = tmp;
                    ++changes;
                }
            }
#pragma omp for reduction(+ \: changes)
            for (int i = 1; i < n - 1; i += 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    tmp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = tmp;
                    ++changes;
                }
            }
        }
    }
}
int main()
{
    int n, arr[10], i;
    double start, end;
    printf("\n**********************BUBBLE SORT ||**********************");
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    start = omp_get_wtime();
    BubbleSort(arr, n);
    end = omp_get_wtime();
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("time:%f", end - start);
    return 0;
}
