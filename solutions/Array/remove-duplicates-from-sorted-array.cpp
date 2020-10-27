/*
* Approach 1: Two Pointers
* Time complexity: O(n) : length of array
* Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // EDGE CASE
        if (nums.size() == 0) 
            return 0;
        
        int pointer1 = 0; // Points to end of final array
        for (int pointer2 = 1; pointer2 < nums.size(); pointer2++) {
            // Compare adjacent elements if not same then increment pointer1 and update final array
            if (nums[pointer1] != nums[pointer2]) {
                pointer1++;
                nums[pointer1] = nums[pointer2];
            }
        }
        
        return pointer1 + 1;
    }
};