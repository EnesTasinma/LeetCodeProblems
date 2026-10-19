package LeetCodeProblems.MergeTwoSortedLinks;

public class Main {
    public static void main(String[] args) {
        ListNode l00 = new ListNode(1);
        ListNode l01 = new ListNode(2);
        ListNode l10 = new ListNode(4);

        ListNode l2 = new ListNode(1);
        ListNode l2_1 = new ListNode(3);
        ListNode l2_2 = new ListNode(4);

        l01.next = l10;
        l00.next = l01;

        l2_1.next = l2_2;
        l2.next = l2_1;

        Solution solution = new Solution();

        solution.mergeTwoLists(l00, l2);

        System.out.println(solution.mergeTwoLists(l00, l2).val);
    }
}
