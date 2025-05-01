class Solution {
public:
    // helper to compute squared distance between two points
    static int dist2(const vector<int>& a, const vector<int>& b) {
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return dx*dx + dy*dy;
    }
    bool checkDistances(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (dist2(p1, p2) == dist2(p3, p4) && dist2(p1, p4) == dist2(p2, p3) && dist2(p1, p2) == dist2(p2, p3) && dist2(p2, p3)>0) {
            cout << "Distances checked" << endl;
            return true;
        }
        return false;
    }

    bool slopeInfinity(vector<int>& p1, vector<int>& p2) {
        return p1[0] == p2[0];
    }


    float getSlope(vector<int>& p1, vector<int>& p2) {
        return float(p1[1] - p2[1]) / float(p1[0] - p2[0]);
    }


    bool checkParallel(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return p2[0] - p1[0] == p3[0] - p4[0] && p2[1] - p1[1] == p3[1] - p4[1];
    }

    bool checkPerpendicular(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return (p2[1] - p1[1]) * (p2[1] - p3[1]) == (p2[0] - p1[0]) * (p3[0] - p2[0]);
        //p2[0] - p1[0] == p3[1] - p2[1] && p2[1] - p1[1] == p3[0] - p2[0];
    }

    bool checkSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        cout << checkParallel(p1, p2, p3, p4) << endl;
        cout << checkParallel(p2, p3, p4, p1) << endl;
        cout << checkPerpendicular(p1, p2, p3, p4);
        return checkDistances(p1, p2, p3, p4) && checkParallel(p1, p2, p3, p4) && checkParallel(p2, p3, p4, p1) && checkPerpendicular(p1, p2, p3, p4);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return checkSquare(p1, p3, p2, p4) ||checkSquare(p1, p2, p3, p4) ||checkSquare(p1, p2, p4, p3) ||checkSquare(p1, p3, p2, p4);
    }//
};
