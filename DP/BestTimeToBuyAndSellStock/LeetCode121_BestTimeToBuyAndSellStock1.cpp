//��һ���ռ临�Ӷ�O(n),Ԥ����ʱ�临�Ӷ�O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //����һ�����飬��¼�ڵ�i����������׬����Ǯ��
        vector<int> profit(prices.size());
        if(prices.size()<=1) return 0;
        profit[0] = 0;
        int min = prices[0]; //��¼ǰi����С�ļ۸�
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

//�������ռ临�Ӷ�O(1),ʱ�临�Ӷ�O(n)
class Solution{
public:
    int maxProfit(vector<int>& prices)
    {   int len = prices.size();
       if(len<=1) return 0;
       int s1 = -prices[0];//��һ���������
       int s2 = INT_MIN;//��һ����������
       for(int i = 1; i < len; i++)
       {
           s1 = max(s1,-prices[i]);
           s2 = max(s2,s1+prices[i]);
       }
       return max(0,s2);
    }
    };
