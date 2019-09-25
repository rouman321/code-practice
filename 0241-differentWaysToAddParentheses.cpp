/*
LeetCode 241. Different Ways to Add Parentheses
medium
time:	9.87%
space:	16.67%
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        // cout<<input<<endl;
        vector<int> ret;
        if(input.size()==0){
            return ret;
        }
        vector<string> equation;
        int start = 0;
        for(int i = 0;i < input.size();i++){
            if(input[i]<'0'||input[i]>'9'){
                equation.push_back(input.substr(start,i-start));
                equation.push_back(string(1,input[i]));
                start = i+1;
            }
        }
        equation.push_back(input.substr(start,input.size()-start));
        if(equation.size()==1){
            ret.push_back(toInt(equation[0]));
            return ret;
        }
        string lp = "";
        string rp = input;
        for(int i = 1;i < equation.size();i+=2){
            lp += equation[i-1];
            vector<int> l = diffWaysToCompute(lp);
            lp += equation[i];
            rp = rp.substr(equation[i-1].size()+1,rp.size()-equation[i-1].size()-1);
            vector<int> r = diffWaysToCompute(rp);
            for(int li = 0;li < l.size();li++){
                for(int ri = 0;ri < r.size();ri++){
                    if(equation[i]=="+"){
                        ret.push_back(l[li]+r[ri]);
                    }
                    else if(equation[i]=="-"){
                        ret.push_back(l[li]-r[ri]);
                    }
                    else if(equation[i]=="*"){
                        ret.push_back(l[li]*r[ri]);
                    }
                    else{
                        ret.push_back(l[li]/r[ri]);
                    }
                }
            }
        }
        return ret;
    }
    
    int toInt(string s){
        int ret = 0;
        for(int i = 0;i < s.size();i++){
            ret *= 10;
            ret += s[i]-'0';
        }
        return ret;
    }
};