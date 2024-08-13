#include <bits/stdc++.h>
using namespace std;

int finder(vector<int> &A, int target)
{
    int n = A.size();
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == target)
            return mid;
        else if (A[mid] > A[low])
        {
            if (A[mid] < target || target < A[low])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else if (target < A[mid] || target > A[low])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (A[low] == target)
        return low;
    return -1;
}

int main()
{
    vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
    cout << finder(vec, 2) << endl;
}