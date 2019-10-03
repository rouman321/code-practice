/*
LeetCode 1175. Prime Arrangements
easy
time:	53.47%
space:	100%
*/
class Solution {
public:
    int numPrimeArrangements(int n) {
        int cnt = 0;
        int mod = 1e9+7;
        vector<int> prime(n+1,0);
        vector<int> check(n+1,0);
        int num = 0;
        for(int i = 1;i <= n;i++){
            if(check[i]==0){
                prime[num] = i;
                num++;
            }
            for(int j = 1;j < num;j++){
                if(prime[j]*i>n){
                    break;
                }
                check[prime[j]*i] = 1;
                if(i%prime[j]==0){
                    break;
                }
            }
        }
        num--;
        cnt = factorial(num);
        long tmp = (long)(cnt)*factorial(n-num);
        cnt = tmp%mod;
        return cnt;
    }
    
    int factorial(int n){
        int ret = 1;
        int mod = 1e9+7;
        while(n>1){
            long tmp = (long)(ret)*n;
            ret = tmp%mod;
            n--;
        }
        return ret;
    }
};