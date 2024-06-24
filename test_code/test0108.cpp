#include <iostream>

int main() {
    int value = 10;
    int val2 = 50;

    const int* ptr = &value;  // ptr 是一个常量指针

    std::cout << "Value: " << *ptr << std::endl;  // 输出值

    // *ptr = 20;  // 错误：不能通过常量指针修改指向的值
    value = 20;  // 可以直接修改变量本身
    std::cout << "New value1: " << *ptr << std::endl;

    ptr = &val2;
    std::cout << "New value2: " << *ptr << std::endl;

    system("pause");
    return 0;
}