/*
LeetCode 901. Online Stock Span
medium
time:	92.15%
space:	100%
*/
class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ret = 1;
        while(!s.empty()&&s.top().first<=price){
            ret += s.top().second;
            s.pop();
        }
        s.push(make_pair(price,ret));
        return ret;
    }
private:
    stack<pair<int,int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */