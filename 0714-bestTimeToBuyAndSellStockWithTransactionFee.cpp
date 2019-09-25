/*
LeetCode 714. Best Time to Buy and Sell Stock with Transaction Fee
medium
time:	24.39%
space:	100%
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()==0){
            return 0;
        }
        int balance = 0;
        int stock = -1*prices[0];
        for(int i = 1;i < prices.size();i++){
            balance = max(balance,stock+prices[i]-fee);
            stock = max(stock,balance-prices[i]);
        }
        return balance;
    }
};