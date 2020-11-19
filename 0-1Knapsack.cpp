#include<bits/stdc++.h>
using namespace std;
int max(int a, int b){
    return (a > b) ? a : b;
}

int knapSack(int W,int n,int *weight,int *value){
    int i, w;
    int K[n+1][W+1];

    for (i=0;i<=n;i++){
        for (w=0;w<=W;w++){
            if (i==0||w==0)
                K[i][w]=0;
            else if (weight[i-1]<=w)
                K[i][w]=max(value[i-1]+K[i-1][w-weight[i-1]],K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}

int main(){
    int value[] = { 3, 4, 5, 6 };
    int weight[] = { 2, 3, 4, 5 };
    int W=5;
    int n=sizeof(value)/sizeof(value[0]);
    cout<<knapSack(W,n,weight,value)<<endl;
}
