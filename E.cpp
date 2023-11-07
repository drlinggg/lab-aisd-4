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

struct MinHeap {
    //non-increasing
    vector<ll> heap;

    void sift_up(ll index) {
        while (index > 0 && heap[(index-1)/2] > heap[index]) {
            ll parent = (index-1)/2;
            swap(heap[index],heap[parent]);
            index = parent;
        }
    }
    void sift_down(ll index) {
        while (2*index+1 < heap.size()) {
            ll left = 2 * index + 1;
            ll right = 2 * index + 2;
            ll j = left;
            if ((right < heap.size()) && (heap[right] < heap[left])) {
                j = right;
            }
            if (heap[index] <= heap[j]) {
                break;
            }
            swap(heap[index], heap[j]);
            index = j;
        }
    }

    void insert(ll value) {
        heap.push_back(value);
        sift_up(heap.size()-1);

    }
    ll extract_min() {
        ll value = heap[0];
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        sift_down(0);
        sift_up(heap.size()-1);
        return value;
    }
    void decrease_key(ll x, ll y) {
        for (ll i = 0; i < heap.size(); i++) {
            if (heap[i] == x) {
                heap[i] = y;
                ll j = i;
                sift_up(j);
                sift_down(j);
                return;
            }
        }
    }
    void heapsort(ll *arr) {
        ll i = 0;
        while (heap.size() != 0) {
            arr[i] = extract_min();
            i++;
        }
    }
};

signed main() {
    fast;
    ll n;
    cin >> n;
    MinHeap EeOneGuy;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        EeOneGuy.insert(temp);
    }
    ll arr[n];
    EeOneGuy.heapsort(arr);
    for (ll i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
