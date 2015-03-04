class Solution {

public:

    int searchInsert(int A[], int n, int target) {
        int left = 0;
        int right = n-1;
        int mid;


        while(left <= right){
            mid = left + (right-left)/2;

            if(A[mid] == target)
                return mid;

            else if(A[mid] > target)
            {
                right = mid - 1;
                if(left > right) return mid;
            }

            else
            {
                left = mid + 1;
                if(left > right) return mid + 1;
            }
        }

        return left;
    }

};

