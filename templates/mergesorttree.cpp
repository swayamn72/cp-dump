#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

struct MergeSortTree {
    ll n; 
    vector<vi> seg; 
    
    MergeSortTree(ll n) {
        this->n = n;
        seg.resize(4 * n + 1);
    }
    
    void build(ll node, ll l, ll r, vi &arr) {
        if (l == r) {
            seg[node] = {arr[l]};
            return;
        }
        ll m = l + (r - l) / 2;
        build(2 * node, l, m, arr);
        build(2 * node + 1, m + 1, r, arr);

        merge(seg[2 * node].begin(), seg[2 * node].end(),
              seg[2 * node + 1].begin(), seg[2 * node + 1].end(),
              back_inserter(seg[node]));
    }
    
    // Query: Find the smallest number >= x in range [ql, qr]
    ll query(ll node, ll l, ll r, ll ql, ll qr, ll x) {
        if (ql > r || qr < l) {
            return LLONG_MAX; // Identity for minimum
        }
        
        // If the node's segment is completely inside the query range
        if (ql <= l && qr >= r) {
            // Binary search within the node's sorted vector
            auto it = lower_bound(seg[node].begin(), seg[node].end(), x);
            if (it != seg[node].end()) {
                return *it;
            }
            return LLONG_MAX; // No element >= x exists in this segment
        }
        
        ll m = l + (r - l) / 2;
        return min(query(2 * node, l, m, ql, qr, x),
                   query(2 * node + 1, m + 1, r, ql, qr, x));
    }
    
    // Note: If you want to count elements < x, change query return type to ll, 
    // change LLONG_MAX to 0, use std::distance with std::lower_bound, and return 
    // sum instead of min.
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, q; 
    if (cin >> n >> q) {
        vi arr(n); 
        for(auto &x : arr) cin >> x;
        
        MergeSortTree mst(n);
        mst.build(1, 0, n - 1, arr);
        
        while(q--) {
            ll l, r, x; 
            cin >> l >> r >> x;
            l--; r--; // Assuming 1-based queries in input, converting to 0-based
            
            ll ans = mst.query(1, 0, n - 1, l, r, x);
            if (ans == LLONG_MAX) cout << -1 << "\n"; // No answer
            else cout << ans << "\n";
        }
    }
    return 0;
}