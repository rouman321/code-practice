/*
LeetCode 454. 4Sum II
medium
time:	46.05%
space:	77.27%
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m;
        for(int i = 0;i < A.size();i++){
            for(int j = 0;j < B.size();j++){
                if(m.find(A[i]+B[j])==m.end()){
                    m[A[i]+B[j]] = 0;
                }
                m[A[i]+B[j]]++;
            }
        }
        int cnt = 0;
        for(int i = 0;i < C.size();i++){
            for(int j = 0;j < D.size();j++){
                if(m.find(-1*(C[i]+D[j]))!=m.end()){
                    cnt+=m[-1*(C[i]+D[j])];
                }
            }
        }
        return cnt;
    }
};
