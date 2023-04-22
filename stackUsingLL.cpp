#include "ListNode.cpp"
using namespace std ;


template <typename T>
class stackUsingLL
{
private:
    ListNode<T> *head ;
    int curSize ;

public:
    // constructor
    stackUsingLL(){
        head = NULL ;
        curSize = 0 ;
    }

    //push
    void push(T data){
       if(!head){
        ListNode<T> *newNode = new ListNode<T>(data) ;
        head = newNode ;
        curSize++ ;
        return ;
       }
       ListNode<T> *newNode = new ListNode<T> (data) ;
       newNode->next = head ;
       head = newNode ;
       curSize++ ;
    }

    // pop function
    T pop(){
        if(head){
            T val = head->val ;
            head = head->next ;
            curSize-- ;
            return val ;
        }
        return 0 ;
    }

    //top function
    T top(){
        if(head){
            return head->val ;
        }
        return 0 ;
    }

    //size function 
    int size(){
        return curSize ;
    }

    //isEmpty
    bool isEmpty(){
        return curSize==0 ;
    }
};
