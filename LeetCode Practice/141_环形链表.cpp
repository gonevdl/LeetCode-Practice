#include<iostream>
#include<map>
using namespace std;
/*
����һ�������ж��������Ƿ��л���
�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� 
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
��� pos �� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
��������д��ڻ����򷵻� true �� ���򣬷��� false ��
���ף������� O(1)�������������ڴ�����������
ʾ�� 1��
���룺head = [3,2,0,-4], pos = 1 �����true
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣 
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/linked-list-cycle
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* p = head;
        map<ListNode*, int> position;
        while (p != NULL) {
            if (position.find(p) == position.end()) {
                position.insert(make_pair(p, p->val));
                p = p->next;
            }
            else return true;
        }
        return false;
    }
};
class Solution1 {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

int main() {
    Solution S;
    Solution1 S1;
    ListNode* list = new ListNode(3);
    ListNode* p = list;
    for (int i = 0; i < 3; i++) {
        ListNode* q = new ListNode(i);
        p->next = q;
        p = q;
    }
    p->next = list->next;
    ListNode* it = list;
    int count = 0;
    while (it != nullptr) {
        cout << it->val << " ";
        it = it->next;
        count++;
        if (count == 15) break;
    }
    cout << endl;
    cout << "sizeof list:" << sizeof(list) << endl;
    bool flag = S.hasCycle(list);
    cout << flag << endl;
    cout << "sizeof listnode:" << sizeof(ListNode) << endl;
    cout << S1.hasCycle(list);
}