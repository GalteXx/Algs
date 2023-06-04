//
// Created by Burenin Artem on 10.04.2023.
//

#include <iostream>
#include "../performance.h"

using namespace std;

namespace iterative {
    double mean(const vector<int>& vec) {
        long long sum = 0;
        for (auto item: vec) {
            sum += item;
        }
        return (double) sum / vec.size();
    }
}

namespace recursive {


    double mean(const vector<int>& vec, int begin, int end) {
        if (end - begin > 1) {
            return mean(vec, begin, begin + (end - begin) / 2) + mean(vec, begin + (end - begin) / 2, end);
        } else {
            return (double) vec[begin] / (double) vec.size();
        }
    }

    double mean(const vector<int>& vec) {
        return mean(vec, 0, (int) vec.size());
    }

    struct linked_list {
        linked_list* next;
        int data;
    };

    linked_list* new_list(int size) {
        if (size == 0)
            return nullptr;

        return new linked_list{new_list(size - 1), 0};
    }

}

int main() {
    auto data = make_random_vector(10);
    cout << data << endl;
    cout << iterative::mean(data) << endl;
    cout << recursive::mean(data) << endl;

    auto* lst = recursive::new_list(5);
    auto* iter = lst;
    int num = 1;
    while (iter != nullptr) {
        iter->data = num;
        num++;
        iter = iter->next;
    }
    iter = lst;
    while (iter != nullptr) {
        cout << iter->data << " ";
        iter = iter->next;
    }
}