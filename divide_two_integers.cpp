#include <iostream>
#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        int a = dividend;
        int b = divisor;

        if(divisor==0) return MAX_INT;
        if(divisor==MIN_INT) return 0;

        if(divisor<0) b = -divisor;

        if(dividend<0&&dividend!=MIN_INT) a = -dividend;
        else if(dividend<0&&dividend==MIN_INT) a = -(1 + dividend);

        int tempres[100];
        tempres[0] = b;
        int res = 1;

        int ptr = 1;

        int divres = a - b;

        while(divres>=b){

        }
    }
};
