/*
LeetCode 383. Ransom Note
time:	36.9%
space:	100%
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size()){
            return false;
        }
        vector<int> alpha(26,0);
        for(int i = 0;i < magazine.size();i++){
            alpha[magazine[i]-'a']++;
        }
        for(int i = 0;i < ransomNote.size();i++){
            if(alpha[ransomNote[i]-'a']==0){
                return false;
            }
            alpha[ransomNote[i]-'a']--;
        }
        return true;
    }
};