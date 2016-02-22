class Solution {
public:
    bool isPalindrome(int x) {
        long long int bc = x;
		long long int rev = 0;
		
		while (bc > 0) {
			int digit = bc % 10;
			rev = rev * 10 + digit;
			bc /= 10;
			
		}
		
		while (x > 0) {
			int d1 = x % 10;
			int d2 = rev % 10;
			
			if (d1 != d2) return false;
			
			x /= 10;
			rev /= 10;
		}
		
		return true;
    }
};