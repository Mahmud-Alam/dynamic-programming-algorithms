#include<bits/stdc++.h>
using namespace std;

bool isSubset(int sum, int n, int *arr){

    bool subset[n+1][sum+1];

    for(int i=0;i<=n;i++){
        subset[i][0] = true;
    }
    for(int i=1;i<=sum;i++){
        subset[0][i] = false;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<arr[i-1]){
                subset[i][j] = subset[i-1][j];
            }
            if(j>=arr[i-1]){
                subset[i][j] = subset[i-1][j]||subset[i-1][j-arr[i-1]];
            }
        }
    }

    cout<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout<<subset[i][j]<<"\t";
        }
        cout<<endl;
    }

    return subset[n][sum];
}

int main(){
    int arr[] = {3,4,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum;
    cout<<"Input a Sum value: ";cin>>sum;
    bool value = isSubset(sum,n,arr);
    if(value)
        cout<<endl<<"Sum of Subset is found!"<<endl;
    else
        cout<<endl<<"Not found!"<<endl;
}
