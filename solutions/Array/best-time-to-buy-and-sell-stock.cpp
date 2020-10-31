/*
* Approach 1: Brute Force
* Time complexity: O(n^2)
* Space Complexity: O(1)
*/

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        
        // i = day to buy
        for (int i = 0; i < prices.size(); i++) {
            // j = day to sell
            for (int j = i+1; j < prices.size(); j++) {
                // profit = j (selling) - i (buying)
                int profit = prices[j] - prices[i];
                if (profit > maxProfit)
                    maxProfit = profit;
            }
        }
        
        return maxProfit;
    }
};

/*
* Approach 2: One Pass
* Time complexity: O(n)
* Space Complexity: O(1)
*/

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {        
        int maxProfit = 0; 
        int minPrice = INT_MAX; // set min price to MAX INT value
        
        for (int i = 0; i < prices.size(); i++) {

            if (prices[i] < minPrice) { // check if we can get a lower price to buy
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProfit) { // check if we can make more profit
                maxProfit = prices[i] - minPrice;
            }
            
        }
        
        return maxProfit;
    }
};