//
// Created by Burenin Artem on 13.04.2023.
//

#include <iostream>
#include <map>
#include "account.hpp"
#include "../5/list.hpp"

using namespace std;

List<Operation> select_by_account_id(List<Operation>& operations, const string& account_id) {
    List<Operation> lst;
    copy_if(operations.begin(), operations.end(), back_inserter(lst),
            [=](Operation& op) { return op._account_id == account_id; });
    return lst;
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
    string account_id;
    cin >> account_id;

    auto selected_ops = select_by_account_id(operations, account_id);
    cout << endl << "Выбранные операции: ";
    for (const auto& op: selected_ops) {
        cout << endl << op.str();
    }
}