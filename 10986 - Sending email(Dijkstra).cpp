#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int counter = 1;
	int t; cin>>t;
	while(t--){
		int n,m,startN,endN;
		cin>>n>>m>>startN>>endN;
		vector<vector<ii>> graph(n);
		vector<int> dist(n);
		while(m--){
			int x,y,w;
			cin>>x>>y>>w;
			graph[x].push_back(ii(w,y));
			graph[y].push_back(ii(w,x));
		}
		for(int i = 0 ; i < dist.size(); i++){
			dist[i] = -1;
		}
		dist[startN] = 0;
		priority_queue<ii,vector<ii>, greater<ii>> que;
		que.push(ii(0, startN));
		while(!que.empty()){
			int top = que.top().second; que.pop();
			for(int i = 0 ; i < graph[top].size(); i++){
				int weight = graph[top][i].first;
				int node = graph[top][i].second;
				if(dist[node] == -1 || dist[top]+weight < dist[node]){
					dist[node] = dist[top] + weight;
					que.push(ii(dist[node], node));
				}
			}
		}
		if(dist[endN]!= -1) cout<<"Case #"<<counter<<":"<<" "<<dist[endN]<<endl;
		else  cout<<"Case #"<<counter<<":"<<" unreachable"<<endl;
		counter++;
		
	}
	return 0;
}