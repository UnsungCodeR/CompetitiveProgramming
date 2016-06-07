#include <cmath>
#include <cstdio>
#include <vector>
MAP C++
-Iterate the map
-Access map with .first and .second

1)
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    map<int, int> m;
    int num, temp;
    cin>>num;
    for(int i = 1 ; i<= num ; i++){
        cin>>temp;
        m.insert(pair<int,int>(temp, i));
    }
    
    for (auto const &c : m){
        cout<<c.second<<endl;
    }
     
    
    return 0;
}
