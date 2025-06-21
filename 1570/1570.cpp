class SparseVector {
private:
    vector<int> n;
public:
    
    SparseVector(vector<int> &nums) {
        n = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int s = 0;
        for (int i = 0; i < n.size(); i++) {
            s += n[i] * vec.n[i];
        }
        return s;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
