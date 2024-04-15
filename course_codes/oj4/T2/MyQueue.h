// MyQueue.h
#include <iostream>
#include "MyStack.h"

class MyQueue
{
private:
    MyStack q1, q2;
    // TODO:
    // 你可以用任何数据结构实现“队列”
    // 我们鼓励你使用MyStack类：请思考，如何维护两个栈结构，以满足队列结构的要求？
    // 我们帮你引用了头文件“MyStack100.h”，这份头文件中含有MyStack类的满分实现，你可以放心使用
    // 你也可以用其他方式实现队列，比如数组或链表。
public:
    MyQueue();         // 构造函数
                       // 我们对MyQueue的析构函数没有做具体要求，你可以按需自行定义实现。
    void push(char c); // 元素从队尾入队
    char pop();        // 队首元素出队，返回出队的元素（我们没有定义空队列pop操作，测试用例中不会涉及）
    int size();        // 返回队列的大小

    // 请注意，以上函数的函数体请你在MyQueue.cpp中实现！
};
// using namespace std;

// // 构造函数
// MyStack::MyStack()
// {
//     top = nullptr;
// }

// // 析构函数，你需要在这里归还额外申请的资源
// MyStack::~MyStack()
// {
//     Node *p = top;
//     while (p != nullptr)
//     {
//         delete p;
//         p = p->next;
//     }
// }

// // 字符c入栈
// void MyStack::push(char c)
// {
//     Node *p = new Node;
//     p->content = c;
//     p->next = top;
//     top = p;
// }

// // 栈顶元素出栈，返回出栈元素（我们没有定义空栈pop操作，测试用例中不会涉及）
// char MyStack::pop()
// {
//     char result = 0;
//     result = top->content;
//     Node *p = top;
//     top = top->next;
//     delete p;
//     return result;
// }

// // 返回栈的大小（栈内元素数量）
// int MyStack::size()
// {
//     int result = 0;
//     Node *p = top;
//     while (p != nullptr)
//     {
//         result++;
//         p = p->next;
//     }
//     return result;
// }
