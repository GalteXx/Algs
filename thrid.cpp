#include <iostream>
#include <vector>
using namespace std;

std::ostream& operator<<(std::ostream &oper, vector<int> &vec){
    for(int& b : vec){
        oper << b << " ";
    }
    return oper;
}

void randVec(vector<int> &vec) {
    for(auto &i : vec)
        i = rand();
}

void SortSplits(vector<int>& v, int s, int m, int e) {
	vector<int> temp;
	int i = s, j = m + 1;
	while (i <= m && j <= e) {
		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}
	}
	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}
	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}
	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];
}
void Split(vector<int>& vec, int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
		Split(vec, s, mid);
		Split(vec, mid + 1, e);
		SortSplits(vec, s, mid, e);
	}
}

void BubbleSort(vector<int> &vec)
{
	int i, j, c;
	int k = 0;
	for(i = vec.size(); i > 1; i--) {
		k = 0;
		for(j = 1; j < i; j++)
			if(vec[j] < vec[j - 1]) {
				c = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = c;
				k = 1;
			}
		if (k == 0) 
            return;
	}
}


int main()
{
    srand(time(NULL));
	std::cout << "Enter array size\n";
	int size;
	std::cin >> size;
	vector<int> vec(size, 0);
    randVec(vec);
	std::cout << "Array: " << vec << '\n';
    BubbleSort(vec);
    std::cout << "Sorted array: " << vec << '\n';
}