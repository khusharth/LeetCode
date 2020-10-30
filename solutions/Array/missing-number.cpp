/*
* Approach 1: Sorting
* Time complexity: O(nlogn) 
* Space Complexity: O(1)
*/

class Solution1 {
public:
    int missingNumber(vector<int>& nums) { 
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            // After sorting array value = index if not then element is missing
            if (nums[i] != i)
                return i;
        }
        
        // If no missing number then return size of nums (new number to be added)
        return nums.size();
    }
};

/*
* Approach 2: Hashmap
* Time complexity: O(n) 
* Space Complexity: O(n)
*/

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, bool> seen;
        
        for(int i = 0; i < nums.size(); i++) {
            seen[nums[i]] = true;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            // If element not in hashmap then return the element
            if (!seen[i])
                return i;
        }   
        
        // If no missing number then return size of nums (new number to be added)
        return nums.size();
    }
};

/*
* Approach 3: Bit Manipulation (XOR)
* If we initialize an integer to n and XOR it with every index and value, we will be left with the missing number.
* Time complexity: O(n) 
* Space Complexity: O(1)
*/

class Solution3 {
public:
    int missingNumber(vector<int>& nums) { 
        // Same number XOR = 0 | XOR with 0 = the number itself
        // n (last num) is the number which is present instead of the missing number
        // we put missing as n as n is not present as index (last index = n-1)
        int missing = num.size();
        
        for(int i = 0; i < nums.size(); i++) {
           missing ^= i ^ nums[i];
        }
        
        return missing;
    }
};

/*
* Approach 4: Gauss's Formula (Sum of first n numbers)
* Time complexity: O(n) 
* Space Complexity: O(1)
*/

class Solution4 {
public:
    int missingNumber(vector<int>& nums) {  
        int n = nums.size();
        // Sum of first n natural numbers
        int expectedSum = n * (n + 1)/2;
        
        int actualSum = 0;
        for (int i = 0; i < n; i++)
            actualSum += nums[i];
        
        return expectedSum - actualSum;
    }
};