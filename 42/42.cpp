class Solution {
public:
    int trap(vector<int>& height) {
        int leftPointer = 0;
        int rightPointer = height.size() - 1;
        int leftMax = height[0];
        int rightMax = height[height.size() - 1];
        int volume = 0;

        while (leftPointer < rightPointer) {
            if (leftMax < rightMax) {
                leftPointer++;
                volume += max(0,leftMax - height[leftPointer]);
                leftMax = max(leftMax, height[leftPointer]);
            }
            else {
                rightPointer--;
                volume += max(0,rightMax - height[rightPointer]);
                rightMax = max(rightMax, height[rightPointer]);
            }
        }
        return volume;
        
    }
};
