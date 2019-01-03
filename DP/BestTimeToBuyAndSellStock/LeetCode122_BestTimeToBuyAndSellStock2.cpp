class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        //ѭ�������۸��Ҫ����ʱ�����롣��һ�쿪ʼѭ�������۸��Ҫ�½��ˣ������������ͬ��
        int day = prices.size();
        int profit = 0;
        int buy = 0;
        for( int i = 0 ; i < day ; i++)
        {
            if(prices[i+1] > prices[i])
            {
                buy = prices[i];
                for(i++; i < day ; i++)
                {
                    if(prices[i] > prices[i+1] || i== day - 1)
                    {
                        profit += prices[i] - buy;
                        break;
                    }
                }
            }
        }
        return profit;
    }
};

//������ʱ�临�Ӷ�O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int ans = 0;
       if(prices.size()==0) return ans;
       for(int i = 0 ; i < prices.size()-1; i++)
           ans += (prices[i+1]-prices[i])>0 ? prices[i+1]-prices[i]:0;
        return ans;
    }
};
