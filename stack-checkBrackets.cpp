#include <bits/stdc++.h>
using namespace std ;

int main(){
    string s ;
    cin >> s ;
    stack<char> s1 ;
    for(auto i:s){
        if(!s1.empty()){
        if(s1.top() == i) s1.pop() ;
        } 
        else s1.push(i) ;
    }
    cout << s1.empty() << endl ;
}