class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int initialState = 0;
        for (int i = 0; i < n; ++i) initialState += i * nums[i];

        int ans = initialState;
        for (int i = n - 1; i > 0; --i) {
            initialState += (sum - (n * nums[i]));
            ans = max(ans, initialState);
        }
        return ans;
    }
};