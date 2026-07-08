class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 0;
        int maxProfit = INT_MIN;
        
        while(j < prices.size()){
            maxProfit = max(maxProfit, prices[j] - prices[i]);


            while(prices[i] > prices[j]){
                i++;
            }
            j++;

        }
        
        return maxProfit;
        
    }
};
