package LeetCodeProblems.TwoSum;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] array = new int[2];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int need = target - nums[i];
            if (map.containsKey(need)) {
                array[0] = map.get(need);
                array[1] = i;
                break;
            }
            map.put(nums[i], i);
        }
        return array;
        

    }
}
