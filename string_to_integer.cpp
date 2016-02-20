class Solution {

public:
	int isDigit(char ch) {
		if (ch <= '9' && ch >= '0') return 1;
		else return 0;
	}
	
    int myAtoi(string str) {
        int isNeg = 0;
		if (str.length() == 0) return 0;
		
		int sp = 0;
		while (str[sp] == '-' || str[sp] == '+') {
			if (str[sp] == '-') isNeg = 1 - isNeg;
			sp ++;
		}
		
		
		
		long long int res = 0;
		
		for (int i = sp; i < str.length(); i++) {
			if (isDigit(str[i]) == 0) return 0;
			
			res *= 10;
			res += str[i] - '0';
		}
		
		if (res > INT_MAX) return 0;
		
		return isNeg ? -res : res;
    }
};