#include <climits>
using namespace std ;

class stackUsingArray
{
private:
    int *data ;
    int nextIndex ;
    int capacity ;

public:


    //default constructor
 
    stackUsingArray(int totalSize){
        data = new int[totalSize] ;
        capacity = totalSize ;
        nextIndex = 0 ;
    }


    //push function

    void push(int val){
        if(nextIndex == capacity) return  ;
        data[nextIndex] = val ;
        nextIndex++ ;
    }


    //pop function also returns the value of the popped element

    int pop(){
        if (isEmpty())
        {
            return INT_MIN ;
        }
        
        nextIndex-- ;
        return data[nextIndex] ;
    }


    //top element excess 

    int top(){
        if (nextIndex == 0)
        {
            return INT_MIN ;
        }
        return data[nextIndex-1] ;
    }


    // to check if the stack is empty or not 

    bool isEmpty(){
        return nextIndex == 0 ;
    }
};
