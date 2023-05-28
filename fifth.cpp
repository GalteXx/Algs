#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



struct pw_cf{
    int power;
    double coefficient;
};

bool operator==(const pw_cf& a, const pw_cf& b){
    return a.coefficient==b.coefficient && a.power == b.coefficient;
}
std::ostream& operator<<(std::ostream& stream, pw_cf& a){
    stream << a.coefficient << "_" << a.power;
    return stream;
}

struct Node {
    pw_cf val;
    Node* next;
    Node(pw_cf _val) : val(_val), next(nullptr){};
};

struct list {
    Node* first;
    Node* last;
    list() : first(nullptr), last(nullptr) {}
    bool is_empty(){
        return first == nullptr;
    }

    void push_back(pw_cf _val) {
        Node *p = new Node(_val);
        if(is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if(is_empty())
            return;
        Node* p = first;
        while(p) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << '\n';
    }

    Node* find(pw_cf _val){
        Node* p = first;
        while(p && !(p-> val == _val))
            return (p && !(p-> val == _val)) ? p : nullptr;
        return nullptr;
    }
    void remove(pw_cf _val){
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

    void print_as_expression(){
        Node* p = first;
        while(p){
            if(p->val.coefficient == 0){
                p = p->next;
            }

            if(p->val.coefficient != 1)
                std::cout << p->val.coefficient;
                
            std::cout << "x";
            if(p->val.power != 1)
                std::cout << "^" << p->val.power;
            if(p->next != nullptr)
                std::cout<< " + ";
            p = p->next;
        }
    }

    double calculate(double x){
        Node* p = first;
        double sum = 0;
        while(p){
            sum += p->val.coefficient*pow(x, p->val.power);
            p = p->next;
        }
        return sum;
    }
};



list* initialise_from_array(pw_cf str[], int size){
    list* res = new list();
    for(int i = 0; i < size; i++){
        res->push_back(str[i]);
    }
    return res;
}




int main(){
    pw_cf c1, c2, c3;
    c1.coefficient = 1;
    c1.power = 1;
    c2.coefficient = 2;
    c2.power = 2;
    c3.coefficient = 3;
    c3.power = 3;
    pw_cf a[3] = {c1, c2, c3};
    list* l = initialise_from_array(a, sizeof(a)/sizeof(a[0]));
    cout << l->calculate(1);
    return 0;
}