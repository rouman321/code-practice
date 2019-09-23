/*
LeetCode 677. Map Sum Pairs
medium
time	76.29%
space	40%
*/
struct Node{
    int val;
    vector<Node*> next;
    Node(int n){
        val = n;
        next.resize(26,NULL);
    }
};
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node(0);
    }
    
    void insert(string key, int val) {
        Node* cur = root;
        for(int i = 0;i < key.size();i++){
            int ind = key[i]-'a';
            if(cur->next[ind]==NULL){
                cur->next[ind] = new Node(0);
            }
            cur = cur->next[ind];
        }
        cur->val = val;
    }
    
    int sumup(Node* root){
        if(root==0){
            return 0;
        }
        int ret = root->val;
        for(int i = 0;i < root->next.size();i++){
            ret += sumup(root->next[i]);
        }
        return ret;
    }
    
    int sum(string prefix) {
        Node* cur = root;
        for(int i = 0;i < prefix.size();i++){
            int ind = prefix[i]-'a';
            if(cur->next[ind]==NULL){
                return 0;
            }
            cur = cur->next[ind];
        }
        return sumup(cur);
    }    
    
private:
    Node *root;
};
