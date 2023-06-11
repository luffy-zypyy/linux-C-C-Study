//1-5-future
#include <iostream>
#include <future>
#include <thread>
using namespace std;

int find_result_to_add()
{
//    std::this_thread::sleep_for(std::chrono::seconds(2)); // 用来测试异步延迟的影响
    std::cout << "find_result_to_add" << std::endl;
    return 1 + 1;
}

int find_result_to_add2(int a, int b)
{
//    std::this_thread::sleep_for(std::chrono::seconds(5)); // 用来测试异步延迟的影响
    return a + b;
}

void do_other_things()
{
    std::cout << "do_other_things" << std::endl;
//    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main()
{
    // 以下三种future的写法都是正确的，推荐使用第三种方式
    std::future<int> result = std::async(find_result_to_add);
//    std::future<decltype (find_result_to_add())> result = std::async(find_result_to_add); //通过推导的方式
//    auto result = std::async(find_result_to_add);  // 推荐的写法
    do_other_things();
    // result.get()是阻塞等待结果
    std::cout << "result: " << result.get() << std::endl;  // 延迟是否有影响？

//    std::future<decltype (find_result_to_add2(int, int))> result2 = std::async(find_result_to_add2, 10, 20); //错误
//  当函数中有参数的话，使用decltype (find_result_to_add2(0, 0))这种方式才是正确的，即必须要把参数实例化才能推导出来
    std::future<decltype (find_result_to_add2(0, 0))> result2 = std::async(find_result_to_add2, 10, 20);
    std::cout << "result2: " << result2.get() << std::endl;  // 延迟是否有影响？
//    std::cout << "main finish" << endl;
    return 0;
}
