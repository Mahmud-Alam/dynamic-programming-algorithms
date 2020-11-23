#include<bits/stdc++.h>
using namespace std;

int fib(int n, int *arr){
    if(n==0){
        arr[0] = 0;
        return arr[0];
    }
    if(n==1){
        arr[1] = 1;
        return arr[1];
    }
    if(arr[n]!=-1)
        return arr[n];
    else
        return arr[n] = fib(n-1, arr) + fib(n-2, arr);
}

int main(){
    int n, arr[100];
    cout<<"Input a number: ";cin>>n;

    for(int i=0;i<n;i++)
        arr[i] = -1;

    for(int i=0;i<n;i++)
        cout<<fib(i, arr)<<"\t";

    cout<<endl;
}
