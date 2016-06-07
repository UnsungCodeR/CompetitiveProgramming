#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
vector<int>p;

int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {p[findSet(i)] = findSet(j);}

int main() {
	int t; cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>> > temp, pq , hold;
		for(int i = 0 ; i < m ; i++){
			int x,y,w;
			cin>>x>>y>>w;
			x--;y--;
			temp.push({w,{x,y}});
		}
		int mst = 0, mst2 = 100000000;
		for(int i = 0 ; i < n ; i++) p.push_back(i);
		vector<iii>store;
		
		while(!temp.empty()){
	        pair<long long,ii> front = temp.top(); temp.pop();
	        if(!isSameSet(front.second.first, front.second.second)){
	            mst+= front.first;
	            unionSet(front.second.first, front.second.second);
	            store.push_back(iii(front.first,ii(front.second.first, front.second.second)));
	        }
	        else pq.push({front.first,{front.second.first, front.second.second}});
    	}
    	
    	hold = pq;
    	int flag = 0;
		for(int i = 0 ; i < n ; i++){
			
			int mstTemp = 0;
			p.clear();
			for(int k = 0 ; k < n ; k++) p.push_back(k);
			pq = hold;
			
			for(int j = 0 ; j < store.size() ; j++){
				if(j!=flag){
					pq.push({store[j].first,{store[j].second.first, store[j].second.second}});
				}
				else pq.push({1000000000,{store[j].second.first, store[j].second.second}});
			}
			while(!pq.empty()){
				pair<long long,ii> front = pq.top(); pq.pop();
				if(!isSameSet(front.second.first, front.second.second)){
	            mstTemp+= front.first;
	            unionSet(front.second.first, front.second.second);
	        	}
			}
			mst2 = min(mst2, mstTemp);
			if(flag == store.size()-1) flag = 0;
			else flag++;
		}
		
		cout<<mst<<" "<<mst2<<endl;
		p.clear();
		store.clear();
		
	}
	
	return 0;
}