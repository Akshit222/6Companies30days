//Question Link - https://leetcode.com/problems/circle-and-rectangle-overlapping/description/
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xNearest = max(x1, min(xCenter, x2));
        int yNearest = max(y1, min(yCenter, y2));
        int distanceSquared = (xNearest - xCenter) * (xNearest - xCenter) +
                              (yNearest - yCenter) * (yNearest - yCenter);
        return distanceSquared <= radius * radius;
    }
};
