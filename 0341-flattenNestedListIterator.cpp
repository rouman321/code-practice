/*
LeetCode 341. Flatten Nested List Iterator
medium
time:	63.77%
space:	63.64%
*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        list.clear();
        cur = 0;
        stack<pair<NestedInteger,int>> s;
        for(int i = 0;i < nestedList.size();i++){
            if(nestedList[i].isInteger()){
                list.push_back(nestedList[i].getInteger());
            }
            else{
                s.push(make_pair(nestedList[i],0));
                while(!s.empty()){
                    vector<NestedInteger> tmp = s.top().first.getList();
                    int j = s.top().second;
                    while(j<tmp.size()&&tmp[j].isInteger()){
                        list.push_back(tmp[j].getInteger());
                        j++;
                    }
                    if(j>=tmp.size()){
                        s.pop();
                    }
                    else{
                        s.top().second = j+1;
                        s.push(make_pair(tmp[j],0));
                    }
                }
            }
        }
    }

    int next() {
        int ret = list[cur];
        cur++;
        return ret;
    }

    bool hasNext() {
        return cur<list.size();
    }
    
private:
    int cur;
    vector<int> list;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */