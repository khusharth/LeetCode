/*
* Approach 1
* Time complexity: O(n)
* Space Complexity: O(1)
*/

class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int i = 0;
        // find target or just greater than target
        for ( ; i<nums.size(); i++) {
            if (nums[i] >= target) { 
                return i;
            }
        }
        return i;   // insert at last position
    }
};

/*
* Approach 2: Binary Search: loop invariant
* Time complexity: O(logn)
* Space Complexity: O(1)
*/

class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        
        // Invariant (non-changing): the desired index is between [low, high+1]
        while (start <= end) {
            mid = start + (end-start)/2; // keep checks of overflow values
            
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // (1) At this point, start > end. That is, start >= end+1
        // (2) From the invariant, we know that the index is between [start, end+1], so start <= end+1. Follwing from (1), now we know start == end+1.
        // (3) Following from (2), the index is between [start, end+1] = [start, start], which means that start is the desired index
        //     Therefore, we return start as the answer. You can also return end+1 as the result, since start == end+1

        return start;
    }
};

// Credits: https://leetcode.com/problems/search-insert-position/discuss/15101/C%2B%2B-O(logn)-Binary-Search-that-handles-duplicate