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
};


MinHeap merge(MinHeap first, MinHeap second) {
    MinHeap new_heap; 
    for (ll i = 0; i < first.heap.size(); i++) {
        new_heap.insert(first.heap[i]);
    }
    for (ll i = 0; i < second.heap.size(); i++) {
        new_heap.insert(second.heap[i]);
    }
    return new_heap;
}




signed main() {
    fast;
    vector<MinHeap> array_of_MinHeaps;
    string command;
    while (cin >> command) {
        if (command == "0") {
            break;
        }

        if (command == "create") {
            MinHeap new_heap;
            array_of_MinHeaps.push_back(new_heap);
        }
        else if (command == "insert") {
            ll k, x;
            cin >> k >> x;
            array_of_MinHeaps[k].insert(x);
        }
        else if (command == "extract-min") {
            ll k;
            cin >> k;
            if (array_of_MinHeaps[k].heap.size() == 0) {
                cout << "*" << '\n';
                continue;
            }
            ll EeOneGuy;
            EeOneGuy = array_of_MinHeaps[k].extract_min();
            cout << EeOneGuy << '\n';
        }
        else if (command == "merge") {
            ll k, m;
            cin >> k >> m;
            array_of_MinHeaps.push_back(merge(array_of_MinHeaps[k], array_of_MinHeaps[m]));
        }
        else if (command == "decrease-key") {
            ll k, x, y;
            cin >> k >> x >> y;
            array_of_MinHeaps[k].decrease_key(x,y);
        }
    }
    return 0;
}
