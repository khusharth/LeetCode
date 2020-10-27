/*
* Approach 1: Two Pointers
* Time complexity: O(n)
* Space Complexity: O(1)
*/

class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        // Pointer to count all the elements except val
        int count = 0;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != val) {
                 // Overwite nums with all elements expect val
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};

/*
* Approach 2: Two Pointers: When elements are rare (swap rare elements out)
* In approach 1 we are copying all elements except the one we want to remove. To reduce copying we can just remove
* elements if they are rare (less)
* Time complexity: O(n) : Assignment operation (nums[i] = "") reduced to no. of rare elements
* Space Complexity: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    
        int i = 0; // Pointer for the start of Array
        int n = nums.size(); // Pointer for the end of Array
        
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1]; // Swap current element with last element 
                n--; // Decrement array size
            } else {
                // If not val then increment the pointer
                i++;
            }
        }
        
        return n;
    }
};