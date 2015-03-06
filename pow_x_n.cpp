#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        bool flag = false;
        if(n==0) return 1;
        if(n<0){
            x = 1/x;
            n = -1 * (n + 1);
            flag = true;
        }
        
        vector<double> res;
        double tmp = x;
        res.push_back(1);
        res.push_back(x);
        for(int i=2; i<sizeof(int)*8; i++) res.push_back(res[i-1]*res[i-1]);

        int bits = n;
        double retvalue = 1;
        for(int i=0; i<sizeof(int)*8; i++){
            if((bits&0x01) != 0)
            {
                retvalue *= res[i+1];
            }
            bits = bits >> 1;
        }
        if(flag) return retvalue*x;
        else return retvalue;
    }
};
int main()
{
    Solution a;
    double x;
    int n;
    cin >> x >> n;
    cout << a.pow(x, n) << endl;
    return 0;
}
