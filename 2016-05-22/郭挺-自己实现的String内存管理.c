#include<iostream>
#include<string>
using namespace std;

class Pstring
{
    friend void swap(Pstring &a, Pstring &b);
    string *str;
public:
    Pstring(string *s= nullptr) :str(s) {}//默认构造函数，可与new结合使用
    explicit Pstring(string s) :str(new string(std::move(s))) {}//使用string的移动初始化
    Pstring(Pstring &s) :str(new string(*s.str)) {}//拷贝构造函数
    Pstring(Pstring &&s)noexcept;//移动构造函数
    Pstring &operator=(Pstring s) noexcept;//使用拷贝并交换技术
    ~Pstring() { delete str; }//析构函数
    
    //重载运算符
    string &operator*()
    {
        return *str;
    }
    string *operator->()
    {
        return str;
    }
    //定义类型转化运算符
    operator string* () const
    {
        string *s = str;
        return s;
    }
};
void swap(Pstring &a,Pstring &b)
{
    using namespace std;
    swap(a.str, b.str);
}
Pstring::Pstring(Pstring &&s)noexcept
{
    str = s.str;
}
Pstring &Pstring::operator=(Pstring s) noexcept
{
    swap(*this,s);
    return *this;
}
int main()
{
    //示例代码--GT
    //初始化：
    Pstring p("这是一个测试");//直接使用字面值常量进行初始化
    Pstring p2 = new string("这是一个测试2");//与new结合使用
    Pstring p3 = p2;//使用一个Pstring来初始化Pstring
    Pstring p4;//创建空Pstring
    
    //打印
    cout << *p << *p2 << endl;//进行解引用操作
    cout << *p3 << " size:" << p3->size() << endl;//等价于（*p3）.size()
    
    //赋值
    p4 = p;//使用一个Pstring来对Pstring赋值
    cout << *p4 << endl;
    p4 = new string("end");//也可使用new来赋值，这时Pstring管理的string会被释放
    cout << *p4 << endl;
    return 0;
