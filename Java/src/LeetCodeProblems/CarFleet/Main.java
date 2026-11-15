package LeetCodeProblems.CarFleet;

public class Main {
    static void main(String[] args) {
        Solution sol = new Solution();
        int[] array1 = {6, 8};
        int[] array2 = {10, 8, 0, 5, 3};
        int target = 12;
        System.out.println(sol.carFleet(target, array2, array1));
    }
}
