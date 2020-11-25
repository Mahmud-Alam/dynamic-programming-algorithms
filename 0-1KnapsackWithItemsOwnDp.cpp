#include<bits/stdc++.h>
using namespace std;

int knapsack(int w, int n, int *wt, int *val){
    int p[n+1][w+1];
    //int sack[n];

    for(int i=0;i<=n;i++)
        p[i][0] = 0;
    for(int i=0;i<=w;i++)
        p[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(j<wt[i-1]){
                p[i][j] = p[i-1][j];
            }
            if(j>=wt[i-1]){
                if(p[i-1][j]> val[i-1] + p[i-1][j-wt[i-1]])
                    p[i][j] = p[i-1][j];
                else p[i][j] = val[i-1] + p[i-1][j-wt[i-1]];
            }
        }
    }

     cout<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            cout<<p[i][j]<<"\t";
        }
        cout<<endl;
    }

    return p[n][w];
}
int main(){
    int w, wt[] = {2,1,3,2}, val[] = {12,10,20,15};
    int n = sizeof(wt)/sizeof(wt[0]);
    cout<<"Input a knapsack weight: ";cin>>w;

    int total = knapsack(w,n,wt,val);

    cout<<endl<<"All possible value: "<<total<<endl;
}
