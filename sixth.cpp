#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct topic{
    string name;
    string date;
};


struct Node {
    topic val;
    Node* next;
    Node* prev;
};

bool operator==(const topic& a, const topic& b){
    return a.name == b.name;
}

struct list {
    Node* first;
    Node* last;
    list() : first(nullptr), last(nullptr) {}
    bool is_empty(){
        return first == nullptr;
    }

    void insert(topic _val, Node* pr){
        Node* nw = new Node();
        nw->val = _val;
        if(is_empty()){
            first = nw;
            last = nw;
            nw->prev = nullptr;
            nw->next = nullptr;
            return;
        }
        nw->prev = pr;
        nw->next = pr->next;
        pr->next->prev=nw;
        pr->next = nw;
    }

    void print(bool from_right = false) {
        if(is_empty())
            return;
        if(from_right){
            Node* p = last;
            while(p) {
                std::cout << p->val.name << " ";
                p = p->prev;
            }
            std::cout << '\n';
            return;
        }
        Node* p = first;
        while(p) {
            std::cout << p->val.name << " ";
            p = p->next;
        }
        std::cout << '\n';
    }

    Node* find(topic _val){
        Node* p = first;
        while(p && !(p-> val == _val))
            return (p && !(p-> val == _val)) ? p : nullptr;
        return nullptr;
    }
    void remove(topic _val){
        if(is_empty())
            return;

        if(first->val == _val){
            Node* save = first;
            first = first->next;
            delete save;
        }

        if(last->val == _val){
            Node* save = last;
            last = last->prev;
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



list* initialise_from_array(topic str[], int size){
    list* res = new list();
    for(int i = 0; i < size; i++){
        res->insert(str[i], res->last);
    }
    return res;
}


struct school_class{
    int num;
    list* topics = new list();
};



int main(){
    int code;
    cin >> code;
    school_class cl;
    cl.num = code;
    string a = "a";
    while(a != "endtopics"){
        cin >> a; 
        topic tmp;
        tmp.name = a;
        cin >> a;
        tmp.date = a;
        cl.topics->insert(tmp, cl.topics->last);
    }
    vector<topic*> b;
    b.push_back((topic*) cl.topics->first);
    Node* p = cl.topics->first;
    while(p){
        cl.topics->remove(p->val);
        p = p->next;
    }
    return 0;
}