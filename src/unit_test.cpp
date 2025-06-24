#include <iostream>
#include <cassert>
#include "hash.h"
#include "linklist_stack.h"


void test_put_and_get() {
    ArrayhashMap map;
    map.put(1, "one");
    map.put(2, "two");
    assert(map.get(1) == "one");
    assert(map.get(2) == "two");
    assert(map.get(3) == ""); // not exist
}

void test_overwrite() {
    ArrayhashMap map;
    map.put(1, "one");
    map.put(1, "uno");
    assert(map.get(1) == "uno");
}

void test_remove() {
    ArrayhashMap map;
    map.put(1, "one");
    map.remove(1);
    assert(map.get(1) == "");
}

void test_keySet_valSet() {
    ArrayhashMap map;
    map.put(1, "one");
    map.put(2, "two");
    auto keys = map.keySet();
    auto vals = map.valSet();
    assert(keys.size() == 2);
    assert(vals.size() == 2);
}

void test_Pairset() {
    ArrayhashMap map;
    map.put(1, "one");
    map.put(2, "two");
    auto pairs = map.Pairset();
    assert(pairs.size() == 2);
    assert((pairs[0]->val == "one" || pairs[0]->val == "two"));
    std::cout << "[test_Pairset] HashMap :" << std::endl;
    map.printHash();
}
void test_stack_push_pop() {
    linklist_stack stk;
    assert(stk.isempty());
    stk.stk_push(10);
    stk.stk_push(20);
    stk.stk_push(30);
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
    }
    assert(thrown);
    thrown = false;
    try {
        stk.stk_pop();
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
    std::cout << "[test_stack_exceptions] passed!" << std::endl;
}



