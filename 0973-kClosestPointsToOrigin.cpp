/*
We have a list of points on the plane.  Find the K closest points to the origin
(0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique
(except for the order that it is in.)
*/
#include "../LCInput/numInput.h"
#include <algorithm>

class Solution {
public:
    vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
        int len = points.size();
        K = min(K,len);
        vector<pair<int,int> > distList;
        for(int i = 0;i < points.size();i++)
        {
            distList.push_back({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
        }
        sort(distList.begin(),distList.end());
        vector<vector<int> > ret;
        for(int i = 0;i < K;i++)
        {
            ret.push_back(points[distList[i].second]);
        }
        return ret;
    }
};

int main()
{
    ifstream f;
    f.open("in.txt");
    string str;
    getline(f,str);
    vector<vector<int> > points;
    vector<int> num;
    bool isNeg = false;
    for(int i = 1;i < str.size();i++)
    {
        if(str[i] == '[')
        {
            i++;
            while(str[i] != ']')
            {
                if(str[i] == '-')
                {
                    isNeg = true;
                    i++;
                }
                int tmp = 0;
                while(isNum(str[i]))
                {
                    tmp *= 10;
                    tmp += str[i] - '0';
                    i++;
                }
                if(isNeg)
                {
                    tmp *= -1;
                    isNeg = false;
                }
                num.push_back(tmp);
                if(str[i] != ']')
                {
                    i++;
                }
            }
            points.push_back(num);
            num.clear();
        }
    }
    getline(f,str);
    int K = 0;
    for(int i = 0;i < str.size();i++)
    {
        K *= 10;
        K += str[i]-'0';
    }
    Solution s;
    numVectorVectorOutput(s.kClosest(points,K));
    return 0;
}
