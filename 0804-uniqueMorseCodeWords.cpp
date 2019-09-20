/*
International Morse Code defines a standard encoding where each letter is mapped to
a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c"
maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given
below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
"-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the
Morse code of each letter. For example, "cba" can be written as "-.-..--...",
(which is the concatenation "-.-." + "-..." + ".-"). We'll call such a
concatenation, the transformation of a word.

Return the number of different transformations among all words we have.
*/
#include "../LCInput/stringVector.h"
#include <iostream>
#include <map>

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,int> myMap;
        int cnt = 0;
        for(int i = 0;i < words.size();i++)
        {
            string morse = "";
            for(int j = 0;j < words[i].size();j++)
            {
                morse += code[words[i][j]-'a'];
            }
            if(myMap.find(morse) == myMap.end())
            {
                cnt++;
                myMap[morse] = 1;
            }
        }
        return cnt;
    }
};

int main()
{
    vector<string> words = stringVectorInput("in.txt");
    Solution s;
    cout<<s.uniqueMorseRepresentations(words)<<endl;
    return 0;
}
