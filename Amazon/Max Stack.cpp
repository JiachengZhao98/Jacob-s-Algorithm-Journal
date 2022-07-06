#include "stack"
#include "map"
using namespace std;

class MaxStack {
private:
    struct linkedList {
        int val;
        linkedList* prev;
        linkedList* next;
        linkedList(): val(0), prev(nullptr), next(nullptr) {};
        linkedList(int x): val(x), prev(nullptr), next(nullptr) {};
    };
    
public:
        linkedList* root = new linkedList();
        linkedList* cur = root;
        multimap<int, linkedList*> myMap;
       

    MaxStack() {
        
    }
    
    
    void push(int x) {
        linkedList* newAdd = new linkedList(x);
        cur->next = newAdd;
        newAdd->prev = cur;
        cur = cur->next;     // cur always points to the last node of this linkedList
        myMap.insert(pair<int, linkedList*>(newAdd->val, newAdd));
    }
    
    int pop() {
        linkedList* temp = cur;
        cur = temp->prev;
        cur->next = temp->next;
        auto it = myMap.equal_range(temp->val);
        for (auto itr = it.first; itr != it.second; ++itr) { 
            if (itr->second == temp) {                       // choose the same node as cur and remove it from myMap
                myMap.erase(itr);
                break;
            }
        }
        return temp->val;
        delete temp;
    }
    
    int top() {
        return cur->val;
    }
    
    int peekMax() {
        return myMap.rbegin()->first;
    }
    
    int popMax() {
        int Max = myMap.rbegin()->first;
        auto it = myMap.equal_range(Max);
        linkedList* temp;
        for (auto itr = it.first; itr != it.second; ++itr) { 
            temp = itr->second;
        }
        for (auto itr = it.first; itr != it.second; ++itr) { 
            if (itr->second == temp) {
                myMap.erase(itr);
                break;
            }
        }
        temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (cur == temp) cur = cur->prev;
        return Max;
        
    }
};