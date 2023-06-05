#include <iostream>
#include <vector>
using namespace std;

std::ostream& operator<<(std::ostream &oper, vector<int> &vec){
    for(int& b : vec){
        oper << b << " ";
    }
    return oper;
}

std::istream& operator>>(std::istream &oper, vector<vector<int>> &vec){
    for(vector<int> &a : vec){
        for(int& b : a){
            oper >> b;
        }
    }
    return oper;
}


int main(){
    int n, m;
    std::cin >> m >> n;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    std::cin >> vec;
    int global = 0, best = 0;
    for(int i = 0; i < vec.size(); i++) {
        int local = 0;
        for(int j = 1; j < vec.size(); j++) {
            if(vec[i][j] == vec[i][j-1]){
                local++;
                if(global < local){
                    global = local;
                    best = i;
                }
            }
        }
    }

    std::cout << "\n" << vec[best];
}