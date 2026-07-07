class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;

        
        double angle = ((11.0 * minutes) / 2.0) - (30.0 * hour);

        
        if (angle < 0) angle = -angle;

        
        if (angle > 180) return 360.0 - angle;

        return angle;
    }
};
