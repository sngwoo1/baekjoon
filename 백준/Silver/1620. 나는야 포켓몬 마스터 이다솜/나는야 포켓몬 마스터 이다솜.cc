#include <iostream>
#include <map>
#include <string>

using namespace std;

string a[100001], s;
map<string, int> mp;
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		mp[a[i]] = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			cout << a[stoi(s)] << '\n';
		}

		else {
			cout << mp[s] << '\n';
		}
	}

}
