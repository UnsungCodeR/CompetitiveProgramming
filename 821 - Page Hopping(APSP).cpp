#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
vector<vector<int>>p;


int main() {
	int x,y, sum = 0, counter = 1, maxi = 0 ;
	double average;
	int AdjMatrix[401][401];
	 for(int i = 0; i < 401 ; i++){
            for(int j = 0 ; j < 401 ;j++){
                AdjMatrix[i][j] = 99999;
                if(i==j) AdjMatrix[i][j]=0;
            }
        }
	bool detect = false;
	while(cin>>x>>y){
		
		if(x!=0 && y!=0){
			x--;y--;
			maxi = max(maxi,max(x,y));
			AdjMatrix[x][y] = 1;
			detect = false;
		}
		else if(x==0 && y==0 && detect==false){

			p.assign(maxi, vector<int>(maxi));
		
			REP (k, 0, maxi+1 ) 
            	REP (i, 0, maxi+1 )
                	REP (j, 0, maxi+1)
                		AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k]+ AdjMatrix[k][j]);
            
            int path = 0 , sum = 0 ;
           	for(int i = 0 ; i <= maxi ; i++){
           		for(int j = 0 ; j <= maxi ; j++){
           			if(i!=j){
           				if(AdjMatrix[i][j] != 99999){
           						sum += AdjMatrix[i][j];
           						path++;
           				}
           			
           			}
           		}
           	}
           	cout<<"Case "<<counter<<": "<<"average length between pages = "<<fixed<<setprecision(3)<<double(sum)/double(path)<<" clicks"<<endl;
			detect = true;
			
			for(int i = 0; i < 401 ; i++){
        		 for(int j = 0 ; j < 401 ;j++){
                	AdjMatrix[i][j] = 99999;
                	if(i==j) AdjMatrix[i][j]=0;
        		  }
        	}
        	maxi = 0;
        	counter++;
        	p.clear();
		}
		else if(x==0 && y==0 && detect==true){
			break;
		}
	}
	return 0;
}