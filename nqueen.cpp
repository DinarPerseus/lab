//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;

int size=4;
int x[100];
int cnt=0;


void write(){
    cnt++;
    cout<<"\n";
    cout<<cnt<<" way:\n";
    
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (j==x[i])
            {
                cout<<"1 ";
            }else
            {
                cout<<"0 ";
            } 
            
        }
        cout<<endl;
    }
    cout<<"\n\n";
}

bool Place(int k,int i){
	for(int j=1;j<=k-1;j++){
    	if(x[j]==i || abs(x[j]-i)==abs(j-k))
        	return false;
    }
    return true;	
}

void NQueens(int k,int n){
	for(int i=1;i<=n;i++){
    	if(Place(k,i)){
        	x[k]=i;
            if(k==n){
                write();
            }
            else NQueens(k+1,n);
        }
    }
}


int main(){
	NQueens(1,size);
return 0;
}