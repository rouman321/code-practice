/*
LeetCode 638. Shopping Offers
medium
time:	37.48%
space:	50%
*/
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int minPrice = -1;
        for(int i = 0;i < special.size();i++){
            bool buy = true;
            vector<int> tmp = needs;
            for(int j = 0;j < special[i].size()-1;j++){
                tmp[j] -= special[i][j];
                if(tmp[j]<0){
                    buy = false;
                    break;
                }
            }
            if(!buy){
                continue;
            }
            int curPrice = special[i][special[i].size()-1]+shoppingOffers(price,special,tmp);
            if(minPrice==-1){
                minPrice = curPrice;
            }
            else{
                minPrice = min(minPrice,curPrice);
            }
        }
        int noSpec = 0;
        for(int i = 0;i < price.size();i++){
            noSpec += price[i]*needs[i];
        }
        if(minPrice==-1){
            minPrice = noSpec;
        }
        else{
            minPrice = min(noSpec,minPrice);
        }
        return minPrice;
    }
};