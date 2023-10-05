#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,r;
    cout<<"enter total number of elements:";
    cin>>n;
    cout<<"enter bag capacity:";
    cin>>r;
    int dp[n+1][r+1];

    int c[n],v[n];
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=r;j++){
            if(i==0||j==0)dp[i][j]=0;
            else if (c[i-1]<=j)
            {
                dp[i][j]=max(v[i-1]+dp[i-1][j-c[i-1]],dp[i-1][j]);
            }else
            {
                dp[i][j]=dp[i-1][j];
            } 
        }
    }
    cout<<dp[n][r];
    return 0;
}

