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


    //print the table
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }


    //store the charecters
    // Following code is used to print LCS
   int index = dp[n][m];

   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character

   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = n, j = m;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (x[i-1] == y[j-1])
      {
          lcs[index-1] = x[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }

      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (dp[i-1][j] > dp[i][j-1])
         i--;
      else
         j--;
   }

   cout<<endl<<"The LCS is: "<<lcs<<endl;


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

