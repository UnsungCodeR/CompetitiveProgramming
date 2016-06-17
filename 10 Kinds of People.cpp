#include <iostream>
#include <vector>
#include <string>
using namespace std;

int setNo[1001][1001];
vector<vector<int>> vec;
int x1,y1,x2,y2;
int groupno=0;
int a,b;

inline bool inbound(int x, int y) {return x>=0 && x<a && y>=0 && y<b;}

void FloodFill(int tempx, int tempy){
    setNo[tempx][tempy]=groupno;
    if (setNo[tempx+1][tempy] == 0 && inbound(tempx+1, tempy) && vec[tempx+1][tempy] == vec[tempx][tempy]) {
        FloodFill(tempx+1, tempy);
    }
    if (setNo[tempx-1][tempy] == 0 && inbound(tempx-1, tempy) && vec[tempx-1][tempy] == vec[tempx][tempy]) {
        FloodFill(tempx-1, tempy);
    }
    if (setNo[tempx][tempy+1] == 0 && inbound(tempx, tempy+1) && vec[tempx][tempy+1] == vec[tempx][tempy]) {
        FloodFill(tempx, tempy+1);
    }
    if (setNo[tempx][tempy-1] == 0 && inbound(tempx, tempy-1) && vec[tempx][tempy-1] == vec[tempx][tempy]) {
        FloodFill(tempx, tempy-1);
    }
}

int main() {
    
    string temp;
    cin>>a>>b;
    vec.resize(a);
    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            setNo[i][j]=0;
        }
    }
    
    for(int i = 0 ; i < a ; i++){
        cin>>temp;
        for(int j = 0 ; j < temp.size(); j++){
            vec[i].push_back(temp[j] - '0');
        }
    }
    
    for(int i=0; i<a; i++) {
        for(int j=0; j<vec[i].size(); j++) {
            if (setNo[i][j] == 0) {
                
                groupno++;
                FloodFill(i, j);
            }
        }
    }
    
    int no;
    cin>>no;
    while(no--){
        cin>>x1>>y1>>x2>>y2;
        if (setNo[x1-1][y1-1] == setNo[x2-1][y2-1] && vec[x1-1][y1-1]==1)
            cout << "decimal"<<endl;
        else
            if (setNo[x1-1][y1-1] == setNo[x2-1][y2-1] && vec[x1-1][y1-1]==0)
            cout << "binary"<<endl;
        else
            if (setNo[x1-1][y1-1] != setNo[x2-1][y2-1])
            cout << "neither"<<endl;
    }

    return 0;
}