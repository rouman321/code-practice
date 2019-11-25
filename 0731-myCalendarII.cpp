/*
LeetCode 731. My Calendar II
medium
time:	184ms
space:	34.7mb
*/
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        auto l = m.find(start);
        if(l==m.end()){
            m[start] = 0;
        }
        ++m[start];
        l = m.find(start);
        int cnt = 0;
        for(auto i = m.begin();i !=m.end();++i){
            if(i->first>=end){
                break;
            }
            cnt += i->second;
            if(cnt>=3){
                --m[start];
                return false;
            }
        }
        if(m.find(end)==m.end()){
            m[end] = 0;
        }
        --m[end];
        return true;
    }
private:
    map<int,int> m;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */