#include<bits/stdc++.h>
using namespace std;

int LCS(int n, int m, char *x, char *y){
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int i=1;i<=m;i++)
        dp[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            if(x[i-1]!=y[j-1]){
                if(dp[i-1][j]>dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }

    return dp[n][m];
}

int main(){
    char x[] = {'A','B','C','B','D','A','B'};
    char y[] = {'B','D','C','A','B','A'};

    int n = sizeof(x)/sizeof(x[0]);
    int m = sizeof(y)/sizeof(y[0]);

    int lcs = LCS(n,m,x,y);
    cout<<endl<<"Largest Common Subsequence: "<<lcs<<endl;
}
