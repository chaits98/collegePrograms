#include <iostream>
#include <cmath>

using namespace std;

int iterationsMerge = 0;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int* arr, int size)
{
    int i, j, min_idx, iterations = 0;
//dkjhlqdbcc.jkqd
    for (i = 0; i < size-1; i++)
    {
        iterations++;
        min_idx = i;
        for (j = i+1; j < size; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
    cout<<"\n\tExpected iterations for selection sort: "<<roundf(size*size);
	cout<<"\n\tActual iterations for selection sort: "<<iterations;
}

void insertionSort(int* arr, int size)
{
   int i, key, j, iterations = 0;
   for (i = 1; i < size; i++)
   {
       iterations++;
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
    cout<<"\n\tExpected iterations for insertion sort: "<<roundf(size*size);
	cout<<"\n\tActual iterations for insertion sort: "<<iterations;
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) 
    {
        iterationsMerge++;
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
        iterationsMerge++;
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    {
        iterationsMerge++;
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 


void printArray(int* arr, int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<"\tIndex "<<i<<": "<<arr[i];
    cout<<endl;
}

int main(){
    int size;
    int arr1[10], arr2[10], arr3[10];

    cout<<"\n\tEnter size of array(max 10): ";
    cin>>size;

    cout<<"\n\tEnter elements of the array: ";
    for(int i=0; i<size; i++){
        cout<<"\tIndex "<<i<<": ";
        cin>>arr1[i];
        arr2[i] = arr3[i] = arr1[i];
    }

    cout<<"\n\tSorted Array by Insertion Sort: \n"<<endl;
    insertionSort(arr1, size);
    cout<<endl;
    printArray(arr1, size);
    cout<<"\n\tSorted Array by Selection Sort: \n"<<endl;
    selectionSort(arr2, size);
    cout<<endl;
    printArray(arr2, size);
    cout<<"\n\tSorted Array by Merge Sort: \n"<<endl;
    mergeSort(arr3, 0, size-1);
    cout<<"\n\tExpected iterations for merge sort: "<<roundf(size*log2(size));
	cout<<"\n\tActual iterations for merge sort: "<<iterationsMerge<<endl;
    printArray(arr3, size);
    return 0;
}
