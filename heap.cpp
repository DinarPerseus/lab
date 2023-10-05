#include <bits\stdc++.h>
using namespace std;


void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < n && arr[l] > arr[largest])largest = l;
	if (r < n && arr[r] > arr[largest])largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
    int n;cout<<"Enter the size of array:";cin>>n;
    srand((unsigned) time(NULL));
	int a[n];
    for(int i=0; i<n; i++)a[i]=rand()%(int)1e9;
    clock_t start_time, end_time;
    double execution_time;
    start_time = clock(); 
	heapSort(a, n);
    end_time = clock(); 
    execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    //for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout << fixed << setprecision(6)<<"\nExe Time: "<<execution_time<<" seconds\n";

return 0;
}
