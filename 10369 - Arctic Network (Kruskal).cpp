#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef pair<int,int> ii;

vector<int> p;

int findSet(int i) {return (p[i]==i) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}
void unionSet(int i, int j){p[findSet(i)] = findSet(j);}

int main() {
	int t; cin>>t;
	while(t--){
		int s,op;
		cin>>s>>op;
		vector<ii> coor;
		int x,y, tempX1, tempY1, tempX2, tempY2;
		double weight;
		for(int i = 0; i < op ; i++){
			cin>>x>>y;
			coor.push_back(ii(x,y));
		}
		for(int i = 0 ; i < op ; i++) p.push_back(i);
		priority_queue<pair<double, ii>, vector<pair<double, ii>>, greater<pair<double, ii>> > pq;
		for(int i = 0 ; i < op ; i++){
			for(int j = i; j < op ; j++){
				if(i!=j){
					tempX1 = coor[i].first; tempY1 = coor[i].second;
					tempX2 = coor[j].first; tempY2 = coor[j].second;
					weight = sqrt((tempX1-tempX2)*(tempX1-tempX2) + (tempY1-tempY2)*(tempY1-tempY2));
					
					pq.push({weight,{i,j}});
				}
			}
		}
		
		vector<double> endie;
		while(!pq.empty()){
			pair<double,ii> front = pq.top(); pq.pop();
			if(!isSameSet(front.second.first, front.second.second)){
				endie.push_back(front.first);
				unionSet(front.second.first, front.second.second);
			}
		}
		
		sort(endie.begin(), endie.end());
		cout << setprecision(2) << fixed << endie[op-s-1] << endl;
		p.clear();
		endie.clear();
		coor.clear();
	}
	return 0;
}