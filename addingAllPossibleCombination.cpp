#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    if(n<1) return 0;
    if(n==1) return 1;
    else return solve(n-1) + solve(n-3) + solve(n-5);
}

int main(){
    int arr[] = {1,3,5};
    int n;
    cout<<"Input a number: ";cin>>n;
    int sum = solve(n);

    cout<<endl<<"All possible combination: "<<sum<<endl;
}
