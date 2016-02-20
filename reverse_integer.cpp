class Solution {
public:
    int reverse(int x) {
        long long int digits[1001];
		int sp = 0;
		
		int isNeg = 0;
		
		if (x < 0) {
			x = -x;
			isNeg = 1;
		}
		
		long long int res = 0;
		int times = 1;
		
		while (x > 0) {
			
			int digit = x % 10;
			digits[sp] = digit;
			sp ++;
			x /= 10;
		}
		
		while (sp - 1 >= 0) {
			res += digits[sp - 1] * times;
			if (res >= INT_MAX) return 0;
			times *= 10;
			sp --;
		}
		
		
		
		return isNeg == 1 ? -res : res;
    }
};