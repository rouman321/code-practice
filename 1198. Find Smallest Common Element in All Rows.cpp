/*
LeetCode 1198. Find Smallest Common Element in All Rows
medium
*/

/*
first attempt
time:	14.29%
space:	100%
*/
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int,int> m;
        for(int i = 0;i < mat.size();i++){
            for(int j = 0;j < mat[i].size();j++){
                if(m.find(mat[i][j])==m.end()){
                    m[mat[i][j]] = 0;
                }
                m[mat[i][j]]++;
            }
        }
        int occur = mat.size();
        int ret = 10000;
        bool has = false;
        for(auto mi:m){
            if(mi.second==occur&&ret>mi.first){
                has = true;
                ret = mi.first;
            }
        }
        if(has){
            return ret;
        }
        return -1;
    }
};

/*
second attempt
time:	42.86%
space:	100%
*/
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int> m(10000,0);
        for(int i = 0;i < mat.size();i++){
            for(int j = 0;j < mat[i].size();j++){
                m[mat[i][j]-1]++;
            }
        }
        int occur = mat.size();
        int ret = 10000;
        bool has = false;
        for(int i = 0;i < 10000;i++){
            if(m[i]==occur){
                return i+1;
            }
        }
        return -1;
    }
};