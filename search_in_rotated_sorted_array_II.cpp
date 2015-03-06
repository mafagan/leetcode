class Solution {

public:

    bool test(int A[], int n, int beginIndex){

        int tmp = A[beginIndex];

        while(beginIndex<n){

            if(A[beginIndex]>tmp) return true;

            beginIndex++;

        }

        return false;

    }



    bool search(int A[], int n, int target) {

        int left = 0;

        int right = n - 1;

        int mid;



        while(left <= right){

            mid = left + (right - left) / 2;



            if(A[mid] == target) return true;



            else if(A[mid] > target)

            {

                if(A[left] > target && A[left] <= A[mid]) left = mid + 1;

                else right = mid - 1;

            }



            else

            {

                if(A[left] < A[mid]) left = mid + 1;

                else if(A[left]==A[mid]){

                    if(test(A, n, mid)) left = mid + 1;

                    else right = mid - 1;

                }

                else if(A[left] > target) left = mid + 1;

                else if(A[left] <= target) right = mid - 1;

            }

        }

        return false;

    }

};
