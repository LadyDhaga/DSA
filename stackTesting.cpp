// #include "stackUsingArray.cpp"
#include "stackUsingLL.cpp"
#include <bits/stdc++.h>
using namespace std ;

int main(){
    stackUsingLL<int> s ;
    s.push(1) ;
    s.push(2) ;
    s.push(3) ;
    s.push(4) ;
    s.push(5) ;
    s.push(6) ;
    cout << s.top() << endl ;
    s.pop() ;
    cout << s.pop() << endl ;
    cout << s.top() << endl ;
}