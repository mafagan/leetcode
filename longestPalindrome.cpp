
class Solution {
public:

	int getOrdCurLength(string s, int pos) {
		int left = pos - 1;
		int right = pos + 1;
		
		int counter = 0;
		
		while (s[left] == s[right] && left >= 0 && right < s.length()) {
			counter ++;
			left --;
			right ++;
		}
		
		return counter;
	}
	
	int getEvenCurLength(string s, int pos) {
		int left = pos;
		int right = pos + 1;
		
		int counter = 0;
		
		while (s[left] == s[right] && left >= 0 && right < s.length()) {
			counter ++;
			left --;
			right ++;
		}
		
		return counter;
	}
	
    string longestPalindrome(string s) {
		if (s.length() == 0) return 0;
		
        int max = 0;
		
		int sp = 0;
		string res;
		
		while (sp < s.length()) {
			int ord = getOrdCurLength(s, sp);
			int even = getEvenCurLength(s, sp);
			
		
			if (ord * 2 + 1 > max) {
				max = ord * 2 + 1;
				res = s.substr(sp - ord, max);
				//cout << "ord: " << ord << " " << sp << " " << res << endl;
//				cout << "heihei: " << res;
			}
			if (even * 2 > max) {
				max = even * 2;
				res = s.substr(sp - even + 1, max);
				
				
			}
			
			sp ++;
		}
		
		return res;
    }
};