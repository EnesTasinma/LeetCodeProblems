package LeetCodeProblems.MergeTwoSortedLinks;

public class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null && list2 == null) return null;
        else if (list1 == null && list2 != null) return list2;
        else if (list1 != null && list2 == null) return list1;

        ListNode returnListNode = new ListNode();
        ListNode returnListSecond = returnListNode;

        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                returnListNode.next = list1;
                returnListNode = returnListNode.next;
                list1 = list1.next;
            } else {
                returnListNode.next = list2;
                returnListNode = returnListNode.next;
                list2 = list2.next;
            }
        }


        while (list1 != null) {
            returnListNode.next = list1;
            returnListNode = returnListNode.next;
            list1 = list1.next;
        }

        while (list2 != null) {
            returnListNode.next = list2;
            returnListNode = returnListNode.next;
            list2 = list2.next;
        }


        return returnListSecond.next;

    }
}
