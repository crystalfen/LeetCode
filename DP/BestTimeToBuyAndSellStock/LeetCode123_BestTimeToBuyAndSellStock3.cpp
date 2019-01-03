//法一：基于状态机制
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;
	int s1=-prices[0],s2=INT_MIN,s3=INT_MIN,s4=INT_MIN;

	for(int i=1;i<prices.size();++i) {
		s1 = max(s1, -prices[i]); //s1代表第一次购买，其值代表第一次购买的利润
		s2 = max(s2, s1+prices[i]); ////s2代表第一次卖出，其值代表第一次卖出的利润
		s3 = max(s3, s2-prices[i]); ////s3代表第二次购买，其值代表第二次购买的利润
		s4 = max(s4, s3+prices[i]); ////s4代表第二次卖出，其值代表第二次卖出的利润
	}
	return max(0,s4);
    }
};

//法二：profit[k][i]代表直到第i天第k次卖出的利润。
//转移公式profit[k][i]=max(profit[k][i-1],maxval+prices[i]);括号里的第一个式子代表什么都不做。后一个式子代表卖出股票。maxval = max(profit[k-1][j]-prices[j]), j = 1,...i-1;
//若maxval+prices[i]>profit[k][i-1]，表明在第k-1次什么都没做的那一天，让那一天变成购买，然后在i天卖出。增加了一次买卖的操作。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int K = 2;
    int len = prices.size();
    if(len<=1) return 0;
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
