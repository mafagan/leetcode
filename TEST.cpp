#include <iostream>
#include <set>
using namespace std;

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
		
		while(str[sp] == ' ') sp ++;
		
//		while (str[sp] == '-' || str[sp] == '+') {
//			if (str[sp] == '-') isNeg = 1 - isNeg;
//			sp ++;
//		}
//		
		
		if (str[sp] == '-') {
			isNeg = 1;
			sp ++;
		} else if (str[sp] == '+') {
			isNeg = 0;
			sp ++;
		}
		
		long long int res = 0;
		
		if (isDisgit(str[sp]) == 0) return 0; 
		for (int i = sp; i < str.length(); i++) {
			if (isDigit(str[i]) == 0) break;
			
			res *= 10;
			res += str[i] - '0';
		}
		
		if ((isNeg == 0 )&& res > INT_MAX) {
			
			return INT_MAX;
		}
		else if ((isNeg == 1 )&& res > INT_MAX + 1){
			
			return INT_MIN;
		} 
		
		return isNeg ? -res : res;
    }
};
int main()
{
	string a = "-2147483649";
	Solution sol;
	cout << sol.myAtoi(a) << endl;
	return 0;
}
