#include <iostream>
#include <functional>
using namespace std;
//保存普通函数
void func1(int a)
{
     cout << a << endl;
}
//保存成员函数
class A{
public:
    A(string name) : name_(name){}
    void func3(int i) const {cout <<name_ << ", " << i << endl;}
private:
    string name_;
};
int main()
{
    cout << "main1 -----------------" << endl;
    //1. 保存普通函数
    std::function<void(int a)> func1_;
    func1_ = func1;
    func1_(2);   //2

     cout << "\n\nmain2 -----------------" << endl;
    //2. 保存lambda表达式
    std::function<void()> func2_ = [](){cout << "hello lambda" << endl;};
    func2_();  //hello world

    cout << "\n\nmain3 -----------------" << endl;

    //3 保存成员函数
    std::function<void(const A&,int)> func3_ = &A::func3;
    A a("darren");
    func3_(a, 1);

    return 0;
}
