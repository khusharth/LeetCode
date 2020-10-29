/*
* Approach 1
* Time complexity: O(n^2)
* Space Complexity: O(n)
*/

class Solution1 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> arr(rowIndex+1, 1);

        for (int i = 1; i < rowIndex; i++) {
            // We add from end as we need starting values to compute new row values
            // arr[start] = prev row | arr[end] = new row
            for (int j = i; j > 0; j--) {
                arr[j] = arr[j] + arr[j-1];
            }
        }
        
        return arr;
    }
};

/*
* Approach 2: Maths: Combinatorics
* Time complexity: O(n)
* Space Complexity: O(n)
*/