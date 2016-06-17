#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define INF 1000000000000100000LL
vector<long long> vec;

char Finder(long long N, long long K){
    if(N==1) return 'N';
    if(N==2) return 'A';
    if(K<=vec[N-2]) Finder(N-2, K);
    else Finder(N-1, K-vec[N-2]);
}

int main() {
    long long N, K;
    cin>>N>>K;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    for(int i = 3; i <= N+1 ; i++){
        vec.push_back(vec[i-2] + vec[i-1]);
        if(vec[i] > INF) vec[i] = INF;
    }
    cout<<Finder(N,K);
    return 0;
}