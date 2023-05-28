#include <iostream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

vector<string> Split(string str, char sep){
	string tmp = "";
	vector<string> res;
	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i+1] == '\0') {
			tmp += str[i];
			res.push_back(tmp);
			tmp = "";
		}
		if(str[i] == sep) {
			res.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += str[i];
		}
	}
	return res;
}

int main(){
    string a = "Blue brown kitty walked outside the door";
    vector<string> c = Split(a, ' ');
    for(auto b : c)
        cout << b << " ";
    return 0;
}