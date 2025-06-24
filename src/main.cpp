#include <iostream>

// 声明测试函数
void test_put_and_get();
void test_overwrite();
void test_remove();
void test_keySet_valSet();
void test_Pairset();
void test_stack_push_pop();
void test_stack_tovector();
void test_stack_exceptions();

int main() {
    test_put_and_get();
    test_overwrite();
    test_remove();
    test_keySet_valSet();
    test_Pairset();
    test_stack_push_pop();
    test_stack_tovector();
    test_stack_exceptions();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}