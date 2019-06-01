#include <iostream>
#include <cmath>

using namespace std;

void sort(int* arr, int size)
{
	int temp;
	for(int i = 0; i < size-1; i++)
	{
		for(int j = 0; j < size-i-1; j++)
		{

			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int linearSearch(int* arr, int size, int element)
{
	int flag = 0, iterations = 0;
	cout<<"\n\t*****Linear Search*****";
	for(int i = 0; i < size; i++)
	{
		iterations++;
		if(arr[i] == element)
		{
			cout<<"\n\tElement found at position: "<<i+1;
			cout<<"\n\tExpected iterations for linear search: "<<size;
			cout<<"\n\tActual iterations for linear search: "<<iterations;
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		cout<<"\n\tElement not found";
	}

}

int binarySearch(int* arr, int size, int element)
{
	cout<<"\n\t*****Binary Search*****";
	sort(arr, size);
	int first = 0, last = size-1, middle, flag = 0, iterations = 0;
	middle = (first + last) / 2;
	while(first <= last)
	{
		iterations++;
		if(arr[middle] < element)
		{
			first = middle + 1;
		}
		else if(arr[middle] == element)
		{
			cout<<"\n\tElement found at position: "<<middle+1;
			cout<<"\n\tExpected iterations for binary search: "<<roundf(log2(size));
			cout<<"\n\tActual iterations for binary search: "<<iterations;
			flag = 1;
			break;
		}
		else
		{
			last = middle - 1;
		}
		middle = (first + last) / 2;
	}
	if(flag == 0)
	{
		cout<<"\n\tElement not found";
	}
}

int main()
{
	int size, element;
    int arr[10];

    cout<<"\n\tEnter size of array(max 10): ";
    cin>>size;

    cout<<"\n\tEnter elements of the array: ";
    for(int i=0; i<size; i++){
        cout<<"\tIndex "<<i<<": ";
        cin>>arr[i];
    }

	cout<<"\n\tEnter element to be searched: ";
	cin>>element;

	linearSearch(arr, size, element);
	binarySearch(arr, size, element);
	cout<<endl;
}
