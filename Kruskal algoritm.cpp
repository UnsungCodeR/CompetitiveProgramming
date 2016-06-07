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
    cin >> n >> m;
    long long mst = 0;
    for (int i = 0; i < n; i++){
        p.push_back(i);
    }
    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>> > pq;
    int a, b, w;
    
    while(m--){
        cin >> a >> b >> w;
        pq.push({w,{a-1,b-1}});
        
    }
    
    
    while(!pq.empty()){
        pair<int,ii> front = pq.top(); pq.pop();
        if(!isSameSet(front.second.first, front.second.second)){
            mst+= front.first;
            unionSet(front.second.first, front.second.second);
        }
        
    }
    
    cout<<mst<<endl;
	return 0;
}
