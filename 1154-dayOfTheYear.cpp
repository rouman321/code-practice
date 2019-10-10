/*
LeetCode 1154. Day of the Year
easy
time:	100%
space:	100%
*/
class Solution {
public:
    int dayOfYear(string date) {
        bool isPrime = false;
        int ret = 0;
        string str = "";
        int i = 0;
        while(date[i]!='-'){
            str += date[i];
            i++;
        }
        int year = toInt(str);
        isPrime = (year%400==0)||(year%100!=0&&year%4==0);
        i++;
        str = "";
        while(date[i]!='-'){
            str += date[i];
            i++;
        }
        int month = toInt(str);
        for(int j = 0;j < month-1;j++){
            if(j==0||j==2||j==4||j==6||j==7||j==9||j==11){
                ret += 31;
            }
            else if(j!=1){
                ret += 30;
            }
            else{
                if(isPrime){
                    ret += 29;
                }
                else{
                    ret += 28;
                }
            }
        }
        i++;
        str = "";
        while(i<date.size()){
            str += date[i];
            i++;
        }
        ret += toInt(str);
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