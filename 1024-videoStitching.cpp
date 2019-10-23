/*
LeetCode 1024. Video Stitching
medium
time:	69.11%
space:	73.33%
*/
class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        if(T==0){
            return 0;
        }
        sort(clips.begin(),clips.end(),cmp);
        map<int,int> dp;
        if(clips[0][0]!=0){
            return -1;
        }
        dp[0] = 0;
        for(int i = 0;i < clips.size();i++){
            if(clips[i][0]>=T){
                break;
            }
            auto next = dp.lower_bound(clips[i][0]);
            if(next!=dp.end()){
                if(dp.find(clips[i][1])==dp.end()){
                    dp[clips[i][1]] = next->second+1;
                }
                else{
                    dp[clips[i][1]] = min(dp[clips[i][1]],next->second+1);
                }
            }
        }
        int ret = INT_MAX;
        for(auto i = dp.lower_bound(T);i !=dp.end();i++){
            ret = min(ret,i->second);
        }
        if(ret==INT_MAX){
            return -1;
        }
        return ret;
    }
};