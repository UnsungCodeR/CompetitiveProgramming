#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main() {
    string str;
    string message;
    int test;
    
    map<char, vector<char>> m;
    cin>>test;
    while(test--){
        string series = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ori = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     	cin>>str;
       	getline(cin, message);
       	getline(cin, message);
    
    //check for duplicated characters
    for(int i = 0 ; i < str.size()-1; i++){
        for(int j = i; j< str.size(); j++){
            if(i!=j){
                if(str[i]==str[j]){
                    str.erase(j,1);
                }
            }
        }
    }
    //take away repeated character from alphabet series
    for(int i = 0 ; i < str.size() ; i++){
        for(int j = 0 ; j < series.size(); j++){
            if(str[i] == series[j])
                series.erase(j,1);
        }
    }
     //string to vector
    vector<char> vec(str.begin(), str.end()); 
    
    //map the str and series
    int temp=series.size();
    int k=0;
     while(k<temp){
            for(int c = 0 ; c < str.size() ; c++){
                if(k<temp){
                    m[str[c]].push_back(series[k]);
                    k++;
                }
            }
        }
	
   //sort the key value and put into a string
        string new_series;
        for(const auto &c : m){
            int size = c.second.size();
            new_series.push_back(c.first);
            for(int i = 0 ; i < size; i++){           
                new_series.push_back(c.second[i]);
            }
        }

        //map ori and new_series together
        map<char, char> m1;
        for(int i = 0 ; i < new_series.size() ; i++){
            m1.insert(pair<char,char>(new_series[i], ori[i]));
        }

        map<char, char>::iterator p;
        for(int i = 0 ; i < message.size(); i++){
            if(message[i] != ' '){
                p = m1.find(message[i]);
                cout<<p->second;
            }
            else cout<<" ";
        }
        m.clear();
        m1.clear();
        cout<<endl;
        
    
    
    
    }
    return 0;
    
}