/*
* Approach 1
* Time complexity: O(n^2)
* Space Complexity: O(n^2)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        
        for (int i = 0; i < numRows; i++) {
              // Push an array with i size initialzied with 1 
              arr.push_back(vector<int>(i + 1, 1));
            
             // We start from 1 as 0th and last element are already initialized to 1
             for (int j = 1; j < i; j++) {  
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
             }
        }
        return arr;
    }
};