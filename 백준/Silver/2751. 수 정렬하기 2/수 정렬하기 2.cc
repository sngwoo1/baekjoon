#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int tmp, N;

int main() {
	cin >> N;
	while(N--) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for(int i : v) cout << i << '\n';
}