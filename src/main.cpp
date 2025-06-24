#include <iostream>
#include <cassert>
#include "hash.h"
#include "linklist_stack.h"
// 声明测试函数
void test_put_and_get();
void test_overwrite();
void test_remove();
void test_keySet_valSet();
void test_Pairset();
void test_stack_push_pop();
void test_stack_tovector();
void test_stack_exceptions();
void test_extend_and_loadfactor();

int main() {
    std::cout << "start test_put_and_get" << std::endl;
    test_put_and_get();
    std::cout << "finish test_put_and_get" << std::endl;
    std::cout << "start test_overwrite" << std::endl;
    test_overwrite();
    std::cout << "finish test_overwrite" << std::endl;
    std::cout << "start test_remove" << std::endl;
    test_remove();
    std::cout << "finish test_remove" << std::endl;
    std::cout << "start test_keySet_valSet" << std::endl;
    test_keySet_valSet();
    std::cout << "finish test_keySet_valSet" << std::endl;
    std::cout << "start test_Pairset" << std::endl;
    test_Pairset();
    std::cout << "finish test_Pairset" << std::endl;
    std::cout << "start test_stack_push_pop" << std::endl;
    test_stack_push_pop();
    std::cout << "finish test_stack_push_pop" << std::endl;
    std::cout << "start test_stack_tovector" << std::endl;
    test_stack_tovector();
    std::cout << "finish test_stack_tovector" << std::endl;
    std::cout << "start test_stack_exceptions" << std::endl;
    test_stack_exceptions();
    std::cout << "finish test_stack_exceptions" << std::endl;
    std::cout << "start test_extend_and_loadfactor" << std::endl;
    test_extend_and_loadfactor();
    std::cout << "finish test_extend_and_loadfactor" << std::endl;
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
