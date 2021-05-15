#pragma once

#include <bits/stdc++.h>
#define RANGE 255

// O(logN) running time
template <typename T>
int binarySearch(std::vector<T> &arr, int n, int x)
{
    int p = 1;
    int r = n;

    while (p <= r)
    {
        int q = (p + r) / 2;
        if (arr[q] == x)
        {
            return q;
        }
        else if (arr[q] > x)
        {
            r = q - 1;
        }
        else
        {
            p = q + 1;
        }
    }
    return -1;
}

// O(logN) running time
template <typename T>
int binarySearchRecursive(std::vector<T> &arr, int p, int r, int x)
{
    if (p > r)
    {
        return -1;
    }
    else
    {
        int q = (p + r) / 2;
        if (arr[q] == x)
        {
            return q;
        }
        else if (arr[q] > x)
        {
            return binarySearchRecursive(arr, p, q - 1, x);
        }
        else
        {
            return binarySearchRecursive(arr, q + 1, r, x);
        }
    }
}

// O(n) but in some cases O(n^2)
template <typename T>
void insertionSort(std::vector<T> &arr)
{
    for (int i = 1; i < int(arr.size()); i++)
    {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void merge(std::vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
//O(n lg n)
void mergeSort(std::vector<int> &arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
// T(n) = T(k) + T(n-k-1) + \theta(n)
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//O(n + k)
void countSort(char arr[])
{
    char output[strlen(arr)];
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
