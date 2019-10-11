/*
LeetCode 492. Construct the Rectangle
easy
time:	26.21%
space:	100%
*/
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int cur = 1;
        while(cur*cur<area){
            cur++;
        }
        while(area%cur!=0){
            cur++;
        }
        return {cur,area/cur};
    }
};