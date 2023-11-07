#include <bits/stdc++.h>
#define fast std::cin.tie(0);std::ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll RBN = 1e9+7;
const ll RSN = -(1e9+7);
const double PI = 3.141592653589793;
//mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); ll gen(){return rnd()%100;}

signed main() {
    ll n;
    cin >> n;
    ll ar[n] = {0};
    for (ll i = 1; i < n; i++) {
        cin >> ar[i];
    }
    for (ll i = 1; i <= log2(n); i++) {
        if (ar[i] >= ar[i*2] || ar[i] >= ar[i*2 + 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
