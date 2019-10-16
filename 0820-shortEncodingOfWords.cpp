/*
LeetCode 820. Short Encoding of Words
medium
time:	25.22%
space:	100%
*/
class Node{
public:
    Node(bool b){
        is_word = b;
    }
    Node* getNext(char c){
        if(m.find(c)==m.end()){
            m[c] = new Node(false);
        }
        return m[c];
    }
    void enable(){
        is_word = true;
    }
    
    bool isWord(){
        return is_word;
    }
    
    unordered_map<char,Node*> getMap(){
        return m;
    }
    
private:
    bool is_word;
    unordered_map<char,Node*> m;
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Node* root = new Node(false);
        for(int i = 0;i < words.size();i++){
            Node* cur = root;
            for(int j = words[i].size()-1;j >= 0;j--){
                cur = cur->getNext(words[i][j]);
            }
            cur->enable();
        }
        unordered_map<char,Node*> w = root->getMap();
        int ret = 0;
        for(auto i:w){
            queue<pair<Node*,int>> q;
            q.push(make_pair(i.second,1));
            while(!q.empty()){
                unordered_map<char,Node*> tmp = q.front().first->getMap();
                int l = q.front().second;
                q.pop();
                if(tmp.size()==0){
                    ret += l+1;
                }
                else{
                    for(auto j:tmp){
                        q.push(make_pair(j.second,l+1));
                    }
                }
            }
        }
        return ret;
    }
};