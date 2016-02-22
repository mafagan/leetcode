class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
		
		int left = 0;
		int right = height.size() - 1;
		
		while (left != right) {
			int tmpRes;
			
			if (height[left] < height[right]) {
				tmpRes = height[left] * (right - left);
				left ++;
			} else {
				tmpRes = height[right] * (right - left);
				right --;
			}
			if (tmpRes > max) max = tmpRes;
			
		}
    }
};