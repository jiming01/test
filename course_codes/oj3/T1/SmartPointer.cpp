#include "SmartPointer.h"

SmartPointer::SmartPointer(const SmartPointer &sptr)
{
    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if (ref_cnt != nullptr)
    {
        *ref_cnt += 1;
    }
}

void SmartPointer::assign(const SmartPointer &sptr)
{
    if (ref_cnt != sptr.ref_cnt)
    {
        if (ref_cnt == nullptr)
        {
            pointer = sptr.pointer;
            ref_cnt = sptr.ref_cnt;
            *ref_cnt += 1;
        }
        else
        {
            if (*ref_cnt > 1)
            {
                *ref_cnt -= 1;
            }
            else if (*ref_cnt == 1)
            {
                this->~SmartPointer();
            }
            pointer = sptr.pointer;
            ref_cnt = sptr.ref_cnt;
            if (ref_cnt != nullptr)
                *ref_cnt += 1;
        }
    }
}

SmartPointer::~SmartPointer()
{
    if (ref_cnt != nullptr && *ref_cnt != 0)
    {
        *ref_cnt -= 1;
        if (*ref_cnt == 0)
        {
            delete pointer;
        }
    }
}

int main()
{
    SmartPointer sp1(new Node(123));
    SmartPointer sp11(new Node(1234));
    // 空指针拷贝构造
    SmartPointer sp2;
    SmartPointer sp3(sp2);
    // 重复析构
    sp3.~SmartPointer();
    sp3.~SmartPointer();
    sp3.assign(sp1);
    sp1.assign(SmartPointer());
}
// int main()
// {
//     SmartPointer sp1(new Node(123));
//     sp1.~SmartPointer();
//     sp1.assign(SmartPointer()); // 测试空指针赋值
//     sp1.assign(*(new SmartPointer(new Node(456))));
// }
// #include<iostream>
// #include<fstream>
// #include"SmartPointer.h"
// using namespace std;

// // 999
// void test1(){
//     SmartPointer sp1(new Node(999));
//     //函数结束，此时node999应该被销毁
// }

// //
// void test2(){
//     SmartPointer sp1(new Node(1));
//     SmartPointer* sp2=new SmartPointer(sp1);
//     //函数结束，sp1被销毁，此时sp2仍持有node1的地址，node1不被销毁
// }

// // 2
// void test3(){
//     SmartPointer* sp1=new SmartPointer(new Node(1));
//     SmartPointer* sp2=new SmartPointer(new Node(2));
//     sp2->assign(*sp1);
//     //node2丢失，被销毁
// }

// // 22 33 11
// void test4(){
//     SmartPointer* sp1=new SmartPointer(new Node(11));
//     SmartPointer* sp2=new SmartPointer(new Node(22));
//     SmartPointer* sp3=new SmartPointer(new Node(33));
//     sp2->assign(*sp1);
//     sp2->assign(*sp3);
//     sp2->assign(*sp1);
//     delete sp2;
//     delete sp3;
//     delete sp1;
// }

// // 2 3 1
// void test5(){
//     SmartPointer sp1(new Node(1));
//     SmartPointer sp2(new Node(2));
//     SmartPointer sp3(new Node(3));
//     sp2.assign(sp1);
//     sp3.assign(sp2);
// }

// // 11 22
// void test6(){
//     SmartPointer* sp1=new SmartPointer(new Node(11));
//     SmartPointer* sp2=new SmartPointer(new Node(22));
//     sp2->assign(*sp2);
//     sp1->assign(*sp2);
//     sp2->assign(*sp1);
//     sp1->~SmartPointer();
//     sp1->assign(*sp1);
//     delete sp1;
//     delete sp2;
// }

// // 123
// void test7(){
//     SmartPointer sp1(new Node(123));
//     sp1.~SmartPointer();
//     sp1.assign(SmartPointer());
//     sp1.assign(*(new SmartPointer(new Node(456))));
// }

// // 123 1234
// void test8(){
//     //鲁棒性
//     SmartPointer sp1(new Node(123));
//     SmartPointer sp11(new Node(1234));
//     //空指针拷贝构造
//     SmartPointer sp2;
//     SmartPointer sp3(sp2);
//     //重复析构
//     sp3.~SmartPointer();
//     sp3.~SmartPointer();

//     sp3.assign(sp1);
//     sp1.assign(SmartPointer());
// }

// int main()
// {
//     ifstream fin("/data/workspace/myshixun/P2/SmartPointer.h");
//     if(fin.is_open()){
//         string line;
//         while(getline(fin, line)){
//             if(line.find("shared_ptr") != string::npos){
//                 cout << "FBI WARNNING: DO NOT USE SHARED_PTR" << endl;
//                 return -1;
//             }
//         }
//     }

//     int n;
//     cin >> n;
//     switch(n)
//     {
//     case 1: {
//         test1();break;
//     }
//     case 2: {
//         test2();break;
//     }
//     case 3: {
//         test3();break;
//     }
//     case 4: {
//         test4();break;
//     }
//     case 5: {
//         test5();break;
//     }
//     case 6: {
//         test6();break;
//     }
//     case 7: {
//         test7();break;
//     }
//     case 8: {
//         test8();break;
//     }
//     default:
//     break;
//     }
//     return 0;
// }