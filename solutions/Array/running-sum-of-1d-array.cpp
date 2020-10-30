/*
* Approach 1
* Time complexity: O(n)
* Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        for (int i = 1; i < nums.size(); i++) {
            // Add current number in sum of previous number
            nums[i] += nums[i-1];
        }
        
        return nums;
    }
};