#include<iostream>
#include<stack>
using namespace std;
/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
实现 MyQueue 类：
void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：
你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。 
进阶：
你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，
即使其中一个操作可能花费较长时间。
示例：
输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]
解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class MyQueue {
public:
    MyQueue() {
        m_Size = 0;
    }
    //在队列的末尾添加元素
    void push(int x) {
        m_Stack1.push(x);
        m_Size++;
    }
    //从队列的开头移除并返回元素
    int pop() {
        stack<int> temp;
        while (!m_Stack1.empty()) {
            temp.push(m_Stack1.top());
            m_Stack1.pop();
        }
        int result = temp.top();
        temp.pop();
        while (!temp.empty()) {
            m_Stack1.push(temp.top());
            temp.pop();
        }
        return result;
    }
    //返回队列开头的元素
    int peek() {
        stack<int> temp;
        while (!m_Stack1.empty()) {
            temp.push(m_Stack1.top());
            m_Stack1.pop();
        }
        int result = temp.top();
        while (!temp.empty()) {
            m_Stack1.push(temp.top());
            temp.pop();
        }
        return result;
    }
    //队列为空返回true
    bool empty() {
        return m_Stack1.empty();
    }
private:
    //这个栈正着放元素
    stack<int> m_Stack1;
    int m_Size;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_3 = obj->peek();
    cout << param_3 << endl;
    int param_2 = obj->pop();
    cout << param_2 << endl;
    bool param_4 = obj->empty();
    cout<<param_4<<endl;
}