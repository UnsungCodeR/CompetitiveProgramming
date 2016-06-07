#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int main(){
	int n, m;
    cin >> n >> m;
    vector<vector<ii> > graph(n, vector<ii> () );
    vector<bool> visited(n, false);
    
    int a, b, w;
    while(m--){
        cin >> a >> b >> w;
        graph[a-1].push_back(ii(b-1, w));
        graph[b-1].push_back(ii(a-1, w));
    }
    
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    long long mst = 0;
    pq.push(ii(0, 0));
    while(!pq.empty()){
        int u = pq.top().second, w = pq.top().first; pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        mst += w;
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first;
            if(!visited[v]){
                pq.push(ii(graph[u][i].second, v));
            }
        }
    }

    cout << mst << endl;

	return 0;
}