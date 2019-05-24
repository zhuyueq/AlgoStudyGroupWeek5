//faster than 99%

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> q;
        for (auto num : nums) {
            q.push(num);
        }
        int count=k;
        int t;
        while (count>0) {
            t = q.top(); q.pop();
            count--;
        }
        return t;
    }
};