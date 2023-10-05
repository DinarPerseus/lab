//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;
// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    //srand((unsigned) time(NULL));
    for(int i=0; i<n; i++)arr[i]=rand()%(int)1e9;

    clock_t start_time, end_time;
    double execution_time;
    start_time = clock();  
    quickSort(arr, 0, n-1);
    end_time = clock(); 
    execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    // for(auto x: arr)cout<<x<<" ";
    cout << fixed << setprecision(5)<<"\nExecution Time: "<<execution_time<<" seconds\n";
    return 0;
}