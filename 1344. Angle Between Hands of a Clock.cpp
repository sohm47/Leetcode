class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = minutes/60.0;
        double mindegs = angle*360.0;
        hour = hour%12;
        double hdegs = (hour/12.0)*360.0 + angle*30.0;
        return min(abs(hdegs-mindegs), 360-abs(hdegs-mindegs));
    }
};
