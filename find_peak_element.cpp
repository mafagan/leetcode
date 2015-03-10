#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int left = 0;
        int right = num.size()-1;

        int mid;

        while(true){
            mid = (left + right) / 2;
            if((mid-1<0||num[mid-1]<num[mid])&&(mid+1>=num.size()||num[mid]>num[mid+1])) return mid;
            else if(mid-1>=0&&num[mid]<num[mid-1]) right = mid - 1;
            else mid = left = mid + 1;
        }
    }

};
