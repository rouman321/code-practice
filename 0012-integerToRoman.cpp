/*
LeetCode 12. Integer to Roman
medium
time	49.74%
space	100%
*/
class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        while(num > 0){
            if(num >= 1000){
                while(num>=1000){
                    ret += "M";
                    num -= 1000;
                }
            }
            else if(num >= 100){
                int tmp = num/100;
                if(tmp == 9){
                    ret += "CM";
                    tmp = 0;
                }
                if(tmp >= 5){
                    ret += "D";
                    tmp -= 5;
                }
                else if(tmp==4){
                    ret += "CD";
                    tmp = 0;
                }
                for(int i = 0;i < tmp;i++){
                    ret += "C";
                }
                num %= 100;
            }
            else if(num >= 10){
                int tmp = num/10;
                if(tmp == 9){
                    ret += "XC";
                    tmp = 0;
                }
                if(tmp >= 5){
                    ret += "L";
                    tmp -= 5;
                }
                else if(tmp==4){
                    ret += "XL";
                    tmp = 0;
                }
                for(int i = 0;i < tmp;i++){
                    ret += "X";
                }
                num %= 10;
            }
            else{
                if(num == 9){
                    ret += "IX";
                    num = 0;
                }
                if(num >= 5){
                    ret += "V";
                    num -= 5;
                }
                else if(num==4){
                    ret += "IV";
                    num = 0;
                }
                for(int i = 0;i < num;i++){
                    ret += "I";
                }
                num = 0;
            }
        }
        return ret;
    }
};