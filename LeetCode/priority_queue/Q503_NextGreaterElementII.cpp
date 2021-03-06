class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int len = nums.size();
        vector<int> res(len, -1);

        for (int i = 0; i < 2 * len; ++i) {
            while (!s.empty() && nums[s.top()] < nums[i % len]) {
                res[s.top()] = nums[i % len];
                s.pop();
            }

            s.push(i % len);
        }

        return res;
    }
};