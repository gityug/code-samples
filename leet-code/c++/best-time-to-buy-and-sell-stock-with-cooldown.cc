// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
//
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
// Example:
//
// prices = [1, 2, 3, 0, 2]
// maxProfit = 3
// transactions = [buy, sell, cooldown, buy, sell]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s(0), sp(0); // Max profit with sequence ending with a sale
        int c(0), cp(0); // Max profit with sequence ending with cooldown
        int n(0), np(0); // Max profit with sequence ending with no-op -- happens between buy and sell
        int b(0), bp(0); // Max profit with sequence ending with a buy
        
        for (int i = 1; i < prices.size(); ++i) {
            int d = prices[i] - prices[i-1];
            s = max(np + d, bp + d );
            c = max(cp, sp);
            n = max(np + d, bp + d);
            b = cp;
            
            sp = s;
            cp = c;
            np = n;
            bp = b;
        }
        return max(s, c); // need not consider buy and no-op as last items in the max profit sequence as they dont contribute to profit
    }
};
