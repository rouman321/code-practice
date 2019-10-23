/*
LeetCode 399. Evaluate Division
medium
time:	57.84%
space:	100%
*/
class Solution {
public:
    int find(int p, vector<int>& parent, vector<double> dist, double& d){
        d = 1.0;
        while(parent[p]!=p){
            d *= dist[p];
            p = parent[p];
        }
        return p;
    }
    
    void update(int p1, int p2, vector<int>& parent, vector<double>& dist, double d){
        int n1 = parent[p1];
        int n2 = parent[p2];
        if(n1==n2){
            return;
        }
        if(n1<n2){
            dist[p2] = dist[p1]/d;
            parent[p2] = n1;
        }
        else{
            dist[p1] = dist[p2]*d;
            parent[p1] = n2;
        }
        // cout<<dist[p1]<<" "<<dist[p2]<<endl;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> m;
        vector<int> node;
        vector<int> parent;
        vector<double> dist;
        int pos = 0;
        for(int i = 0;i < equations.size();i++){
            int p1 = 0;
            int p2 = 0;
            if(m.find(equations[i][0])==m.end()){
                m[equations[i][0]] = pos;
                node.push_back(pos);
                parent.push_back(pos);
                dist.push_back(1.0);
                p1 = pos;
                pos++;
            }
            else{
                p1 = m[equations[i][0]];
            }
            if(m.find(equations[i][1])==m.end()){
                m[equations[i][1]] = pos;
                node.push_back(pos);
                parent.push_back(pos);
                dist.push_back(1.0);
                p2 = pos;
                pos++;
            }
            else{
                p2 = m[equations[i][1]];
            }
            update(p1,p2,parent,dist,values[i]);
        }
        vector<double> ret;
        for(int i = 0;i < queries.size();i++){
            if(m.find(queries[i][0])==m.end()||m.find(queries[i][1])==m.end()){
                ret.push_back(-1);
            }
            else{
                double d1 = 1.0;
                double d2 = 1.0;
                int p1 = find(m[queries[i][0]],parent,dist,d1);
                int p2 = find(m[queries[i][1]],parent,dist,d2);
                if(p1!=p2){
                    ret.push_back(-1);
                }
                else{
                    ret.push_back(d1/d2);
                }
            }
        }
        return ret;
    }
};