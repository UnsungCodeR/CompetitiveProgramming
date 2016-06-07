#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
vector<int> p;
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {p[findSet(i)] = findSet(j);}
int main() {
	int c,s,q, counter = 0;
	while(cin>>c && cin>>s && cin>>q) {
		
		counter++;
		if(c==0 && s==0 && q==0 ) break;
		if(counter!=1) cout<<endl;
		priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii>> > pq;
		for (int i = 0; i < c; i++)	p.push_back(i);
		while(s--){
			int x,y,w;
			cin>>x>>y>>w;
			x--; y--;
			pq.push({w,{x,y}});
		}
	
		vector<vector<pair<int,int>>> graph(c);
		while(!pq.empty()){
	        pair<int,ii> front = pq.top(); pq.pop();
	        if(!isSameSet(front.second.first, front.second.second)){
	            graph[front.second.first].push_back(ii(front.first,front.second.second));
	            graph[front.second.second].push_back(ii(front.first,front.second.first));
	            unionSet(front.second.first, front.second.second);
	        }
		}
	    cout<<"Case "<<"#"<<counter<<endl;
	       	while(q--){
	       		int maxi = 0;
	       		bool status = false;
	       		vector<int>dist(c);
	       		for(int i = 0; i < c; i++) dist[i] = 1000000000;
	       		int src, end;
	       		cin>>src>>end;
	       		src--; end--;
	       		dist[src] = 0;
	       		queue<ii> que;
	        	que.push(ii(0,src));
	        	while(!que.empty() && !status ){
			        int top = que.front().second; que.pop();
			         for(int i = 0 ; i <graph[top].size() ; i++){
			             int weight = graph[top][i].first;
			             int node = graph[top][i].second;
			             if(dist[node]==1000000000){
			             	dist[node] =  max(dist[top], weight);
			              	maxi = max(maxi,weight);
			              	if(node == end) status= true;
			                	else que.push(ii(weight,node));
			          	}	
			              			
			      	}
	       		}
	       		if(dist[end]==1000000000) cout<<"no path"<<endl;
	       		else cout<<dist[end]<<endl;
	       		dist.clear();
    		}
    			p.clear();
		}
	return 0;
}