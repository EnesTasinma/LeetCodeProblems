package LeetCodeProblems.RomanToInteger;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int romanToInt(String s) {
//        Map<Character, Integer> values = new HashMap<>();
//        values.put('I', 1);
//        values.put('V', 5);
//        values.put('X', 10);
//        values.put('L', 50);
//        values.put('C', 100);
//        values.put('D', 500);
//        values.put('M', 1000);

//        int length = s.length();
//        int total = 0;
////      int lastAdded = values.get(s.charAt(0));
//        for (int i = 0; i < length; i++) {
//            if (lastAdded < values.get(s.charAt(i))) {
//                total -= 2 * lastAdded;
//            }
//            total += values.get(s.charAt(i));
//            lastAdded = values.get(s.charAt(i));
//        }
//        return total;

        int length = s.length();
        int total = 0;
        for (int i = 0; i < length; i++) {
            int current = getVal(s.charAt(i));

            if (i < length - 1 && current < getVal(s.charAt(i + 1))) {
                total -= current;
            } else {
                total += current;
            }

        }
        return total;
    }

    // Using a switch-case is faster than Map lookup in Java
    private int getVal(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
}
