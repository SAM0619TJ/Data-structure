#include "linklist_stack.h"
#include <stdexcept>

// Add a declaration for freeMemoryLinkedList if not already declare

linklist_stack::linklist_stack()
{
    stkSize = 0;
    stacktop = nullptr;
}
linklist_stack::~linklist_stack()
{
    ListNode* curr = stacktop;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    stacktop = nullptr;
    stkSize = 0;
}
int linklist_stack::size(){return stkSize;}

bool linklist_stack::isempty(){
    return size() == 0;
}

void linklist_stack::stk_push(int num)
{
    ListNode* node = new ListNode(num);
    node->next = stacktop;
    stacktop = node;
    stkSize++;
}

int linklist_stack::stk_pop()
{
    int num = top();
    ListNode* tmp = stacktop;
    stacktop = stacktop->next;
    delete tmp;
    stkSize--;
    return num;
}

int linklist_stack::top()
{
    if (isempty())
    throw std::out_of_range("stack is empty");
    return stacktop->val;
}

std::vector<int> linklist_stack::tovector()
{
    ListNode* node = stacktop;
    std::vector<int> res(size());
    for(int i = res.size() - 1; i >= 0 ; i--)
    {
        res[i] = node->val;
        node = node->next;
    }
    return res;
}