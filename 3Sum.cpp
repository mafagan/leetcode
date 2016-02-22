bool mysort(const int &a1, const int &a2) {
    return a1 < a2;
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    	/*
        for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j ++) {
				
				if (nums[i] > nums[j]) {
					int tmp = nums[i];
					nums[i] = nums[j];
					nums[j] = tmp;
				}
			}
		}*/
		
		sort(nums.begin(),nums.end(),mysort);
		
		vector<vector<int> > res;
		
		for (int i = 0; i < nums.size(); i++) {
		    if (i > 0 && nums[i] == nums[i-1]) continue;
			int m = i + 1;
			int n = nums.size() - 1;
			
			while (m < n) {
				
				if (nums[i] + nums[m] + nums[n] == 0) {
					if (res.size() != 0) {
						vector<int> tmpVec = res[res.size()-1];
						if (tmpVec[0] == nums[i] && tmpVec[1] == nums[m] && tmpVec[2] == nums[n]) {
							n--;
							m++;
							continue;
						}	
					}
					
					vector<int> tmpResVec;
					tmpResVec.push_back(nums[i]);
					tmpResVec.push_back(nums[m]);
					tmpResVec.push_back(nums[n]);
					
					res.push_back(tmpResVec);
					n--;
					m++;
				} else if (nums[i] + nums[m] + nums[n] > 0) {
					n --;
				} else {
					m ++;
				}
			}
		}
		
		return res;
    }
};