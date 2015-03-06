#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()==0) return false;
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m*n-1;

        int mid;

        while(left<=right){
            mid = left + (right - left) / 2;

            int x = mid/n;
            int y = mid%n;
            if(matrix[x][y]==target) return true;
            else if(matrix[x][y]<target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }

};
