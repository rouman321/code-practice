/*
LeetCode 873. Length of Longest Fibonacci Subsequence
medium
time:	220ms
space:	10.1mb
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int,int> m;
        unordered_map<int,int> l;
        for(int i = 0;i < A.size();++i){
            m[A[i]] = i;
        }
        int ret = 0;
        for(int i = 1;i < A.size();++i){
            for(int j = 0;j < i;++j){
                if(m.find(A[i]-A[j])!=m.end()){
                    int prior = m[A[i]-A[j]];
                    if(prior<j){
                        int len = 0;
                        if(l.find(prior*A.size()+j)!=l.end()){
                            len = l[prior*A.size()+j]+1;
                        }
                        else{
                            len = 3;
                        }
                        l[j*A.size()+i] = len;
                        ret = max(ret,len);
                    }
                }
            }
        }
        return ret;
    }
};