#include <iostream>
#include <zero_threadpool.h>
using namespace std;

void func0()
{
    cout << "func0()" << endl;
}

void func1(int a)
{
    cout << "func1() a=" << a << endl;
}

void func2(int a, string b)
{
    cout << "func2() a=" << a << ", b=" << b<< endl;
}


void test1() // 简单测试线程池
{
    ZERO_ThreadPool threadpool;       // 封装一个线程池                                  
    threadpool.init(1);               // 设置线程的数量
    threadpool.start(); // 创建线程，启动线程池
    // 假如要执行的任务
    threadpool.exec(1000,func0);    // 1000是超时的意思，目前没有起作用
    threadpool.exec(func1, 10);     // 插入任务
    threadpool.exec(func2, 20, "darren");   //插入任务
    threadpool.waitForAllDone();    // 等待任务都执行完退出运行函数，比如插入1000个任务，等1000个任务执行完毕才退出
    threadpool.stop();  // 这里才是真正的退出
}

int func1_future(int a)
{
    cout << "func1() a=" << a << endl;
    return a;
}

string func2_future(int a, string b)
{
    cout << "func1() a=" << a << ", b=" << b<< endl;
    return b;
}

void test2() // 测试任务函数返回值
{
    ZERO_ThreadPool threadpool;
    threadpool.init(1);
    threadpool.start(); // 启动线程池
    // 假如要执行的任务
    std::future<decltype (func1_future(0))> result1 = threadpool.exec(func1_future, 10);
    std::future<string> result2 = threadpool.exec(func2_future, 20, "darren");
//  auto result2 = threadpool.exec(func2_future, 20, "darren");

    std::cout << "result1: " << result1.get() << std::endl;
    std::cout << "result2: " << result2.get() << std::endl;
    threadpool.waitForAllDone();
    threadpool.stop();
}

class Test
{
public:
    int test(int i){
        cout << _name << ", i = " << i << endl;
        return i;
    }
    void setName(string name){
        _name = name;
    }
    string _name;
};

void test3() // 测试类对象函数的绑定
{
    ZERO_ThreadPool threadpool;
    threadpool.init(1);
    threadpool.start(); // 启动线程池
    Test t1;
    Test t2;
    t1.setName("Test1");
    t2.setName("Test2");
    auto f1 = threadpool.exec(std::bind(&Test::test, &t1, std::placeholders::_1), 10);
    auto f2 = threadpool.exec(std::bind(&Test::test, &t2, std::placeholders::_1), 20);
    threadpool.waitForAllDone();
    cout << "t1 " << f1.get() << endl;
    cout << "t2 " << f2.get() << endl;
}
int main()
{
//    test1(); // 简单测试线程池
//    test2(); // 测试任务函数返回值
    test3(); // 测试类对象函数的绑定
    cout << "main finish!" << endl;
    return 0;
}
