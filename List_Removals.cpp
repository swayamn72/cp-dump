#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
template<typename T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    vi p(n); for(auto &x : p) cin >> x;
    oset<ll> s;
    for(ll i=0; i<n; i++) s.insert(i);
    for(auto a : p){
        auto it = s.find_by_order(a-1);
        cout << arr[*it] << " ";
        s.erase(it);
    }
}