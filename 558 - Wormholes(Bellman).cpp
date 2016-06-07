#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> ii;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<vector<ii>> graph(n);
		vector<int> dist(n);
		while(m--){
			int x,y,w;
			cin>>x>>y>>w;
			graph[x].push_back(ii(y,w));
		}
		for(int i = 0 ; i < dist.size() ; i++){
			dist[i] = 999999999;
		}
		dist[0] = 0;
		for(int i = 0 ; i < n-1; i++){
			for(int u = 0 ; u < n ; u++){
				for(int j = 0 ; j < graph[u].size(); j++){
					ii v = graph[u][j];
					dist[v.first] = min(dist[v.first], dist[u] + v.second);
				}
			}
		}
		
		bool hasNC = false;
		for(int u = 0; u < n ; u++){
			for(int j = 0 ; j < graph[u].size(); j++){
				ii v = graph[u][j];
				if(dist[v.first] > dist[u] + v.second) hasNC = true;
			}
		}
		if(hasNC) cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;
	}
	return 0;
}