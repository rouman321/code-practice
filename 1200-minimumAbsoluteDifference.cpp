/*
LeetCode 1200. Minimum Absolute Difference
easy
time:	93.93%
space:	100%
*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int dist = arr[1]-arr[0];
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        ret[0].push_back(arr[0]);
        ret[0].push_back(arr[1]);
        for(int i = 2;i < arr.size();i++){
            if(arr[i]-arr[i-1]<=dist){
                if(arr[i]-arr[i-1]<dist){
                    ret.clear();
                }
                dist = arr[i]-arr[i-1];
                ret.push_back(vector<int>());
                ret[ret.size()-1].push_back(arr[i-1]);
                ret[ret.size()-1].push_back(arr[i]);
            }
        }
        return ret;
    }
};