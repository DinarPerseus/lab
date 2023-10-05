//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, minIdx;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])minIdx = j;
        }
        swap(arr[i],arr[minIdx]);
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
    selectionSort(arr, n);
    end_time = clock(); 
    execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    //for(auto x: arr)cout<<x<<" ";
    cout << fixed << setprecision(5)<<"\nExecution Time: "<<execution_time<<" seconds\n";
    return 0;
}