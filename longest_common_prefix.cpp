class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
		
		string commonStr = strs[0];
		
		for (int i = 1; i < strs.length(); i++) {
			string tmmStr = "";
			
			for (int j = 0; j < commonStr.length() && j < strs[i].length(); j++) {
				if (commonStr[j] == strs[i][j]) tmmStr += commonStr[j];
				else break;
			}
			
			commonStr = tmmStr;
		}
		
		return commonStr;
    }
};