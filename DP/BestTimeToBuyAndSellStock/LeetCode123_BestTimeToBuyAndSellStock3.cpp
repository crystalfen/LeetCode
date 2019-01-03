//��һ������״̬����
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;
	int s1=-prices[0],s2=INT_MIN,s3=INT_MIN,s4=INT_MIN;

	for(int i=1;i<prices.size();++i) {
		s1 = max(s1, -prices[i]); //s1�����һ�ι�����ֵ�����һ�ι��������
		s2 = max(s2, s1+prices[i]); ////s2�����һ����������ֵ�����һ������������
		s3 = max(s3, s2-prices[i]); ////s3����ڶ��ι�����ֵ����ڶ��ι��������
		s4 = max(s4, s3+prices[i]); ////s4����ڶ�����������ֵ����ڶ�������������
	}
	return max(0,s4);
    }
};

//������profit[k][i]����ֱ����i���k������������
//ת�ƹ�ʽprofit[k][i]=max(profit[k][i-1],maxval+prices[i]);������ĵ�һ��ʽ�Ӵ���ʲô����������һ��ʽ�Ӵ���������Ʊ��maxval = max(profit[k-1][j]-prices[j]), j = 1,...i-1;
//��maxval+prices[i]>profit[k][i-1]�������ڵ�k-1��ʲô��û������һ�죬����һ���ɹ���Ȼ����i��������������һ�������Ĳ�����
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
