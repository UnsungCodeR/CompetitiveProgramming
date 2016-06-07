#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> ii;
vector<int> p;
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {p[findSet(i)] = findSet(j);}
int main() {
	int t, display = 1;
	cin>>t;
	while(t--){
		int city;
		double dist;
		double road = 0.0 ;
		double railroad = 0.0;
		cin>>city>>dist;
		int noCity= city;
		vector<int>x(city);
		vector<int>y(city);
		vector<vector<double>>a;
		a.assign(city, vector<double>(city));
		for(int i = 0 ; i < city; i++){
			cin>>x[i]>>y[i];
			a[i][i] = 0.0;
			for(int j = 0 ; j < i ; j++){
				double c = x[i]-x[j];
			    double b = y[i]-y[j];
				a[i][j] = a[j][i] = sqrt(c*c + b*b);
			}
		}
		for (int i = 0; i < city; i++){
    	 	p.push_back(i);
	 	}
	 	priority_queue<pair<double, ii>, vector<pair<double, ii>>, greater<pair<double, ii>> > pq;
	 	for(int i = 0 ; i < city; i ++){
	 		for(int j = 0 ; j < i ; j++){
	 			if(i!= j){
	 				pq.push({a[i][j],{i,j}});
	 			}
	 		}
	 	}
	 	while(!pq.empty()){
        pair<double,ii> front = pq.top(); pq.pop();
        if(!isSameSet(front.second.first, front.second.second)){
            
            if(front.first<=dist){
            	road+=front.first;
            	noCity--;
            }
            else railroad+=front.first;
            unionSet(front.second.first, front.second.second);
    		}
        
    	}
    
	 	cout<<"Case"<<" "<<"#"<<display<<":"<<" "<<noCity<<" "<<round(road)<<" "<<round(railroad)<<endl;
	 	display++;
	 	p.clear();
	}
	return 0;
}