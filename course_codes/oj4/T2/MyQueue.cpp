// MyQueue.cpp
#include "MyQueue.h"
using namespace std;
MyQueue::MyQueue()
{
    // TODO
}

// 元素从队尾入队
void MyQueue::push(char c)
{
    // TODO
    q1.push(c);
}

// 队首元素出队，返回出队的元素（我们没有定义空队列pop操作，测试用例中不会涉及）
char MyQueue::pop()
{
    char result;
    // TODO
    while (q1.size() != 0)
    {
        q2.push(q1.pop());
    }
    result = q2.pop();
    while (q2.size() != 0)
    {
        q1.push(q2.pop());
    }
    return result;
}

// 返回队列的大小（队列内元素的个数）
int MyQueue::size()
{
    int result;
    // TODO
    result = q1.size();
    return result;
}

int main()
{
    MyQueue s;
    s.push('N');
    s.push('J');
    s.push('U');
    cout << s.size() << endl; // 3
    cout << s.pop() << endl;  // U
    cout << s.pop() << endl;  // J
    cout << s.pop() << endl;  // N
    cout << s.size() << endl; // 0
    return 0;
}