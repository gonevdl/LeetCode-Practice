#include<iostream>
#include<map>
using namespace std;
/*
给定一个链表，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
如果链表中存在环，则返回 true 。 否则，返回 false 。
进阶：你能用 O(1)（即，常量）内存解决此问题吗？
示例 1：
输入：head = [3,2,0,-4], pos = 1 输出：true
解释：链表中有一个环，其尾部连接到第二个节点。 
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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