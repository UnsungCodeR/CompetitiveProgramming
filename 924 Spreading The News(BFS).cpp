#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int number, linkNo, tempEmp, testNo, tempTest, count;
	cin>>number;
	
	vector<vector<int>> graph(number);
	vector<int> linkEmp;
	vector<int> test;
	for(int i = 0 ; i < number; i++){
		cin>>linkNo;
		while(linkNo--){
			cin>>tempEmp;
			graph[i].push_back(tempEmp);
		}
	}
	
	cin>>testNo;
	while(testNo--){
		cin>>tempTest;
		queue<int> que;
		vector<int> dist(number,-1);
		dist[tempTest] = 0;
		int firstday=0;
		que.push(tempTest);
		while(!que.empty()){
			int top = que.front(); que.pop();
			for(int i = 0 ; i < graph[top].size(); i++){
				int n = graph[top][i];
				if(dist[n] == -1){
					dist[n] = dist[top] + 1;
					que.push(n);
				}
			}
			
		}
		
		if(graph[tempTest].size() == 0) cout<<"0"<<endl;
		else{
			sort(dist.begin(), dist.end());
			vector<int> final(dist[dist.size()-1]+1, 0);
			
			for(int i = 0 ; i < dist.size(); i++){
				if(dist[i] >=0) final[dist[i]] ++;
			}
			vector<int> temp1(final.size());
			for(int i = 0 ; i < temp1.size(); i++) temp1[i] = final[i];
			sort(final.begin(), final.end());
			firstday = final[final.size()-1];
			
			int actualfirstday = 9999999;
			
			for(int i = 0 ; i < temp1.size() ; i++){
				if(temp1[i]==firstday){
					actualfirstday = min(actualfirstday, i);
				}
			}
			if(actualfirstday==0) actualfirstday++;
			cout<<final[final.size()-1]<<" "<<actualfirstday<<endl;
			final.clear();
		}
		dist.clear();
	}
	
	
	return 0;
}