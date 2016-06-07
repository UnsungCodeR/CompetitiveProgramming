#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
vector<int> p;
typedef pair<int, int> ii;
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {p[findSet(i)] = findSet(j);}

int main(){
	int n, m;
	
    while(cin>>n && cin>>m){
    	if(n==0) break;
    long long mst = 0;
    long long Tweight=0;
    for (int i = 0; i < n; i++){
        p.push_back(i);
    }
    priority_queue<pair<long long, ii>, vector<pair<long long, ii>>, greater<pair<long long, ii>> > pq;
    int a, b;
    long long w;
    
    while(m--){
        cin >> a >> b >> w;
        Tweight += w;
        pq.push({w,{a,b}});
        
    }
    
    
    while(!pq.empty()){
        pair<long long,ii> front = pq.top(); pq.pop();
        if(!isSameSet(front.second.first, front.second.second)){
            mst+= front.first;
            unionSet(front.second.first, front.second.second);
        }
        
    }
    
    cout<<Tweight-mst<<endl;
    p.clear();
	
    }
    return 0;
}
