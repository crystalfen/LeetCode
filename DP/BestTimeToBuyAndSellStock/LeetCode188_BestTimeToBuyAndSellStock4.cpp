class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len<=1 || k <=0) return 0;
       if (k>len/2){ // simple case相当于可以任意次交易
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        vector<int> s(2*k);
        s[0] = -prices[0];
        for(int i = 1; i < 2*k; i++)
            s[i] = INT_MIN;
        for(int i  = 1; i < prices.size(); i++)
        {
            s[0] = max(s[0], - prices[i]);
            for(int j = 1; j < 2*k; j++)
            {
                if(j%2 != 0)//卖
                    s[j] = max(s[j], s[j-1]+prices[i]);
               else//买
                    s[j] = max(s[j], s[j-1] - prices[i]);
            }
        }
        return max(0, s[2*k-1]);

    }
};


//法二
class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
    //int K = 2;
    int len = prices.size();
    if(len<=1) return 0;
      if (K>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
    vector<vector<int>> profit(K+1,vector<int>(len,0));
    for(int k = 1; k <= K; k++)
    {
        int maxval = profit[k-1][0]-prices[0];
        for(int i = 1; i < len; i++)
        {
            profit[k][i] = max(profit[k][i-1],maxval+prices[i]);
            if(maxval<profit[k-1][i]-prices[i])
                maxval = profit[k-1][i]-prices[i];
        }
    }
    return profit[K][len-1];
    }
};

//法三
 class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int m = prices.size();
            if(m==0 || m==1 || k == 0) return 0;
            if (k>m/2){ // simple case
                int ans = 0;
                for (int i=1; i<m; ++i){
                    ans += max(prices[i] - prices[i-1],0);
                }
                return ans;
            }
            vector<vector<int>> buy(k+1,vector<int>(m+1,0));
            vector<vector<int>> sell(k+1,vector<int>(m+1,0));
            vector<int> end(m+1,0);
          //  buy[1][0] = -prices[0];
            for(int i=1;i<=k;i++)
                buy[i][0] = INT_MIN;

            for(int i=1;i<=m;i++){
                for(int j=1;j<=k;j++){
                    //for the first buy state, need to compare the current price with the previous price. sell[0][0] are all initialized with 0, then sell[0][0] - prices[i-1] is the price of current first buy state
                    buy[j][i] = max(buy[j][i-1], sell[j-1][i-1] - prices[i-1]);
                    sell[j][i] = max(buy[j][i-1]+prices[i-1],sell[j][i-1]);
                }
            }
            return sell[k][m];
        }
    };

//法三和法一一样的道理。把法三改成下面的模样，就和法一同一道理
class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int m = prices.size();
            if(m==0 || m==1 || k == 0) return 0;
            if (k>m/2){ // simple case
                int ans = 0;
                for (int i=1; i<m; ++i){
                    ans += max(prices[i] - prices[i-1],0);
                }
                return ans;
            }
            vector<vector<int>> buy(k+1,vector<int>(m+1,0));
            vector<vector<int>> sell(k+1,vector<int>(m+1,0));
            vector<int> end(m+1,0);
            buy[1][0] = -prices[0];
            sell[1][0] = INT_MIN;
            for(int i=2;i<=k;i++)
            {
                buy[i][0] = INT_MIN;
                sell[i][0] = INT_MIN;
            }


            for(int i=1;i<m;i++){
                for(int j=1;j<=k;j++){
                    //for the first buy state, need to compare the current price with the previous price. sell[0][0] are all initialized with 0, then sell[0][0] - prices[i-1] is the price of current first buy state

                    buy[j][i] = max(buy[j][i-1], sell[j-1][i] - prices[i]);
                    sell[j][i] = max(buy[j][i]+prices[i],sell[j][i-1]);
                }
            }
            return sell[k][m-1];
        }
    };




