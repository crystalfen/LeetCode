//法一：空间复杂度O(n),预处理时间复杂度O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //借助一个数组，记录在第i天卖出可以赚多少钱。
        vector<int> profit(prices.size());
        if(prices.size()<=1) return 0;
        profit[0] = 0;
        int min = prices[0]; //记录前i天最小的价格
        for(int i = 1; i <= prices.size()-1; i++)
        {
            if(prices[i] <= min)
            {
                profit[i] = 0;
                min = prices[i];
            }
            else
            {
                profit[i] = prices[i] - min;
            }

        }
        sort(profit.begin(), profit.end());
        return profit[prices.size()-1];
    }
};

//法二：空间复杂度O(1),时间复杂度O(n)
class Solution{
public:
    int maxProfit(vector<int>& prices)
    {   int len = prices.size();
       if(len<=1) return 0;
       int s1 = -prices[0];//第一次买的利润
       int s2 = INT_MIN;//第一次卖的利润
       for(int i = 1; i < len; i++)
       {
           s1 = max(s1,-prices[i]);
           s2 = max(s2,s1+prices[i]);
       }
       return max(0,s2);
    }
    };
