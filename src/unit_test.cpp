#include "hash.h"
#include <iostream>
#include <cassert>

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


