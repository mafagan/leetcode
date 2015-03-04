#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:

        int sqrt(int x) {

            int left = 0;

            int right = x;



            long long mid;



            while(left <= right){

                mid = left + (right-left)/2;

                cout << mid << endl;
                if(mid*mid<=x && (mid+1)*(mid+1)>x) return mid;

                else if(mid*mid < x) left = mid + 1;

                else right = mid - 1;
            }
            return 0;
        }
};

int main()
{
    Solution a;
    int data;
    cin >> data;
    cout << a.sqrt(data) << endl;
    return 0;
}
