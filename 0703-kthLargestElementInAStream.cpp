/*
LeetCode 703. Kth Largest Element in a Stream
easy
time:	11.53%
space:	65%
*/
class KthLargest {
public:
    int bi(int val){
        int l = 0;
        int r = n.size();
        while(l<r){
            int mid = (l+r)/2;
            if(n[mid]==val){
                return mid;
            }
            if(n[mid]<=val){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
    
    KthLargest(int k, vector<int>& nums) {
        pos = k-1;
        n = nums;
        sort(n.begin(),n.end(),greater<int>());
    }
    
    int add(int val) {
        int i = bi(val);
        n.insert(n.begin()+i,val);
        // for(int i = 0;i < n.size();i++){
        //     cout<<n[i]<<" ";
        // }
        // cout<<endl;
        return n[pos];
    }
    
private:
    vector<int> n;
    int pos;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */