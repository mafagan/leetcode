#include <set>


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
		
		int lp1 = 0;
		int lp2 = 0;
		
		int max = 1;
		
		set<char> dataWindowSet;
		set<char>::iterator it;
		
		while (lp2 < s.length()) {
			
			
			it = dataWindowSet.find(s[lp2]);
			
			if (it == dataWindowSet.end()) {
				if (lp2 - lp1 + 1 > max) max = lp2 - lp1 + 1;
				
				dataWindowSet.insert(s[lp2]);
				lp2 += 1;
				continue;
			} else {
				while (dataWindowSet.find(s[lp2]) != dataWindowSet.end() ) {
					dataWindowSet.erase(s[lp1]);
					lp1 += 1;
				}
				
				dataWindowSet.insert(s[lp2]);
				lp2 += 1;
			}
			
		}
		
		return max;
		
    }
};
