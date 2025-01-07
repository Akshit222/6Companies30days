//Question Links - https://leetcode.com/problems/russian-doll-envelopes/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        vector<int> heights;
        for (auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }
        vector<int> lis;
        for (int h : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) {
                lis.push_back(h);
            } else {
                *it = h;
            }
        }
        return lis.size();
    }
};
