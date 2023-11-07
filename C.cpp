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

struct Shaurmist
{
    ll salary;
    ll free_time;
};

struct MinHeap_workers {
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
        if (heap.size() == 0) {
            return -1;
        }
        ll value = heap[0];
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        sift_down(0);
        sift_up(heap.size()-1);
        return value;
    }
};

struct MinHeap_working {
    //non-increasing
    vector<Shaurmist> heap;

    void sift_up(ll index) {
        while (index > 0 && heap[(index-1)/2].free_time > heap[index].free_time) {
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
            if ((right < heap.size()) && (heap[right].free_time < heap[left].free_time)) {
                j = right;
            }
            if (heap[index].free_time <= heap[j].free_time) {
                break;
            }
            swap(heap[index], heap[j]);
            index = j;
        }
    }

    void insert(Shaurmist value) {
        heap.push_back(value);
        sift_up(heap.size()-1);

    }
    ll extract_min() {
        Shaurmist value = heap[0];
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        sift_down(0);
        sift_up(heap.size()-1);
        return value.salary;
    }
};

signed main() {
    fast;
    MinHeap_working working;
    MinHeap_workers workers;
    ll salary = 0;
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        workers.insert(temp);
    }

    for (ll i = 0; i < m; i++) {
        ll start, duration;
        cin >> start >> duration;
        //cout << "vreyma " << start << '\n';
        //cout << "zakaz " << i+1 << '\n';
        while (working.heap.size() != 0 && working.heap[0].free_time <= start) {
            ll free_worker = working.extract_min();
            //cout << "free to go " << free_worker << '\n';
            workers.insert(free_worker);
        }
        if (workers.heap.size() != 0) {
            ll worker = workers.extract_min();
            //cout << worker << " taken" << '\n';
            salary += worker*duration;
            //cout << worker*duration << " paid" << '\n';
            Shaurmist working_guy;
            working_guy.salary = worker;
            working_guy.free_time = start+duration;
            working.insert(working_guy);
        }
    }
    cout << salary;
    return 0;
}
