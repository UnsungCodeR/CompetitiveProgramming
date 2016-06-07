#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
int row, column;
bool isValid(int rT, int cT){
	if(rT>=0 && rT<row && cT>=0 && cT<column) return true;
	return false;
}

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
		int temp;
		cin>>row>>column;
		vector<vector<int>> graph(row);
		for(int i = 0 ; i < row; i++){
			for(int j = 0 ; j < column; j++){
				cin>>temp;
				graph[i].push_back(temp);
			}
		}
		
	vector<vector<int>> dist(row, vector<int>(column, -1));
	dist[0][0] = graph[0][0];
	priority_queue<iii, vector<iii>, greater<iii>> que;
	que.push(iii(graph[0][0],ii(0,0)));
	while(!que.empty()){
		int trow,tcol, weight;
		weight = que.top().first; trow = que.top().second.first; tcol = que.top().second.second; que.pop();
		if(isValid(trow,tcol-1) && (dist[trow][tcol-1]==-1 || weight+graph[trow][tcol-1] < dist[trow][tcol-1])){
			dist[trow][tcol-1]=  weight+graph[trow][tcol-1] ;
			que.push(iii(dist[trow][tcol-1],ii(trow,tcol-1)));
		}
		if(isValid(trow,tcol+1) && (dist[trow][tcol+1]==-1 ||  weight+graph[trow][tcol+1] < dist[trow][tcol+1])){
			dist[trow][tcol+1]=  weight+graph[trow][tcol+1] ;
			que.push(iii(dist[trow][tcol+1],ii(trow,tcol+1)));
		}
		if(isValid(trow-1,tcol) && (dist[trow-1][tcol]==-1 ||  weight+graph[trow-1][tcol] < dist[trow-1][tcol])){
			dist[trow-1][tcol]=  weight+graph[trow-1][tcol] ;
			que.push(iii(dist[trow-1][tcol],ii(trow-1,tcol)));
		}
		if(isValid(trow+1,tcol) && (dist[trow+1][tcol]==-1 ||  weight+graph[trow+1][tcol] < dist[trow+1][tcol])){
			dist[trow+1][tcol]=  weight+graph[trow+1][tcol] ;
			que.push(iii(dist[trow+1][tcol],ii(trow+1,tcol)));
		}
		
	}
		
		cout<<dist[row-1][column-1]<<endl;
	
	}
	return 0;
}