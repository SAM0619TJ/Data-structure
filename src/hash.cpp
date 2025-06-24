#include "hash.h"
#include <iostream>

// Pair 构造函数实现
Pair::Pair(int key, std::string val) : key(key), val(val) {}
//构造函数初始化
ArrayhashMap::ArrayhashMap() : size(0), capacity(5), loadThres(0.75), extendRatio(2){
    buckets.resize(capacity);
}
//析构方法
ArrayhashMap::~ArrayhashMap() {
    for(auto& bucket: buckets)
    {
        for(Pair* pair : bucket)
        {
            //释放内存
            delete pair;
        }
    }

}
int ArrayhashMap::Hashfunc(int key) {
    return key % 100;
}

double ArrayhashMap::loadfactor(){
    return (double)size / (double)capacity;
}
void ArrayhashMap::extend()
{
    int old_capacity = capacity;
    capacity *= extendRatio;
    std::vector<std::vector<Pair*>> new_buckets(capacity);
    for (auto& bucket : buckets) {
        for (auto pair : bucket) {
            int index = Hashfunc(pair->key);
            new_buckets[index].push_back(pair);
        }
    }
    buckets = std::move(new_buckets);
}
std::string ArrayhashMap::get(int key) 
{
    int index = Hashfunc(key);
    for(Pair *pair: buckets[index])
    {
        if(pair->key == key)
        {
            return pair->val;
        }
    }
    return "";
}
void ArrayhashMap::put(int key, std::string val) 
{
 // 当负载因子超过阈值时，执行扩容
    if (loadfactor() > loadThres) {
    extend();
    }
    int index = Hashfunc(key);
 // 遍历桶，若遇到指定 key ，则更新对应 val 并返回
    for (Pair *pair : buckets[index]) {
        if (pair->key == key) {
            pair->val = val;
            return;
            }
        }
 // 若无该 key ，则将键值对添加至尾部
    buckets[index].push_back(new Pair(key, val));
    size++;
 
}
void ArrayhashMap::remove(int key) {
    int index = Hashfunc(key);
    auto& bucket = buckets[index];
    for (int i = 0; i < bucket.size(); i++)
    {
        if(bucket[i]->key == key)
        {
            Pair* tmp = bucket[i];
            bucket.erase(bucket.begin()+i);
            delete tmp;
            size--;
            return ;
        }
    }
    throw std::logic_error("Key not found");
}
std::vector<Pair* >ArrayhashMap::Pairset() {
    std::vector<Pair *> Pairset;
    for (auto& bucket : buckets) 
    {
        for(Pair* pair: bucket)
        {
            if(pair != nullptr){
                Pairset.push_back(pair);
            }
        }
    }
    return Pairset;
}
std::vector<int> ArrayhashMap::keySet() {
    std::vector<int> keySet;
    for (auto& bucket : buckets) {
        for(Pair* pair: bucket)
        {
            if(pair != nullptr){
                keySet.push_back(pair->key);
            }
        }
    }
    return keySet;
}
std::vector<std::string> ArrayhashMap::valSet() {
    std::vector<std::string> valSet;
    for(auto& bucket :buckets)
    {
        for (Pair *pair : bucket) 
        {
            if (pair != nullptr) { valSet.push_back(pair->val);}
        }
    }
    return valSet;

}
void ArrayhashMap::printHash() {
    for (Pair* kv : Pairset()) {
        std::cout << kv->key << "->" << kv->val << std::endl;
    }
}
