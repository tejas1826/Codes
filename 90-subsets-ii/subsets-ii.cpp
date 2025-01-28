class Solution {
public:
    void subset2(int idx, vector<int>& ds, vector<vector<int>>& ans,
                 vector<int>& nums) {
        ans.push_back(ds); // Add the current subset to the result \U0001f31f

        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates to avoid redundant subsets \U0001f6ab
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            ds.push_back(nums[i]); // Include the current number ➕
            subset2(i + 1, ds, ans, nums); // Recurse to the next level \U0001f504
            ds.pop_back(); // Backtrack by removing the current number ⬅️
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to bring duplicates together \U0001f5c2️
        vector<vector<int>> ans; // Store the unique subsets \U0001f4be
        vector<int> ds; // Temporary list to build subsets \U0001f6e0️
        subset2(0, ds, ans, nums); // Start the recursion \U0001f680
        return ans; // Return the result ✅
    }
};