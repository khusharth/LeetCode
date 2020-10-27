/*
* Approach 1: Brute Force
* Time complexity: O(n^2)
* Space Complexity: O(1)
*/

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        for (int i=0; i < nums.size(); i++) {
          for (int j=i+1; j< nums.size(); j++) {
              if (nums[i]+nums[j] == target) {
                  output.push_back(i);
                  output.push_back(j);
                  return output;   
              }
          }
        }
        return output;
    }
};

/*
* Approach 2: Two pass Hash Table
* Time complexity: O(n) : Traverse list twice. Hash table reduced search to O(1)
* Space Complexity: O(n) : Extra space required to store hashtable
*/

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;     
        unordered_map<int, int> map;
    
        // Store nums[i] as key and index as value in map
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
    	    int numToFind = target - nums[i];
    
            // if num exist and num index not same as current num 
            if (map.count(numToFind) > 0 && map[numToFind] != i) {
                output.push_back(i);
                output.push_back(map[numToFind]);
                // delete current element from map so that pair is not repeated
                map.erase(nums[i]);
            }
        }
        
        return output;
    }
};

/*
* Approach 3: One pass Hash Table
* Time complexity: O(n) : Traverse list once and do the search|insertion in map at the same time.
* Space Complexity: O(n) : Extra space required to store hashtable
*/

class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Store nums[i] as key and index as value in map
        unordered_map<int, int> map;
      
        for (int i = 0; i < nums.size(); i++) {
    	    int numToFind = target - nums[i];
            // If pair found then return as there is only 1 solution
            if (map.count(numToFind) > 0) {
                return {i, map[numToFind]};
            }
            // If numToFind not found then:
            // Store the current element as key and its index as value
            map[nums[i]] = i;
        }
        
       return {};
    }
};