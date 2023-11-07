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

struct Node
{
    ll code;
    ll value;
};


struct MaxHeap {
    //non-decreasing
    vector<Node> heap;

    void sift_up(ll index) {
        while (index > 0 && heap[(index-1)/2].value <= heap[index].value) {
            ll parent = (index-1)/2;
            if (heap[index].value == heap[parent].value) {
                ll temp = heap[index].code;
                ll temp1 = heap[parent].code;
                heap[parent].code = max(temp,temp1);
                heap[index].code = min(temp,temp1);
                index = parent;
                continue;
            }
            swap(heap[index],heap[parent]);
            index = parent;
        }
    }
    void sift_down(ll index) {
        while (2*index+1 < heap.size()) {
            ll left = 2 * index + 1;
            ll right = 2 * index + 2;
            ll j = left;
            if ((right < heap.size()) && (heap[right].value > heap[left].value)) {
                j = right;
            }
            else if (heap[right].value == heap[left].value) {
                if (heap[right].code > heap[left].code) {
                    j = right;
                }
                else {
                    j = left;
                }
            }
            if (heap[index].value == heap[j].value) {
                ll temp = heap[index].code;
                ll temp1 = heap[j].code;
                heap[j].code = min(temp,temp1);
                heap[index].code = max(temp,temp1);
                index = j;
                continue;
            }
            else if (heap[index].value > heap[j].value) {
                break;
            }
            swap(heap[index], heap[j]);
            index = j;
        }
    }

    void insert(Node value) {
        heap.push_back(value);
        sift_up(heap.size()-1);

    }
    ll extract_max() {
        ll value = heap[0].value;
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        sift_down(0);
        sift_up(heap.size()-1);
        return value;
    }

    void take(ll index) {
        swap(heap[index],heap[heap.size()-1]);
        heap.pop_back();
        sift_down(index);
        sift_up(index);
    }
};

signed main() {
    fast;
    ll n;
    cin >> n;
    vector<Node> Cities_rating;
    vector<Node> Cities_money;
    vector<ll> tours;
    vector<ll> producer_calls;
    ll count_of_calls = 0;
    MaxHeap rating_heap;
    MaxHeap money_heap;
    for (ll i = 0; i < n; i++) {
        ll index, rating, money;
        cin >> index >> rating >> money;
        Node a;
        a.value = rating; a.code = index;
        Node b;
        b.value = money; b.code = index;
        Cities_rating.push_back(a);
        Cities_money.push_back(b);
    }
    ll count_of_trades;
    cin >> count_of_trades;
    vector<string> answers;
    for (ll i = 0; i < count_of_trades; i++) {
        string temp;
        cin >> temp;
        answers.push_back(temp);
    }
    for (ll i = 0; i < n; i++) {
        rating_heap.insert(Cities_rating[i]);
        money_heap.insert(Cities_money[i]);
    }
    while (rating_heap.heap.size() != 0) {
        if (rating_heap.heap[0].code == money_heap.heap[0].code) {
            tours.push_back(rating_heap.heap[0].code);
            money_heap.extract_max();
        }else {
            if (count_of_calls < count_of_trades) {
                producer_calls.push_back(rating_heap.heap[0].code);
                if (answers[count_of_calls] == "YES") {
                    tours.push_back(rating_heap.heap[0].code);
                }
                for (ll i = 0; i<money_heap.heap.size(); i++) {
                    if (money_heap.heap[i].code == rating_heap.heap[0].code) {
                        money_heap.take(i);
                        break;
                    }
                }
                count_of_calls++;
            }
        }
        rating_heap.extract_max();
        rating_heap.sift_down(0);
        money_heap.sift_down(0);
    }

    for (ll i = 0; i < producer_calls.size(); i++) {
        cout << producer_calls[i] << " ";
    }
    cout << '\n';
    for (ll i = 0; i < tours.size(); i++) {
        cout << tours[i] << " ";
    }
    return 0;
}
