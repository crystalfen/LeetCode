class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        vector<int> buy(len);
        vector<int> sell(len);
        if(len<=1) return 0;
        buy[0] = -prices[0];
        sell[0] = -fee;
        int maxprofit = 0;
        for(int i  = 1 ; i < len ; i++)
        {
          buy[i] = max(sell[i-1] - prices[i], buy[i-1] + prices[i-1] - prices[i]);
          sell[i] = max(sell[i-1] - prices[i-1] + prices[i], buy[i-1] + prices[i] - fee);
          if(sell[i] > maxprofit)
              maxprofit = sell[i];
        }

        return maxprofit;
    }
};
