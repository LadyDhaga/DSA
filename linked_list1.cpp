#include "ListNode.cpp"
#include <bits/stdc++.h>

using namespace std ;

int main(){

    ListNode *head = takeInput() ;
    // print(head) ;
    // int n = lengthRecursive(head) ;
    // cout << n << endl ;
    // head =  insertRecursive(head,2,100) ;
    deleteRecursive(head,7) ;
    // eliminateDuplicates(head) ;s
    print(head) ;
}