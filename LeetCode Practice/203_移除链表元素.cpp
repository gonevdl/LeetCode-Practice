#include<iostream>
using namespace std;

/*
����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��

���룺head = [1,2,6,3,4,5,6], val = 6
�����[1,2,3,4,5]
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode* p = head;
        ListNode* q = p->next;
        while (q!= nullptr) {
            if(p->val)
            if (q->val == val) {
                if (q->next == nullptr) {
                    p->next = nullptr;
                    break;
                }
                else {
                    p->next = q->next;
                    q = q->next;
                }
            }
            else {
                p = p->next;
                q=q->next;
            }
        }
        if (head->val == val) {
            head = head->next;
            return head;
        }
        return head;
    }
};

int main() {
    Solution S;
    ListNode* list = new ListNode(3);
    ListNode* p = list;
    for (int i = 0; i < 10; i++) {
        ListNode* q = new ListNode(4);
        p->next = q;
        p = q;
    }
    p = list;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    int val = 3;
    ListNode* result = S.removeElements(list, val);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
}