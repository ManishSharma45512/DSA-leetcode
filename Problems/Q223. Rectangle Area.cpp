class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // Calculate areas of both rectangles directly
        int areaA = (ax2 - ax1) * (ay2 - ay1);
        int areaB = (bx2 - bx1) * (by2 - by1);

        // Find overlapping width and height (max(0, ...) handles non-overlapping cases)
        int x_overlap = max(0, min(ax2, bx2) - max(ax1, bx1));
        int y_overlap = max(0, min(ay2, by2) - max(ay1, by1));

        int common = x_overlap * y_overlap;

        return areaA + areaB - common;
    }
};
