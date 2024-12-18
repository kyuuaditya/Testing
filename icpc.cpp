#include <iostream>
#include <string>
using namespace std;

bool check(const string& s) {
    int n = s.length();
    if (n < 2) return false;

    for (int i = 1; i < n; i++) {
        string t1 = s.substr(0, i);
        // cout << (s.substr(0, 1)) << endl;
        string t2 = s.substr(i);
        // cout << (s.substr(i)) << endl;
        if (t1.front() != t2.back()) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        int n;
        cin >> n;
        cin >> s;
        if (check(s)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}