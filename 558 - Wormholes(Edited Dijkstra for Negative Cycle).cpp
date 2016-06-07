#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
 
int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		bool status = false;
		int n,m;
		cin>>n>>m;
		vector<vector<ii>> graph(n);
		vector<int> dist(n);
		vector<int> queuetime(n,0);
		queue<int> q; q.push(0);
		vector<bool> in_queue(n,0);
		in_queue[0] = true;
		
		while(m--){
			int x,y,w;
			cin>>x>>y>>w;
			graph[x].push_back(ii(y,w));
		}
 
		for(int i = 0 ; i < dist.size() ; i++){
			dist[i] = 999999999;
		}
		dist[0] = 0;
		in_queue[0] = true;
		while(!q.empty() && !status ){
			int u = q.front(); q.pop(); in_queue[u] = false;
			for(int j = 0; j < graph[u].size() ; j++){
				int v = graph[u][j].first, weight_u_v = graph[u][j].second;
				if(dist[u] + weight_u_v < dist[v]){
					dist[v] = dist[u] + weight_u_v;
					if(!in_queue[v]){
						q.push(v);
						in_queue[v]=true;
						queuetime[v]++;
						if(queuetime[v] == v+2){
							status = true;
							break;
						}
					
					}
				}
			}
		}
		
		cout << (status?"possible":"not possible") << endl;
		
	}
	return 0;
}