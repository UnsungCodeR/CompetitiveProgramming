#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> fk;
int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int m; cin>>m;
        int x,y,w,s;
        vector<vector<pair<int,int>>> graph(n);
        vector<int>dist(n);
        int mm = m;
        while(mm--){
            cin>>x>>y>>w;
            graph[x-1].push_back(fk(w,y-1));
            graph[y-1].push_back(fk(w,x-1));
        }
        cin>>s;
        s--;
        
        for(int i = 0; i < n; i++){
            dist[i] = -1;
        }
        
        dist[s] = 0;
        priority_queue<fk, vector<fk>, greater<fk>> que;
        que.push(fk(0,s));
        while(!que.empty()){
            int top = que.top().second; que.pop();
            for(int i = 0 ; i <graph[top].size() ; i++){
                int weight = graph[top][i].first;
                int node = graph[top][i].second;
                    if(dist[node] == -1|| dist[top]+weight < dist[node]){
                        dist[node] = dist[top] + weight;
                        que.push(fk(dist[node],node));

                    }
                }
                
            }
        
        for(int j = 0 ; j < n ; j++){
            if(dist[j]!=0){
                if(dist[j] == -1) cout<<-1<<" ";
                else cout<<dist[j]<<" "; 
                }
             }   
        cout<<endl;        
        } 
    return 0;
}