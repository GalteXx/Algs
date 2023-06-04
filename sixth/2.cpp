//
// Created by Burenin Artem on 13.04.2023.
//

#include <iostream>
#include <map>
#include "account.hpp"
#include "../5/list.hpp"

using namespace std;

void remove_(List<Operation>& operations) {
    map<string, int> balances;
    for (const auto& op: operations) {
        if (op._type == OperationType::ADDINTION)
            balances[op._account_id] += op._amount;
        else
            balances[op._account_id] -= op._amount;
    }

    auto it = operations.begin();
    while (it != operations.end()) {
        if (balances[it->_account_id] >= 0) {
            it = operations.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
    List<Operation> operations;
    int n;
    cout << "Введите количество операций: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string date, account_id;
        int amount;
        cout << endl << "Введите номер счёта (число, 20 знаков): ";
        cin >> account_id;
        cout << endl << "Введите дату операции (dd.mm.yyyy): ";
        cin >> date;
        cout << endl << "Введите изменение баланса: ";
        cin >> amount;
        Operation op;
        auto err = parse(op, account_id, date, amount);
        if (err) {
            cout << endl << err.details;
            --i;
        } else {
            operations.push_back(op);
        }
    }
    remove_(operations);
    cout << endl << "Оставшиеся операции: ";
    for (const auto& op: operations) {
        cout << endl << op.str();
    }
}