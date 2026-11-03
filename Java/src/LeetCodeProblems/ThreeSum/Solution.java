package LeetCodeProblems.ThreeSum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int current = i + 1;
            int end = nums.length - 1;
            while (current < end) {
                int sum = nums[i] + nums[current] + nums[end];

                if (sum == 0) {
                    result.add(Arrays.asList(nums[i], nums[current], nums[end]));
                    while (current < end && nums[current] == nums[current + 1]) {
                        current++;
                    }
                    while (current < end && nums[end] == nums[end - 1]) {
                        end--;
                    }
                    current++;
                    end--;
                } else if (sum < 0) {
                    current++;
                } else {
                    end--;
                }
            }
        }

        return result;
    }
}