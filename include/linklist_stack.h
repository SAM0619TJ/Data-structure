#ifndef LINKLIST_STACK_H
#define LINKLIST_STACK_H

#include<vector>
// Define ListNode if not already defined elsewhere
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

class linklist_stack
{
private:
    int stkSize;
    ListNode *stacktop;
    /* data */
public:
    linklist_stack();
    ~linklist_stack();
    int size();
    bool isempty();
    void stk_push(int num);
    int stk_pop();
    int top();
    std::vector<int> tovector();
};


#endif