class Solution {
public:
    int maxProfit(vector<int>& p)
    {
        if(p.size() < 2) return 0;
        int len = p.size();
        vector<int>buy(len);
        vector<int>sell(len);
        buy[0] = -p[0];
        sell[0] = 0;
        int ret = 0;
        for(int i = 1; i < len; i++)
        {
            sell[i] = max(buy[i-1]+p[i], sell[i-1] - p[i-1] + p[i]);
            if(sell[i]>ret)
                ret = sell[i];
            if(i==1)
               buy[i] = buy[0] + p[0] - p[1];
            else
                buy[i] = max(sell[i-2]-p[i], buy[i-1]+p[i-1]-p[i]);
        }
        return ret;
    }
};
