#include <iostream>
#include <string>

using namespace std;

// TODO: 补全TimeParser类并实现以下函数
class TimeParser
{
public:
    TimeParser(string s); // 有参构造函数
    int getHour();        // 返回时
    int getMin();         // 返回分
    int getSec();         // 返回秒
    int format();         // 格式检查
private:
    string time;
    int judge;
};

