#include <iostream>
using namespace std;

int nod (int a, int b)
{
    if (b == 0)
        return a;
    return nod (b, a % b);
}


struct Node {
    int val;
    Node* next;
    Node(int _val) : val(_val), next(nullptr){};
};

struct list {
    Node* first;
    Node* last;
    list() : first(nullptr), last(nullptr) {}
    bool is_empty(){
        return first == nullptr;
    }

    void push_back(int _val) {
        Node *p = new Node(_val);
        if(is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print(Node* p) {
        if(is_empty() || !p)
            return;
        std::cout << p->val << ' ';
        print(p->next);
    }

    Node* find(int _val){
        Node* p = first;
        while(p && !(p-> val == _val))
            return (p && !(p-> val == _val)) ? p : nullptr;
        return nullptr;
    }
    void remove(int _val){
        if(is_empty())
            return;

        if(first->val == _val){
            Node* save = first;
            first = first->next;
            delete save;
        }

        if(last->val == _val){
            Node* save = last;
            Node* p = first;
            while(p && p->next != last){
                p = p->next;
            }
            if(p == nullptr)
                std::cout << "lol, what?\n";
            last = p;
            delete save;
        }

        Node* slow = first;
        Node* fast = first->next;
        while(fast && !(fast->val == _val)){
            fast = fast->next;
            slow = slow->next;
        }
        if(!fast){
            return;
        }
        slow->next = fast->next;
        delete fast;
    }
};


int main(){
    list lst;
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(3);
    lst.push_back(5);
    lst.print(lst.first);
    return 0;    
}