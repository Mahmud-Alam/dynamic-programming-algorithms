#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, int *dp){
    if(n==0) return dp[0]=0;
    else if(n==1) return dp[1]=1;
    else{
        if(dp[n]!=-1) return dp[n];
        else return dp[n] = fibonacci(n-1,dp)+fibonacci(n-2,dp);
    }
}

int main(){
    int n, dp[100];
    cout<<"Input number: ";cin>>n;
    for(int i=0;i<n;i++)
        dp[i]=-1;
    for(int i=0;i<n;i++)
        cout<<fibonacci(i,dp)<<"\t";
    cout<<endl;
}
