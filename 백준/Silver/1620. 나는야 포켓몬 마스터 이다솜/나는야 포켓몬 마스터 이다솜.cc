#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
map<string, int> mp;
string a[100004];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        cin >> s;
        mp[s] = i + 1;
        a[i+1] = s;
    }
    
    for(int i = 0; i < M; i++) {
        cin >> s;
        if(isdigit(s[0])) cout << a[stoi(s)] << '\n';
        else {
            cout << mp[s] << '\n';
        }
    }
    
    return 0;
}