/*
LeetCode 1109. Corporate Flight Bookings
medium
time:	54.28%
space:	100%
*/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n,0);
        for(int i = 0;i < bookings.size();i++){
            ret[bookings[i][0]-1] += bookings[i][2];
            if(bookings[i][1]<n){
                ret[bookings[i][1]] -= bookings[i][2];
            }
        }
        for(int i = 1;i < n;i++){
            ret[i] += ret[i-1];
        }
        return ret;
    }
};