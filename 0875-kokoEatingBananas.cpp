/*
LeetCode 875. Koko Eating Bananas
medium
time:	46.04%
space:	100%
*/
class Solution {
public:
    bool judge(int k, vector<int>& piles, int h){
        int cnt = 0;
        for(int i = 0;i < piles.size();i++){
            cnt += piles[i]%k==0?piles[i]/k:piles[i]/k+1;
        }
        return cnt<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        long sum = 0;
        int r = 0;
        for(int i = 0;i < piles.size();i++){
            sum += piles[i];
            r = max(r,piles[i]);
        }
        int l = sum/H;
        l = max(1,l);
        while(l<r){
            int mid = (l+r)/2;
            if(judge(mid,piles,H)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};