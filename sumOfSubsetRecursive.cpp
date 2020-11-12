#include<bits/stdc++.h>
using namespace std;
bool sumOfSubset(int sum, int n, int *arr){
    if (sum == 0)return true;
    if (n == 0)return false;
    if (arr[n-1]>sum) return sumOfSubset(sum,n-1,arr);
    return sumOfSubset(sum,n-1,arr)||sumOfSubset(sum-arr[n-1],n-1,arr);
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
