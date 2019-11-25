/*
LeetCode 720. Longest Word in Dictionary
easy
time:	72ms
space:	24.2mb
*/
typedef struct Node{
    char ch;
    vector<Node*> next;
    Node(char c){
        ch = c;
        next = vector<Node*>(26,NULL);
    }
}node;
class Solution {
public:
    bool hasPre(string s, node* root){
        node* cur = root;
        for(int i = 0;i < s.size()-1;++i){
            if(cur->next[s[i]-'a']==NULL){
                return false;
            }
            cur = cur->next[s[i]-'a'];
        }
        return true;
    }
    void add(string s, node* root){
        node* cur = root;
        for(int i = 0;i < s.size()-1;++i){
            cur = cur->next[s[i]-'a'];
        }
        cur->next[s[s.size()-1]-'a'] = new node(s[s.size()-1]);
    }
    string longestWord(vector<string>& words) {
        string ret = "";
        sort(words.begin(),words.end());
        int len = 0;
        Node* root = new Node('a');
        for(string s: words){
            if(hasPre(s,root)){
                add(s,root);
                if(s.size()>len){
                    len = s.size();
                    ret = s;
                }
            }
        }
        return ret;
    }
};