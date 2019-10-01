/*
LeetCode 1005. Maximize Sum Of Array After K Negations
easy
time:	98.04%
space:	50%
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int> que;
        int m = 101;
        int sum = 0;
        for(int i = 0;i < A.size();i++){
            if(A[i]>=0){
                if(m>A[i]){
                    m = A[i];
                }
                sum += A[i];
            }
            else{
                if(que.size()>=K){
                    int tmp = que.top();
                    if(tmp>A[i]){
                        que.pop();
                        que.push(A[i]);
                        sum -= A[i];
                        sum += 2*tmp;
                    }
                    else{
                        sum += A[i];
                    }
                }
                else{
                    que.push(A[i]);
                    sum -= A[i];
                }
            }
        }
        if(que.size()<K){
            if(m==101||(!que.empty()&&m>-1*que.top())){
                int tmp = K-que.size();
                if(tmp%2!=0){
                    sum += 2*que.top();
                }
            }
            else{
                int tmp = K-que.size();
                if(tmp%2!=0){
                    sum -= 2*m;
                }
            }
        }
        return sum;
    }
};