#include <iostream>
#include <vector>
using namespace std;

void randVec(vector<int> vec) {
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

int BubbleSort(int *array,int len)
{
	int i, j, c;
	int k = 0;
	for(i = len; i > 1; i--) {
		k = 0;
		for(j = 1; j < i; j++)
		if(array[j] < array[j - 1]) {
			c = array[j];
			array[j] = array[j - 1];
			array[j - 1] = c;
			k = 1;
		}
		if (k == 0) 
            return 0;
	}
}


int main()
{
    srand(time(NULL));
	vector<int> vec;
    randVec(vec);
    Split(vec, 0, vec.size());
    
}