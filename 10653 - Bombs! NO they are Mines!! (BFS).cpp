#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 10000000
int row,column;

bool isValid(int rT, int cT){
	if(rT>=0 && rT<row && cT>=0 && cT<column) return true;
	return false;
}

int main() {
	// your code goes here
	int rowCount, temprow, tempcol, mineNum, sRow, sCol, dRow, dCol;
	while(scanf ("%d %d", &row, &column)){
		  if ( row == 0 && column == 0 ) break;
			
			vector<vector<int>> graph;
			graph.assign(row, vector<int>(column, -1));
			
			scanf ("%d", &rowCount);
			for(int i = 0 ; i < rowCount ; i++){
				  scanf ("%d", &temprow);
				  scanf ("%d", &mineNum);
				  for(int j = 0 ; j < mineNum; j++){
				  	  scanf ("%d", &tempcol);
				  	graph[temprow][tempcol] = INF;
				  }
			}
			cin>>sRow>>sCol>>dRow>>dCol;
			graph[sRow][sCol] = 0;
			queue<int> ro;
			queue<int> co;
			ro.push(sRow); co.push(sCol);
			while(!ro.empty() && !co.empty()){
				int r, c;
				r = ro.front(); ro.pop();
				c = co.front(); co.pop();
				
				if(isValid(r-1,c) && graph[r-1][c]<0){
					graph[r-1][c] = graph[r][c]+1;
					ro.push(r-1); co.push(c); 
				}
				if(isValid(r+1,c) && graph[r+1][c]<0){
					graph[r+1][c] = graph[r][c]+1;
					ro.push(r+1); co.push(c); 
				}
				if(isValid(r,c-1) && graph[r][c-1]<0){
					graph[r][c-1] = graph[r][c]+1;
					ro.push(r); co.push(c-1); 
				}
				if(isValid(r,c+1) && graph[r][c+1]<0){
					graph[r][c+1] = graph[r][c]+1;
					ro.push(r); co.push(c+1); 
				}
			}
			
			cout<<graph[dRow][dCol]<<endl;

	}
	

	return 0;
}