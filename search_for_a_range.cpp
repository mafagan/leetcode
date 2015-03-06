#include <vector>
#include <iostream>
using namespace std;

class Solution {

public:
    int search(int A[], int begin, int end, int target){
        int left = begin;
        int right = end-1;
        int mid;

        while(left<=right){
            mid = left + (right - left) / 2;
            if(A[mid]==target) return mid;
            else if (A[mid]<target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }

    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;

        int left = 0;
        int right = n - 1;
        int mid;

        int leftIndex = -1;
        int rightIndex = -1;

        while(left<=right){
            mid = left + (right - left) / 2;
            if(A[mid]==target){
                leftIndex = mid;
                rightIndex = mid;
                break;
            }

            else if(A[mid]>target) right = mid - 1;
            else left = mid + 1;
        }

        if(leftIndex == -1){
            res.push_back(leftIndex);
            res.push_back(rightIndex);
            return res;
        }

        int leftleft = 0;
        int leftright = leftIndex;
        int rightleft = rightIndex;
        int rightright = n;

        int leftres = leftIndex;
        int rightres = rightIndex;

        while(leftres != -1){
            leftres = search(A, leftleft, leftright, target);
            if(leftres != -1){
                leftIndex = leftres;
                leftright = leftIndex;
            }
        }

        while(rightres != -1){
            rightres = search(A, rightleft+1, rightright, target);
            if(rightres != -1){
                rightIndex = rightres;
                rightleft = rightIndex;
            }
        }

        res.push_back(leftIndex);
        res.push_back(rightIndex);
        return res;
    }

};
