#include<iostream>
using namespace std;
/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
示例 1：
输入：head = [1,2,3,4,5]   输出：[5,4,3,2,1]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* p = head;
        ListNode* q = head->next;
        while (p != nullptr && q->next != nullptr) {
            ListNode* r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        q->next = p;
        p = q;
        head->next = nullptr;
        return p;
    }
};

int main() {
    Solution S;
    ListNode* list = new ListNode(1);
    ListNode* p = list;
    for (int i = 0; i < 4; i++) {
        ListNode* q = new ListNode(i + 2);
        p->next = q;
        p = q;
    }
    ListNode* q = S.reverseList(list);
    while (q != nullptr) {
        cout << q->val << " ";
        q = q->next;
    }
    cout << endl;

}