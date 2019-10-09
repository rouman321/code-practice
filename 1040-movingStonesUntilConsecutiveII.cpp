/*
LeetCode 1040. Moving Stones Until Consecutive II
medium
time:	67.81%
space:	100%
*/
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        vector<int> ret;
        sort(stones.begin(),stones.end());
        ret.push_back(minM(stones));
        ret.push_back(maxM(stones));
        return ret;
    }
    
    int minM(vector<int> stones){
        int l = 0;
        int r = 1;
        int ret = INT_MAX;
        while(r<stones.size()){
            int slot = stones[r]-stones[l]-(r-l);
            int other = stones.size()-(r-l+1);
            if(other>=slot){
                if(other==1&&slot==0){
                    ret = min(ret,2);
                }
                else{
                    ret = min(ret,other);
                }
                r++;
            }
            else{
                l++;
            }
        }
        return ret;
    }
    
    int maxM(vector<int> stones){
        int n = stones.size();
        int ret = stones[stones.size()-2]-stones[0]-1-(n-3);
        ret = max(ret,stones[stones.size()-1]-stones[1]-1-(n-3));
        return ret;
    }
};