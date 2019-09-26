/*
LeetCode 900. RLE Iterator
medium
time:	62.17%
space:	83.33%
*/
class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        cur = 0;
        a = A;
    }
    
    int next(int n) {
        if(cur>=a.size()){
            return -1;
        }
        if(a[cur]>=n){
            a[cur] -= n;
            int tmp = cur;
            if(a[cur]==0){
                cur += 2;
            }
            return a[tmp+1];
        }
        while(cur<a.size()&&n>a[cur]){
            n -= a[cur];
            cur += 2;
        }
        if(cur>=a.size()){
            return -1;
        }
        a[cur] -= n;
        if(a[cur]==0){
            cur += 2;
            return a[cur-1];
        }
        return a[cur+1];
    }
private:
    vector<int> a;
    int cur;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */