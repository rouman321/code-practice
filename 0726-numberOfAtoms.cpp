/*
LeetCode 726. Number of Atoms
hard
time:	0ms
space:	9.7mb
*/
typedef struct Node{
    string name;
    int cnt;
    Node(string s, int n){
        name = s;
        cnt = n;
    }
}node;
class Solution {
public:
    bool static cmp(node &a, node &b){
        return a.name<b.name;
    }
    string countOfAtoms(string formula) {
        stack<node> s;
        for(int i = 0;i < formula.size();++i){
            if(formula[i]==')'){
                vector<node> t;
                while(s.top().name!="("){
                    t.push_back(s.top());
                    s.pop();
                }
                s.pop();
                ++i;
                string num = "";
                while(i<formula.size()&&formula[i]>='0'&&formula[i]<='9'){
                    num += formula[i];
                    ++i;
                }
                --i;
                for(int j = t.size()-1;j >= 0;--j){
                    t[j].cnt *= stoi(num);
                    s.push(t[j]);
                }
            }
            else if(formula[i]>='0'&&formula[i]<='9'){
                string num = "";
                while(i<formula.size()&&formula[i]>='0'&&formula[i]<='9'){
                    num += formula[i];
                    ++i;
                }
                node tmp = s.top();
                s.pop();
                tmp.cnt *= stoi(num);
                s.push(tmp);
                --i;
            }
            else{
                string tmp = "";
                tmp += formula[i];
                if(i==formula.size()-1||(formula[i+1]>='a'&&formula[i+1]<='z')){
                    tmp += formula[i+1];
                    s.push(node(tmp,1));
                    ++i;
                }
                else
                    s.push(node(tmp,1));
            }
        }
        string ret = "";
        vector<node> atom;
        unordered_map<string,int> m;
        while(!s.empty()){
            node t = s.top();
            s.pop();
            if(m.find(t.name)==m.end()){
                m[t.name] = 0;
            }
            m[t.name] += t.cnt;
        }
        for(auto i:m){
            atom.push_back(node(i.first,i.second));
        }
        sort(atom.begin(),atom.end(),cmp);
        for(int i = 0;i < atom.size();++i){
            ret += atom[i].name;
            if(atom[i].cnt!=1)
                ret += to_string(atom[i].cnt);
        }
        return ret;
    }
};