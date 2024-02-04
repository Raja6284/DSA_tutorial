#include <iostream>
using namespace std;

// This code is being written for 0 based indexing of array
// Heap sort calling max_heapify will sort the array increasing order
// Heap sort calling min_heapify will sort the array in decreasing order

void max_heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        max_heapify(arr, n, largest);
    }
}

void min_heapify(int arr[], int n, int i)
{

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }

    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        min_heapify(arr, n, smallest);
    }
}

void build_heap(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        min_heapify(arr, n, i); // max_heapify(arr,n,i); for max_heap sorting
    }

    cout << "heap has been built in this way" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heap_sort(int arr[], int n)
{

    // first build heap
    build_heap(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);   // swap root node with last node
        min_heapify(arr, i, 0); // bring the root node to its correct position by calling heapify
    }                           // max_heapify(arr,i,0); ,for max_heap sorting
}

void print_array(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // ascending , no. of comparison = c1;
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // descending ,no. of comparison = c2;
    int arr3[] = {1, 9, 2, 8, 3, 7, 4, 6, 5, 10}; // random, no. of comparison = c3;

    // (c1 < c3 < c2) is always true

    int n = 10; // sizeof(arr)/sizeof(arr[0]);

    cout << "Original array is" << endl;
    print_array(arr3, n);

    heap_sort(arr3, n);

    cout << "Sorted array is " << endl;
    print_array(arr3, n);

    return 0;
}