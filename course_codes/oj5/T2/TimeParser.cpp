#include "TimeParser.h"

using namespace std;

TimeParser::TimeParser(string s)
{
    time = s;
    judge = 0;
    /* TODO */
}

int TimeParser::getHour()
{
    /* TODO */
    string h1;
    int h2;
    judge = format();
    if (judge == -1)
    {
        return -1;
    }
    h1 = time.substr(0, 2);
    h2 = stoi(h1, nullptr, 10);
    if (h2 < 0 || h2 > 23)
    {
        judge = -1;
        return -1;
    }
    return h2;
}

int TimeParser::getMin()
{
    /* TODO */
    string m1;
    int m2;
    if (judge == -1)
    {
        return -1;
    }
    m1 = time.substr(3, 2);
    m2 = stoi(m1, nullptr, 10);
    if (m2 < 0 || m2 > 59)
    {
        return -1;
    }
    return m2;
}

int TimeParser::getSec()
{
    /* TODO */
    string s1;
    int s2;
    if (judge == -1)
    {
        return -1;
    }
    s1 = time.substr(6, 2);
    s2 = stoi(s1, nullptr, 10);
    if (s2 < 0 || s2 > 59)
    {
        return -1;
    }
    return s2;
}

int TimeParser::format()
{
    string f1, f2;
    f1 = time.substr(2, 1);
    f2 = time.substr(5, 1);
    if (f1 != ":" || f2 != ":")
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    std::string s;
    std::cin >> s;
    TimeParser tp(s);
    std::cout << tp.getHour() << ' ';
    std::cout << tp.getMin() << ' ';
    std::cout << tp.getSec() << endl;
    return 0;
}