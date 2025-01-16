//Qs Link - https://leetcode.com/problems/count-number-of-nice-subarrays/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        auto atmostK = [&](int k){
            int count =0,left=0,oddcount=0;
            for (int right=0;right<nums.size();++right){
                 if(nums[right]%2!=0)oddcount++;
                 while(oddcount>k){
                    if(nums[left]%2!=0)oddcount--;
                    left++;
                 }
                 count+=right-left+1;

            }
            return count;
        };
        return atmostK(k)-atmostK(k-1);
    }
};
