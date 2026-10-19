package LeetCodeProblems.ContainerWithMostWater;

import static java.lang.Math.min;

class Solution {
    public int maxArea(int[] height) {
        int max = -1;
        int left = 0;
        int right = height.length - 1;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            if (area > max) max = area;
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
    }
}