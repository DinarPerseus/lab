//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;
int n,m=100;
int w[100];
bool x[100];
void sumofsub(int s,int k,int r){
    x[k]=1;
    if (s+w[k]==m)
    {
        for (int i = 1; i <= k; i++)cout<<x[i]<<" ";cout<<"\n";
        
    }else if (s+w[k]+w[k+1]<=m)
    {
        sumofsub(s+w[k],k+1,r-w[k]);
    }
    if (s+r-w[k]>=m&&s+w[k+1]<=m)
    {
        x[k]=0;
        sumofsub(s,k+1,r-w[k]);

    }   
}
int main(){
    int r=0,s=0,k=1;
    cout<<"Enter the total number of elements :";
    cin>>n;
    for (int i = 1; i <= n; i++)w[i]=(rand()%50)+1;
    for (int i = 1; i <= n; i++)r+=w[i];
    clock_t start_time, end_time;
    double execution_time;
    start_time = clock();  
    sumofsub(s,k,r);
    end_time = clock(); 
    execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(6)<<"\nExe Time: "<<execution_time<<" s\n"; 
    return 0;
}
