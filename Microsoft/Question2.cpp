//Quesstion Link - https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle;
        for (int i = 1; i <= n; i++) {
            circle.push_back(i);
        }
        int startIndex = 0;
        while (circle.size() > 1) {
            int removalIndex = (startIndex + k - 1) % circle.size();
            circle.erase(circle.begin() + removalIndex);
            startIndex = removalIndex;
        }
        return circle.front();
    }
};
