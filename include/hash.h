#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>

struct Pair {
    int key;
    std::string val;
    Pair(int key, std::string val);
};

class ArrayhashMap {
public:
    ArrayhashMap();
    ~ArrayhashMap();
    int Hashfunc(int key);
    std::string get(int key);
    void put(int key, std::string val);
    void remove(int key);
    std::vector<int> keySet();
    std::vector<std::string> valSet();
    std::vector<Pair *> Pairset();
    void printHash();
private:
    std::vector<Pair *> buckets;
};

#endif // HASH_H