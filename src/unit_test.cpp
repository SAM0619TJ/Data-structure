#include <iostream>
#include <cassert>
#include "hash.h"
#include "linklist_stack.h"

void test_put_and_get() {
    ArrayhashMap map;
    map.put(1, "one");
    map.put(2, "two");
    std::cout << "map.get(1): " << map.get(1) << std::endl;
    std::cout << "map.get(2): " << map.get(2) << std::endl;
    std::cout << "map.get(3): " << map.get(3) << std::endl;
    assert(map.get(1) == "one");
    assert(map.get(2) == "two");
    assert(map.get(3) == ""); // not exist
    std::cout << "[test_put_and_get] passed!" << std::endl;
}

void test_overwrite() {
    ArrayhashMap map;
    map.put(1, "one");
    std::cout << "before overwrite: " << map.get(1) << std::endl;
    map.put(1, "uno");
    std::cout << "after overwrite: " << map.get(1) << std::endl;
    assert(map.get(1) == "uno");
    std::cout << "[test_overwrite] passed!" << std::endl;
}

void test_remove() {
    ArrayhashMap map;
    map.put(1, "one");
    std::cout << "before remove: " << map.get(1) << std::endl;
    map.remove(1);
    std::cout << "after remove: " << map.get(1) << std::endl;
    assert(map.get(1) == "");
    std::cout << "[test_remove] passed!" << std::endl;
}

void test_keySet_valSet() {
    ArrayhashMap map;
    map.put(1, "one");
    map.put(2, "two");
    auto keys = map.keySet();
    auto vals = map.valSet();
    std::cout << "keys: ";
    for (int k : keys) std::cout << k << " ";
    std::cout << "\nvals: ";
    for (auto& v : vals) std::cout << v << " ";
    std::cout << std::endl;
    assert(keys.size() == 2);
    assert(vals.size() == 2);
    std::cout << "[test_keySet_valSet] passed!" << std::endl;
}

void test_Pairset() {
    ArrayhashMap map;
    map.put(1, "one");
    map.put(2, "two");
    auto pairs = map.Pairset();
    std::cout << "pairs: ";
    for (auto p : pairs) std::cout << "(" << p->key << "," << p->val << ") ";
    std::cout << std::endl;
    assert(pairs.size() == 2);
    assert((pairs[0]->val == "one" || pairs[0]->val == "two"));
    std::cout << "[test_Pairset] HashMap :" << std::endl;
    map.printHash();
    std::cout << "[test_Pairset] passed!" << std::endl;
}

void test_stack_push_pop() {
    linklist_stack stk;
    assert(stk.isempty());
    stk.stk_push(10);
    stk.stk_push(20);
    stk.stk_push(30);
    std::cout << "stack top: " << stk.top() << std::endl;
    assert(stk.size() == 3);
    assert(stk.top() == 30);
    assert(stk.stk_pop() == 30);
    assert(stk.top() == 20);
    assert(stk.stk_pop() == 20);
    assert(stk.stk_pop() == 10);
    assert(stk.isempty());
    std::cout << "[test_stack_push_pop] passed!" << std::endl;
}

void test_stack_tovector() {
    linklist_stack stk;
    for (int i = 1; i <= 5; ++i) stk.stk_push(i);
    auto vec = stk.tovector();
    std::cout << "stack to vector: ";
    for (int v : vec) std::cout << v << " ";
    std::cout << std::endl;
    assert(vec.size() == 5);
    for (int i = 0; i < 5; ++i) {
        assert(vec[i] == i + 1);
    }
    std::cout << "[test_stack_tovector] passed!" << std::endl;
}

void test_stack_exceptions() {
    linklist_stack stk;
    bool thrown = false;
    try {
        stk.top();
    } catch (const std::out_of_range&) {
        thrown = true;
        std::cout << "[test_stack_exceptions] top() exception caught" << std::endl;
    }
    assert(thrown);
    thrown = false;
    try {
        stk.stk_pop();
    } catch (const std::out_of_range&) {
        thrown = true;
        std::cout << "[test_stack_exceptions] stk_pop() exception caught" << std::endl;
    }
    assert(thrown);
    std::cout << "[test_stack_exceptions] passed!" << std::endl;
}

void test_extend_and_loadfactor() {
    ArrayhashMap map;
    int n = 100;
    for (int i = 0; i < n; ++i) {
        map.put(i, std::to_string(i));
    }
    double lf = map.loadfactor();
    std::cout << "[test_extend_and_loadfactor] loadfactor: " << lf << std::endl;
    assert(lf <= 1.0); // 扩容后负载因子应合理
    map.extend(); // 手动扩容
    std::cout << "[test_extend_and_loadfactor] after extend, loadfactor: " << map.loadfactor() << std::endl;
    for (int i = 0; i < n; ++i) {
        assert(map.get(i) == std::to_string(i));
    }
    std::cout << "[test_extend_and_loadfactor] passed!" << std::endl;
}




