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

void f(string str, vector<ll> &digit) {
    for (ll i = (ll)str.length(); i > 0; i -= 9) {
        if (i >= 9) {
            digit.push_back(stoi(str.substr(i - 9, 9)));
        }
        else {
            digit.push_back(stoi(str.substr(0, i)));
        }
    }
}

signed main() {

    fast
    const ll base = 1000 * 1000 * 1000;
    ll n;
    cin >> n;
    string number;
    cin >> number;
    vector<ll> digit;
    f(number, digit);
    for (ll j = 1; j < n; j++) {
        string anumber;
        cin >> anumber;
        vector<ll> aDigit;
        f(anumber, aDigit);
        ll flag = 0;
        ll max_len_number = max(digit.size(), aDigit.size());
        for (size_t i = 0; i < max_len_number || flag; i++) {
            if (i == digit.size()) {
                digit.push_back(0);
            }
            if (i < aDigit.size()) {
                digit[i] += flag + aDigit[i];
            }
            else {
                digit[i] += flag + 0;
            }
            flag = digit[i] >= base;
            if (flag) {
                digit[i] -= base;
            }
        }
    }
    if (!digit.empty()) {
        printf("%lld", digit.back());
    }
    else {
        printf("%lld", (ll) 0);
    }
    for (ll i = (ll) digit.size() - 2; i >= 0; --i)
        printf("%09lld", digit[i]);
    return 0;
}
