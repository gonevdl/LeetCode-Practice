#include<iostream>
using namespace std;

/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4] 输出：[1,1,2,3,4,4]
示例 2：
输入：l1 = [], l2 = []输出：[]
示例 3：
输入：l1 = [], l2 = [0]输出：[0]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 class Solution {
 public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if (l1 == nullptr && l2 == nullptr) {
             return nullptr;
         }
         ListNode* result = new ListNode;
         ListNode* p1 = l1;
         ListNode* p2 = l2;
         ListNode* p = result;
         while (p1 != nullptr && p2 != nullptr) {
             ListNode* q = new ListNode;
             if (p1->val <= p2->val) {
                 q->val = p1->val;
                 p1 = p1->next;
             }
             else {
                 q->val = p2->val;
                 p2 = p2->next;
             }
             p->next = q;
             p = q;
         }
         while (p1 != nullptr) {
             ListNode* q = new ListNode;
             q->val = p1->val;
             p1 = p1->next;
             p->next = q;
             p = q;
         }
         while (p2 != nullptr) {
             ListNode* q = new ListNode;
             q->val = p2->val;
             p2 = p2->next;
             p->next = q;
             p = q;
         }
         ListNode* result1 = result->next;
         return result1;
     }
 };


int main() {
    Solution S;
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(1);
    ListNode* l1p = l1;
    ListNode* l2p = l2;
    for (int i = 0; i < 3; i++) {
        ListNode* l1q = new ListNode;
        l1p->next = l1q;
        l1p = l1q;

        ListNode* l2q = new ListNode;
        l2p->next = l2q;
        l2p = l2q;

        l1p->val = l2p->val = i + 1;
    }

    ListNode* p1 = S.mergeTwoLists(l1, l2);
    while (p1 != nullptr) {
        cout << p1->val << " ";
        p1=p1->next;
    }
}