#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout << 1 << '\n';
            cout << "1 1\n";
            continue;
        }
        cout << n / 2 << '\n';
        for (int i = 0; i < n / 2; i++) {
            if (n % 2 == 1 && i == 0) cout << "3 ";
            else cout << "2 ";
            cout << i * 2 + 1 << ' ' << i * 2 + 2;
            if (n % 2 == 1) {
                if (i == 0) cout << ' ' << n;
            }
            cout << '\n';
        }
    }
    return 0;
}
