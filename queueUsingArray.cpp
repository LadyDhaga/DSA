#include <bits/stdc++.h>
using namespace std;
template <typename T>

class queueWithArray
{
private:
    T *queue;
    int currSize;
    int nextIndex;
    int frontIndex;
    int capacity;

public:
    // constructor
    queueWithArray(int space)
    {
        queue = new T[space];
        currSize = 0;
        capacity = space;
        frontIndex = -1;
        nextIndex = 0;
    }

    // push function
    void push(T data)
    {
        if (currSize == capacity)
        {
            cout << "Queue full" << endl;
            return;
        }
        queue[nextIndex] = data;
        nextIndex = (nextIndex + 1) % capacity;
        currSize++;
        if (frontIndex == -1)
            frontIndex++;
        return;
    }

    // pop function
    void pop()
    {
        if (!currSize)
        {
            cout << "queue is Empty" << endl;
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        currSize--;
        if (currSize == 0)
        {
            frontIndex = -1;
            nextIndex = 0;
        }
        return;
    }

    // top value
    T front()
    {
        if (currSize)
            return queue[frontIndex];
        cout << "queue is Empty" << endl;
        return 0;
    }

    bool isEmpty()
    {
        return currSize == 0;
    }

    int size()
    {
        return currSize;
    }
};
