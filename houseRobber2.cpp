class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int> &dp){
        if(i>n) return 0;

        if(dp[i] != -1) return dp[i];

        int steal = nums[i] + solve(nums,i+2,n,dp);
        int skip = solve(nums,i+1,n,dp);

        return dp[i] = max(steal,skip);
    }
    // int tabulation(vector<int>& nums) {
    //     vector<int> dp(nums.size(),0);
    //     dp[0]=0; // total sum of money loated from 0th index to ith index
    //     for(int i=1;i<=n-1;i++) {
    //         int take=nums[i-1]+
    //     }
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        if(n==2) return max(nums[0],nums[1]);
        // Memoization
        // Time complexity, O(N)
        // Space complexity, O(N)
        vector<int> dp1(n+1,-1); // total money from ith index to last index
        int zero_index = solve(nums,0,n-2,dp1);

        vector<int> dp2(n+1,-1);
        int first_index = solve(nums,1,n-1,dp2);
        // return tabulation(nums);
        return max(zero_index,first_index);
    }
};
