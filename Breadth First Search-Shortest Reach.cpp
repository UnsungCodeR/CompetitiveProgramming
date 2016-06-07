Breath First Search C++ coding

*input*
1
4 2
1 2
1 3
1
*end-input*

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 
 
int main() {
    int t,m,n,x,y,s;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> vec(n);
        vector<int> dist(n);
        int mm = m;
        while(mm--){
            cin>>x>>y;
            vec[x-1].push_back(y-1);
            vec[y-1].push_back(x-1);
 
        }
        cin>>s;
        s--;
           for(int p = 0 ; p < n; p++)
            {
            dist[p] = -1;
        }
        dist[s] = 0;
        queue<int> que;
        que.push(s);
        while(!que.empty()){
            int top = que.front(); 
            que.pop();
            for(int i= 0 ; i < vec[top].size(); i++ )
                {
                     int n = vec[top][i];
                     if(dist[n] == -1){
                         dist[n] = dist[top] + 1;
                         que.push(n);
                }
            }
 
         }
 
        for(int j = 0 ; j < n ; j++)
            {
            if(dist[j]!=0)
                {
                    if(dist[j] == -1) cout<<-1<<" ";
                    else cout<<dist[j] * 6<<" ";
                   
            }
        }
    cout<<endl;
 
    }
 
    return 0;
}