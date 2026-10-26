#include <stdlib.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr, long n)
{
    long i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertion_sort(int *arr, long n)
{
    long i, j;
    int key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selection_sort(int *arr, long n)
{
    long i, j, min_index;

    for (i = 0; i < n - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            swap(&arr[i], &arr[min_index]);
        }
    }
}

long partition(int *arr, long low, long high)
{
    int pivot = arr[high];
    long i = low - 1;
    long j;

    for (j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort_recursive(int *arr, long low, long high)
{
    if (low < high)
    {
        long p = partition(arr, low, high);

        quick_sort_recursive(arr, low, p - 1);
        quick_sort_recursive(arr, p + 1, high);
    }
}

void quick_sort(int *arr, long n)
{
    if (n > 1)
        quick_sort_recursive(arr, 0, n - 1);
}

void merge(int *arr, int *temp, long left, long mid, long right)
{
    long i = left;
    long j = mid + 1;
    long k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (k = left; k <= right; k++)
        arr[k] = temp[k];
}

void merge_sort_recursive(int *arr, int *temp, long left, long right)
{
    if (left < right)
    {
        long mid = left + (right - left) / 2;

        merge_sort_recursive(arr, temp, left, mid);
        merge_sort_recursive(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void merge_sort(int *arr, long n)
{
    int *temp;

    if (n <= 1)
        return;

    temp = malloc(sizeof(int) * n);
    if (temp == NULL)
        return;

    merge_sort_recursive(arr, temp, 0, n - 1);
    free(temp);
}

void heapify(int *arr, long n, long i)
{
    long largest = i;
    long left = 2 * i + 1;
    long right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, long n)
{
    long i;

    if (n <= 1)
        return;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
