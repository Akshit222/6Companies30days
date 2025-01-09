//Qs Link - https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/submissions/1502614064/
class Solution {
public:
    vector<int> v;
    vector<vector<int>> rects;
    int cntPoints(vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
    
    Solution(vector<vector<int>> rect) {
        rects = rect;
        int totalPts=0;
        for (auto r: rects) {
            totalPts+=cntPoints(r);
            v.push_back(totalPts);
        }
    }
    
    vector<int> pick() {
        int pt = rand() % v.back(); 

        int idx = upper_bound(v.begin(), v.end(), pt) - v.begin();

        vector<int> r = rects[idx];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];  
        return { x, y };
    }
};
