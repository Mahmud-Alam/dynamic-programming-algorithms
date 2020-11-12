#include<bits/stdc++.h>
using namespace std;
bool sumOfSubset(int sum, int n, int *arr){
    bool subset[n+1][sum+1];
    for (int i=0; i<=n; i++)
        subset[i][0]=true;
    for (int i=1; i<=sum; i++)
        subset[0][i]=false;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=sum; j++){
            if(j<arr[i-1])
                subset[i][j]=subset[i-1][j];
            if(j>=arr[i-1])
                subset[i][j]=subset[i-1][j]||subset[i-1][j-arr[i-1]];
        }
    }
    return subset[n][sum];
}
int main(){
    int n, arr[100],sum;
    cout<<"Input array size: ";
    cin>>n;
    cout<<endl<<"Input set of integers: "<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<endl<<"Input Sum: ";
    cin>>sum;
    if (sumOfSubset(sum,n,arr))
        cout<<endl<<"Yes"<<endl;
    else cout<<endl<<"No"<<endl;
}
