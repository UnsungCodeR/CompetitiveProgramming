#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long int Sol(vector<long int> sol, long int N ){
    
    long int localMax= sol[0];
    long int globalMax=sol[0];
    for(int i = 1; i < N; i++){
        localMax = max(sol[i], localMax+ sol[i]);
        globalMax = max(localMax, globalMax);
    }
   return globalMax;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        vector<long int> vec(n);
        for(int i = 0 ; i < n ; i++){
            cin>>vec[i];
        }
        long int easy = 0;
        bool status= false;
        for(int i = 0 ; i < n ; i++){
        if(vec[i]>0){
            easy = easy + vec[i];
            status = true;
             }
        }      
        if(!status){
               easy = -999999;
            for(int i = 0 ; i < n ; i++){
             
                easy = max(vec[i],easy);
            }
        }
        cout<<Sol(vec, n)<<" "<<easy<<endl;
    }

    return 0;
}
