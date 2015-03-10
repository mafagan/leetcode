#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int *temp = new int[m+n];
        memcpy(temp, A, m*sizeof(int));
        memcpy(temp+m, B, n*sizeof(int));
        sort(temp, temp+m+n);

        for(int i=0; i<m+n; i++)
            cout << temp[i] << endl;
        double median = (m+n)%2 ? temp[(m+n)/2]: (temp[(m+n)/2-1]+temp[(m+n)/2])/2.0;

        delete temp;
        return median;
    }
};

int main()
{
    int a[] = {3,2};
    int b[] = {};

    Solution tt;
    cout << tt.findMedianSortedArrays(a, 2, b, 0) << endl;;
    return 0;
}
