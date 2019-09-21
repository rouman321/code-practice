/*
LeetCode 1196. How Many Apples Can You Put into the Basket
easy
time:   66.67%
space:  100%
*/
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        priority_queue<int> p;
        int weight = 5000;
        int cur = 0;
        for(int i = 0;i < arr.size();i++){
            if(cur+arr[i]<=weight){
                cur += arr[i];
                p.push(arr[i]);
            }
            else{
                if(p.empty()){
                    continue;
                }
                int tmp = p.top();
                if(tmp>arr[i]){
                    cur += arr[i]-tmp;
                    p.pop();
                    p.push(arr[i]);
                }
            }
        }
        return p.size();
    }
};