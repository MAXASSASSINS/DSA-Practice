#include <iostream>

using namespace std;

int partition(int arr[], int st, int en)
{
    int pivot = arr[st];
    int count = 0;
    for (int i = st + 1; i <= en; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = st + count;
    swap(arr[pivotIndex], arr[st]);

    int i = st;
    int j = en;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] > arr[pivotIndex])
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int st, int en)
{
    if (st >= en)
    {
        return;
    }

    int pivotIndex = partition(arr, st, en);

    quickSort(arr, st, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, en);
}

int main()
{
    int arr[5] = {2, 6, 4, 7, 3};
    int n = 5;

    quickSort(arr, 0, n - 1);

    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i] << " ";
    }
    cout<<endl;
    
    return 0;
}