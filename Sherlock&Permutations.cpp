#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int mod = 1000000007, comb[2001][2001];


int main() {
   for (int i = 0; i <= 2000; i++)
      {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                  comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
                  if (comb[i][j] >= mod) comb[i][j] -= mod;
            }
      }
    
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m; m--;
        cout<<comb[n+m][n]<<endl;
    }
    return 0;
}