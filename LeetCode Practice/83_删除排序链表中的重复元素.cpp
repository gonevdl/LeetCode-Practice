#include<iostream>

using namespace std;
/*
����һ�����������е�����������������ͷ�ڵ� head ������ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ��
����ͬ�����������еĽ������
ʾ�� 1��
���룺head = [1,1,2]  �����[1,2]
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
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