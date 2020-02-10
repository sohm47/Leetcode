class Solution {
    double calcArea(vector<int> &A, vector<int> &B, vector<int> &C) {
        return 0.5 * fabs((A[0]*B[1] + B[0]*C[1] + C[0]*A[1]-A[1]*B[0] - B[1]*C[0] - C[1]*A[0]));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        if(points.size()<3)
            return 0;
        
        double largestArea = 0;
        for(int i=0; i<points.size()-2; i++) {
            for(int j=i+1; j<points.size()-1; j++) {
                for(int k=j+1; k<points.size(); k++) {
                    double area = calcArea(points[i], points[j], points[k]);
                    largestArea = max(largestArea, area);
                }
            }
        }
        
        return largestArea;
    }
};
