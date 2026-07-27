class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 0;
        int maxProfit = 0;
        for(r = 0; r < prices.size(); r++){
            while(prices[l] > prices[r]){
                ++l;
            }
            if((prices[r] - prices[l]) > maxProfit){
                maxProfit = prices[r] - prices[l];
            }
            
        }
        return maxProfit;
    }
};
