#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
		int n, exit, time, link, x, y, w, counter = 0;
		cin>>n;
		cin>>exit;
		cin>>time;
		cin>>link;
		vector<vector<ii>> graph(n);
		vector<int>dist(n);
		while(link--){
			 cin>>x>>y>>w;
			 graph[y-1].push_back(ii(w, x-1));
		}
		
		for(int i = 0; i < n; i++){
            dist[i] = -1;
        }
		dist[exit-1] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> que;
        que.push(ii(0,exit-1));
		while(!que.empty()){
            int top = que.top().second; que.pop();
            for(int i = 0 ; i <graph[top].size() ; i++){
                int weight = graph[top][i].first;
                int node = graph[top][i].second;
                    if(dist[node] == -1|| dist[top]+weight < dist[node]){
                        dist[node] = dist[top] + weight;
                        que.push(ii(dist[node],node));

                    }
                }
                
            }
	
		for(int i = 0 ; i < n ; i++){
			if(dist[i] <= time && dist[i]!=-1) counter++;
		}
		
		cout<<counter<<endl;
		if(test!=0) cout<<endl;
		graph.clear();
		dist.clear();
		
	}
	return 0;
}