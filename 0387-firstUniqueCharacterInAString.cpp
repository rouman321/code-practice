/*
LeetCode 387. First Unique Character in a String
time:   60.07%
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int i;
        int index = 0;
        int flag = 0;
        while(index < s.size())
        {
            flag = 0;
            for(i = 0;i < s.size();i++)
            {
                if(s[i] == s[index]&&i != index)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                return index;
            }
            index++;
        }
        return -1;
    }
};