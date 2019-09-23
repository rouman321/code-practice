/*
LeetCode 781. Rabbits in Forest
medium
time	89.77%
space	50%
*/
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.size()==0){
            return 0;
        }
        unordered_map<int,int> cnt;
        for(int i = 0;i < answers.size();i++){
            if(cnt.find(answers[i])==cnt.end()){
                cnt[answers[i]] = 0;
            }
            cnt[answers[i]]++;
        }
        int ret = 0;
        for(auto ind: cnt){
            int num = ind.first+1;
            int c = ind.second;
            ret += c%num==0?c:c/num*num+num;
        }
        return ret;
    }
};