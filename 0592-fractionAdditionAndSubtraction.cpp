/*
LeetCode 592. Fraction Addition and Subtraction
medium
time:	59.73%
space:	50%
*/
class Solution {
public:
    int gcd(int a, int b){
        if(a<b){
            swap(a,b);
        }    
        if(a==b){
            return a;
        }
        while(b){
            int tmp = a%b;
            a = b;
            b = tmp;
        }
        return a;
    }
    
    string fractionAddition(string expression) {
        int u = 0;
        int v = 0;
        int pos = 0;
        expression += " ";
        string input = "";
        int ui = 0;
        int vi = 0;
        int status = -1;
        while(pos<expression.size()){
            if(expression[pos]<='9'&&expression[pos]>='0'){
                input += expression[pos];
            }
            else if(expression[pos]=='/'){
                ui = stoi(input);
                input = "";
            }
            else{
                if(pos==0){
                    switch(expression[pos]){
                        case '+':
                            status = 0;
                            break;
                        case '-':
                            status = 1;
                            break;
                        default:
                            break;
                    }
                    pos++;
                    continue;
                }
                vi = stoi(input);
                input = "";
                if(v==0&&status==-1){
                    u = ui;
                    v = vi;
                }
                else{
                    if(v!=0){
                        int g = gcd(v,vi);
                        int tmp = v;
                        u *= vi/g;
                        v *= vi/g;
                        ui *= tmp/g; 
                // cout<<ui<<" "<<vi<<endl;
                    }
                    else{
                        v = vi;
                    }
                    switch(status){
                        case 0:
                            u += ui;
                            break;
                        case 1:
                            u -= ui;
                            break;
                    }
                }
                switch(expression[pos]){
                    case '+':
                        status = 0;
                        break;
                    case '-':
                        status = 1;
                        break;
                    default:
                        break;
                }
            }
            pos++;
        }
        string ret = "";
        if(u<0){
            if(v>0){
                ret += '-';  
            }
            u *= -1; 
        }
        if(u==0){
            v = 1;
        }
        else{
            int t = gcd(u,v);
            if(t!=1){
                u /= t;
                v /= t;
            }
        }
        // cout<<u<<" "<<v<<endl;
        ret += to_string(u)+'/'+to_string(v);
        return ret;
    }
};