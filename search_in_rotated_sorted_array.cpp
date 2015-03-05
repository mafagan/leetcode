#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;
        int mid;

        while(left <= right)
        {
            mid = left + (right - left) / 2;

            if(A[mid] == target) return mid;

            else if(A[mid] > target)
            {
                if(A[left] > target && A[left] <= A[mid]) left = mid + 1;
                else right = mid - 1;
            }

            else
            {
                if(A[left] <= A[mid]) left = mid + 1;
                else if(A[left] > target) left = mid + 1;
                else if(A[left] <= target) right = mid - 1;
                
                
            }
        }

        return -1;
    }
};



int main()
{
    Solution a;

    int data[2];
    int target;
    cin >> data[0] >> data[1] >> target;

    int res = a.search(data, 2, target);
    cout << res << endl;
    return 0;
}
