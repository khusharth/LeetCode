/*
* Approach 1: Brute Force: Checking all possible subarray
* Time complexity: O(n^2)
* Space Complexity: O(1)
*/

class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        int max = nums[0];
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum > max) {
                    max = sum;
                }
            }
        }
        
        return max;
    }
};

/*
* Approach 2: Kadane's Algorithm
* Time complexity: O(n)
* Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        int localMax = nums[0];
        int globalMax = nums[0];
        
        for (int i=1; i<nums.size(); i++) {
            // if max so far + current element > current element
            if(localMax + nums[i] > nums[i])
                localMax += nums[i];
            else
                localMax = nums[i]; // current element is greater
            
            // localMax = max(localMax + nums[i], nums[i]);
            
            if (localMax > globalMax)
                globalMax = localMax; // update globalMax only when localMax is more
        }
        
        return globalMax;
            
    }
};