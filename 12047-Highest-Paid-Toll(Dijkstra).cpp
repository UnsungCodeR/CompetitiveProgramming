#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<long long, int> ii;
 
int main() {
	// your code goes here
	int test; cin>>test;
	while(test--){
		int n, m , s, t, p;
		int maxx = -1;
		cin>>n>>m>>s>>t>>p;
		vector<vector<ii>> graph(n);
		vector<vector<ii>> graph1(n);
		vector<long long> dist(n);
		vector<long long> dist1(n);
		while(m--){
			int x,y,w;
			cin>>x>>y>>w;
			graph[x-1].push_back(ii(w,y-1));
			graph1[y-1].push_back(ii(w,x-1));
		}
 
		for(int i = 0 ; i < dist.size(); i++){
			dist[i] = 1000000000000000;
			dist1[i] = 1000000000000000;
		}
		dist[s-1] = 0;
		dist1[t-1] = 0;
		priority_queue<ii, vector<ii>, greater<ii>>que;
		que.push(ii(0,s-1));
		while(!que.empty()){
			int top = que.top().second, d = que.top().first; que.pop();
			if(d != dist[top]) continue;
			for(int i = 0 ; i < graph[top].size(); i++){
					int weight = graph[top][i].first;
					int node = 	graph[top][i].second;
					if(dist[top] + weight < dist[node]){
							dist[node] = dist[top]+ weight;
							que.push(ii(dist[node], node));
						}
					}
			}
		que.push(ii(0,t-1));
		while(!que.empty()){
			int top1 = que.top().second, d1 = que.top().first; que.pop();
			if(d1 != dist1[top1]) continue;
			for(int i = 0 ; i < graph1[top1].size(); i++){
					int weight1 = graph1[top1][i].first;
					int node1 = 	graph1[top1][i].second;
					if(dist1[top1] + weight1 < dist1[node1]){
							dist1[node1] = dist1[top1]+ weight1;
							que.push(ii(dist1[node1], node1));
						}
					}
			}
			
		for(int i = 0 ; i < n; i++){
			for(int j  = 0 ; j < graph[i].size(); j++){
				int wt = graph[i][j].first;
				int nt = graph[i][j].second;
				
				if(dist[i] == -1 || dist1[nt] == -1) continue;
				if(dist[i]+(long long)wt+dist1[nt]<= (long long)p) maxx = max(maxx, wt);
			}
		}
 	cout<<maxx<<endl;
	}
	return 0;
}

FASTER VERSION
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<long long, int> ii;
 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	int test; 
	cin>>test;
	while(test--){
		int n, m , s, t, p;
		int maxx = -1;
		cin>>n>>m>>s>>t>>p;
		vector<vector<ii>> graph(n);
		vector<vector<ii>> graph1(n);
		vector<long long> dist(n);
		vector<long long> dist1(n);
		while(m--){
			int x,y,w;
			cin>>x>>y>>w;
			graph[x-1].push_back(ii(w,y-1));
			graph1[y-1].push_back(ii(w,x-1));
		}
 
		for(int i = 0 ; i < dist.size(); i++){
			dist[i] = 1000000000000000;
			dist1[i] = 1000000000000000;
		}
		dist[s-1] = 0;
		dist1[t-1] = 0;
		priority_queue<ii, vector<ii>, greater<ii>>que;
		que.push(ii(0,s-1));
		while(!que.empty()){
			int top = que.top().second, d = que.top().first; que.pop();
			if(d != dist[top]) continue;
			for(int i = 0 ; i < graph[top].size(); i++){
					int weight = graph[top][i].first;
					int node = 	graph[top][i].second;
					if(dist[top] + weight < dist[node]){
							dist[node] = dist[top]+ weight;
							que.push(ii(dist[node], node));
						}
					}
			}
		que.push(ii(0,t-1));
		while(!que.empty()){
			int top1 = que.top().second, d1 = que.top().first; que.pop();
			if(d1 != dist1[top1]) continue;
			for(int i = 0 ; i < graph1[top1].size(); i++){
					int weight1 = graph1[top1][i].first;
					int node1 = 	graph1[top1][i].second;
					if(dist1[top1] + weight1 < dist1[node1]){
							dist1[node1] = dist1[top1]+ weight1;
							que.push(ii(dist1[node1], node1));
						}
					}
			}
			
		for(int i = 0 ; i < n; i++){
			for(int j  = 0 ; j < graph[i].size(); j++){
				int wt = graph[i][j].first;
				int nt = graph[i][j].second;
				
				if(dist[i]+(long long)wt+dist1[nt]<= (long long)p) maxx = max(maxx, wt);
			}
		}
 	cout<<maxx<<endl;
	}
	return 0;
}