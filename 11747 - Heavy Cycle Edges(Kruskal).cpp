#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> ii;
vector<int> p;
vector<long long> store;
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {p[findSet(i)] = findSet(j); }

int main() {
	int n,m;
	while(cin>>n && cin>>m){
		if(n==0 && m==0) break;
		bool status = false;
		priority_queue<pair<long long, ii>, vector<pair<long long, ii>>, greater<pair<long long, ii>> > pq;
		while(m--){
			int x,y,w;
			cin>>x>>y>>w;
			pq.push({w,{x,y}});
		}
		
		for(int i = 0 ; i < n ; i++){
			p.push_back(i);
			
		}
		
		while(!pq.empty()){
			pair<long long,ii> front = pq.top(); pq.pop();
	        if(!isSameSet(front.second.first, front.second.second)){
	            unionSet(front.second.first, front.second.second);
	        }
	        else{
	        	long long weight = front.first;
	        	store.push_back(weight);
	        	
	        }
	        
		}
	    sort(store.begin(), store.end());
	    if(store.size() == 0 ) cout<<"forest";
	    else{
	    	cout<<store[0];
	    	for(int i = 1 ; i < store.size() ; i++){
	    		cout<<" "<<store[i];
	    	}
	    }
	    cout<<endl;
	    p.clear();
	    store.clear();
	}
	return 0;
}