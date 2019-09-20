/*
In a deck of cards, every card has a unique integer.  You can order the deck in any
order you want.

Initially, all the cards start face down (unrevealed) in one deck.

Now, you do the following steps repeatedly, until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck, put the next top card of the deck at the
bottom of the deck.
If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

The first entry in the answer is considered to be the top of the deck.
*/
#include "../LCInput/numInput.h"
#include <iostream>
#include <algorithm>

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        bool flag = true;
        int cnt = 0;
        int index = 0;
        vector<int> ret(deck.size(),0);
        while(cnt < deck.size())
        {
            if(ret[index] == 0)
            {
                if(flag)
                {
                    ret[index] = deck[cnt];
                    flag = false;
                    cnt++;
                }
                else
                {
                    flag = true;
                }
            }
            index = (index+1)%deck.size();
        }
        return ret;
    }
};

int main()
{
    vector<int> deck = numVectorInput("in.txt");
    Solution s;
    vector<int> ans = s.deckRevealedIncreasing(deck);
    for(int i = 0;i < ans.size();i++)
    {
        cout<<ans[i]<<", ";
    }
    cout<<endl;
    return 0;
}
