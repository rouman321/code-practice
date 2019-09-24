/*
LeetCode 676. Implement Magic Dictionary
medium
time	70.55%
space	66.7%
*/
struct Node{
    bool isWord;
    vector<Node*> next;
    Node(bool n){
        isWord = n;
        next.resize(26,NULL);
    }
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new Node(false);
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        Node* cur = root;
        for(int i = 0;i < dict.size();i++){
            cur = root;
            for(int j = 0;j < dict[i].size();j++){
                if(cur->next[dict[i][j]-'a']==NULL){
                    cur->next[dict[i][j]-'a'] = new Node(false);
                }
                cur = cur->next[dict[i][j]-'a'];
            }
            cur->isWord = true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        cout<<word<<endl;
        for(int i = 0;i < word.size();i++){
            for(int n = 0;n < 25;n++){
                word[i]++;
                if(word[i]>'z'){
                    word[i] = 'a';
                }
                Node* cur = root;
                bool notfound = false;
                for(int j = 0;j < word.size();j++){
                    if(cur->next[word[j]-'a']==NULL){
                        notfound = true;
                        break;
                    }
                    cur = cur->next[word[j]-'a'];
                }
                if(notfound){
                    continue;
                }
                if(cur->isWord){
                    return true;
                }
            }
            word[i]++;
            if(word[i]>'z'){
                word[i] = 'a';
            }
        }
        return false;
    }
    
private:
    Node* root;
};
