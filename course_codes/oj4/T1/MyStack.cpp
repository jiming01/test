// MyStack.cpp
#include "MyStack.h"

using namespace std;

// 构造函数
MyStack::MyStack()
{
    top = nullptr;
}

// 析构函数，你需要在这里归还额外申请的资源
MyStack::~MyStack()
{
    Node *p = top;
    while (p != nullptr)
    {
        delete p;
        p = p->next;
    }
}

// 字符c入栈
void MyStack::push(char c)
{
    Node *p = new Node;
    p->content = c;
    p->next = top;
    top = p;
}

// 栈顶元素出栈，返回出栈元素（我们没有定义空栈pop操作，测试用例中不会涉及）
char MyStack::pop()
{
    char result = 0;
    result = top->content;
    Node *p = top;
    top = top->next;
    delete p;
    return result;
}

// 返回栈的大小（栈内元素数量）
int MyStack::size()
{
    int result = 0;
    Node *p = top;
    while (p != nullptr)
    {
        result++;
        p = p->next;
    }
    return result;
}

int main()
{
    MyStack s;
    s.push('U');
    s.push('J');
    s.push('N');
    cout << s.size() << endl;
    cout << s.pop() << endl;  // U
    cout << s.pop() << endl;  // J
    cout << s.pop() << endl;  // N
    cout << s.size() << endl; // 0
    return 0;
}