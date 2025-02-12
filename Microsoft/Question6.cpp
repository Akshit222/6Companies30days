//Qs Link - https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/submissions/1502616127/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n/2; i++){
            steps += nums[n-1-i] - nums[i]; //Adding difference
        }
        return steps;
    }
};
