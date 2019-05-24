class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return (a[0]*a[0]+a[1]*a[1])>(b[0]*b[0]+b[1]*b[1]);
        };
        
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> q(cmp);
        
        for (auto point : points) {
            q.push(point);
        }
        int count=K;
        vector<int> t;
        vector<vector<int>> ans;
        while (count>0) {
            t = q.top(); q.pop();
            ans.push_back(t);
            count--;
        }
        return ans;
    }
};

//faster than 42%