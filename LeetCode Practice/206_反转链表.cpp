#include<iostream>
using namespace std;
/*
���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
ʾ�� 1��
���룺head = [1,2,3,4,5]   �����[5,4,3,2,1]
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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