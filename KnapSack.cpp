#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> vec(n);
        for(int i = 0 ; i < n ; i++){
            cin>>vec[i];
        }
        vector<int>Min(k+1);
        for(int i = 0 ; i <=k; i++){
            Min[i] = 0;
        }
        
        for(int i = 1 ; i <= k; i++){
            for(int j = 0; j < n; j++){
                if(vec[j]<=i){
                    Min[i] = max(Min[i], Min[i-vec[j]]+vec[j]);
			//max is used because i iterates, pick the best case.
			//Min[i-vec[j]] is the memory which stored the optimal sub-solution.
                }
            }
        }
        cout<<Min[k]<<endl;
    }
    return 0;
}
