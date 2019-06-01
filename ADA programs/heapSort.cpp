#include <iostream>
#include <cmath>

using namespace std;

int iterationsHeap = 0, iterationsQuick = 0;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int start, int end)
{
    static int iterations = 0;
	int pivot = arr[end];
	int pindex = start;

	for(int i = start; i < end; i++)
	{
        iterationsQuick++;
		if(arr[i] <= pivot)
		{
			swap(arr[i], arr[pindex]);
			pindex++;
		}
	}

	swap(arr[pindex], arr[end]);
	return pindex;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    iterationsHeap++;

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int* arr, int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<"\tIndex "<<i<<": "<<arr[i];
    cout<<endl;
}


int main()
{
    int size;
    int arr1[10], arr2[10];

    cout<<"\n\tEnter size of array(max 10): ";
    cin>>size;

    cout<<"\n\tEnter elements of the array: ";
    for(int i=0; i<size; i++){
        cout<<"\tIndex "<<i<<": ";
        cin>>arr1[i];
        arr2[i] = arr1[i];
    }

    heapSort(arr1, size);
    quickSort(arr2, 0, size-1);

    cout<<"\n\tSorted Array by Heap Sort: \n"<<endl;
    printArray(arr1, size);
    cout<<"\n\tExpected iterations for heap sort: "<<roundf(size*log2(size));
	cout<<"\n\tActual iterations for heap sort: "<<iterationsHeap;
    cout<<"\n\tSorted Array by Quick Sort: \n"<<endl;
    printArray(arr2, size);
    cout<<"\n\tExpected iterations for heap sort: "<<roundf(size*size);
	cout<<"\n\tActual iterations for quick sort: "<<iterationsQuick;
    return 0;
}
