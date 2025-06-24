#include <iostream>

// 声明测试函数
void test_put_and_get();
void test_overwrite();
void test_remove();
void test_keySet_valSet();
void test_Pairset();

int main() {
    test_put_and_get();
    test_overwrite();
    test_remove();
    test_keySet_valSet();
    test_Pairset();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}