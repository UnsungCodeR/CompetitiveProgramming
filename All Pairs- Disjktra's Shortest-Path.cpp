/*input
4 3 4
0 1 2
1 2 2
3 3 1
0 2
1 2
3 0
3 3
2 1 2
0 1 100
0 1
1 0
0 0 0
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

typedef pair<int, int> ii;

using namespace std;

int main() {
	int n, m, q, u, v, w;

	while (cin >> n >> m >> q) {
		if (n==0 && m==0 && q==0) break;

		vector<ii> graph[151];
		int distAns[151][151], dist[151];

		for(int i=0; i<m; i++) {
			cin >> u >> v >> w;
			graph[u].push_back({v, w});
		}
		memset(distAns, -1, sizeof distAns);

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) dist[j]=999999999;
			dist[i]=0;
			priority_queue<ii, vector<ii>, greater<ii> > pq;
			pq.push(ii(0, i));
			distAns[i][i]=0;
			while (!pq.empty()) {
				ii top = pq.top(); 
				pq.pop();
				int d = top.first, u = top.second;
				//cout << "VISITING " << u << endl;
				if (d == dist[u]) {
					for(int j=0; j<graph[u].size(); j++) {						
						int v=graph[u][j].first;
						int weight_u_v=graph[u][j].second;

						if (dist[u] + weight_u_v < dist[v]) {
							dist[v] = dist[u] + weight_u_v;
							distAns[i][v] = dist[v];
							//cout << "DIST[" << i << "][" << v << "] = " << dist[v] << endl;
							pq.push({dist[v], v});
						}
					}
				}
			}
		}
		while(q--) {
			cin >> u >> v;
			if (distAns[u][v]!=-1) cout << distAns[u][v] << '\n';
			else cout << "Impossible\n";
		}
		cout << "\n";
	}
	return 0;
}