// class ListNode
// {
// private:
//     /* data */
// public:
//     int data ;
//     ListNode *next ;
//     ListNode(int data){
//         this->data = data ;
//         next = nullptr ;
//     }
// };
#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <unordered_set>
using namespace std ;



// ListNode struct as on leetcode

template <typename T>
struct ListNode {
    T val;
    ListNode<T> *next;
    
    ListNode() : val(T()), next(nullptr) {}
    ListNode(T x) : val(x), next(nullptr) {}
    ListNode(T x, ListNode<T> *next) : val(x), next(next) {}
};



// taking input recursively
template <typename T>
class LinkedList {
    ListNode <T> *head ;
    int size ;
    
    public :
ListNode<T> *takeInput(){
    T data ;
    cin >>data ;
    ListNode<T> *head = NULL ;
    ListNode<T> *temp = NULL ;
    while(data != NULL){
        ListNode<T> *newNode = new ListNode<T>(data) ;
        if(head == NULL){
            head = newNode ;
            temp = head ;
        }
        else {
             temp->next = newNode ;
             temp = temp->next ;
        }
        cin >>data ;
    }
    return head ;
}


//printing list recursively
void print(ListNode<T> *head){
    if(!head) return ;
    cout <<head->val<<endl ;
    print(head->next) ;
    return ;
}


// get length recursively
int lengthRecursive(ListNode<T> *head){
    if(!head->next) return 1 ;
    return 1 + lengthRecursive(head->next) ;
}


// inserting node recursively
ListNode<T> *insertRecursive(ListNode<T> *head,int n,T data){
    if(n == 0){
        ListNode<T> *newNode = new ListNode<T>(data) ;
        newNode->next = head ;
        head = newNode ;
        return head;
    }
    head->next = insertRecursive(head->next,n-1,data) ;
    return head ;
}



// deleting node  recursively
void deleteRecursive(ListNode<T> *head,int n){
    if(n==1){
        if(head->next){
            if(!head->next->next)
            head->next = nullptr ;
            return  ;
        }
    }
    if(n==0){
        if(!head->next){
            return ;
        }
        else {
            head->val = head->next->val ;
            head->next = head->next->next ;
            return  ;
        }
    }
    deleteRecursive(head->next,n-1) ;
}


// eliminating duplicate nodes recursively

void eliminateDuplicates(ListNode<T> *head){
    unordered_set <T> mpp ;
    for(auto temp = head;temp;temp=temp->next ){
        // mpp.insert(temp->val) ;
        if(temp->next)
        if(mpp.find(temp->val) != mpp.end() )
        {
            deleteRecursive(temp,0) ;
        }
        mpp.insert(temp->val) ;
    }
    return ;
}
};