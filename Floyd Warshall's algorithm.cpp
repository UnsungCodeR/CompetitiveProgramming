#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int main() {
  
        int n; cin>>n;
        int m; cin>>m;
        int x,y,w,s;
      
        vector<int>dist(n);
        int AdjMatrix[401][401];
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < n ;j++){
                AdjMatrix[i][j] = 99999;
                if(i==j) AdjMatrix[i][j]=0;
            }
        }
        int mm = m;
        while(mm--){
            cin>>x>>y>>w;
            x--;
            y--;
            AdjMatrix[x][y] = w;          
        }
        REP (k, 0, n ) 
            REP (i, 0, n )
                REP (j, 0, n)
                    AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);
    
        
        cin>>s;
        while(s--){
            int startnode, endnode;
            cin>>startnode>>endnode;
            
            if(AdjMatrix[startnode-1][endnode-1]==99999) cout<<-1<<endl;
            else cout<<AdjMatrix[startnode-1][endnode-1]<<endl;
                           
        }
    
    return 0;
}