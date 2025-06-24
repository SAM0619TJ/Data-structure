#include "hash.h"
#include <iostream>

// Pair 构造函数实现
Pair::Pair(int key, std::string val) : key(key), val(val) {}
ArrayhashMap::ArrayhashMap() {
    buckets = std::vector<Pair *>(100);
}
ArrayhashMap::~ArrayhashMap() {
    for (const auto& bucket : buckets) {
        delete bucket;
    }
    buckets.clear();
}
int ArrayhashMap::Hashfunc(int key) {
    return key % 100;
}
std::string ArrayhashMap::get(int key) {
    int index = Hashfunc(key);
    Pair *pair = buckets[index];
    if (pair == nullptr) return "";
    return pair->val;
}
void ArrayhashMap::put(int key, std::string val) {
    Pair *pair = new Pair(key, val);
    int index = Hashfunc(key);
    buckets[index] = pair;
}
void ArrayhashMap::remove(int key) {
    int index = Hashfunc(key);
    delete buckets[index];
    buckets[index] = nullptr;
}
std::vector<Pair *> ArrayhashMap::Pairset() {
    std::vector<Pair *> Pairset;
    for (Pair *pair : buckets) {
        if (pair != nullptr) {
            Pairset.push_back(pair);
        }
    }
    return Pairset;
}
std::vector<int> ArrayhashMap::keySet() {
    std::vector<int> keySet;
    for (Pair *pair : buckets) {
        if (pair != nullptr) {
            keySet.push_back(pair->key);
        }
    }
    return keySet;
}
std::vector<std::string> ArrayhashMap::valSet() {
    std::vector<std::string> valSet;
    for (Pair *pair : buckets) {
        if (pair != nullptr) {
            valSet.push_back(pair->val);
        }
    }
    return valSet;
}
void ArrayhashMap::printHash() {
    for (Pair* kv : Pairset()) {
        std::cout << kv->key << "->" << kv->val << std::endl;
    }
}
