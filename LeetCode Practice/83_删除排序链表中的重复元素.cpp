#include<iostream>

using namespace std;
/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
返回同样按升序排列的结果链表。
示例 1：
输入：head = [1,1,2]  输出：[1,2]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        if (p == nullptr || p->next == nullptr) return head;
        while (p != nullptr && p->next != nullptr) {
            if (p->val == p->next->val) {
                if (p->next->next != nullptr) {
                    ListNode* q = p->next;
                    ListNode* t = p->next->next;
                    delete q;
                    q = nullptr;
                    p->next = t;
                }
                else {
                    ListNode* q = p->next;
                    delete q;
                    q = nullptr;
                    p->next = nullptr;
                }
            }
            else {
                p = p->next;
            }
        }
        return head;
    }
};

int main() {
    Solution S;
    ListNode* list = new ListNode(1);
    ListNode* p = list;
    for (int i = 0; i < 4; i++) {
        ListNode* q = new ListNode((i + 4)/2);
        p->next = q;
        p = q;
    }
    ListNode* q = list;
    while (q != nullptr) {
        cout << q->val << " ";
        q = q->next;
    }
    ListNode* q1 = S.deleteDuplicates(list);
    while (q1 != nullptr) {
        cout << q1->val << " ";
        q1 = q1->next;
    }
    cout << endl;

}