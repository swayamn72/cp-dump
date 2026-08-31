#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Fenwick2D {
    int n, m;
    vector<vector<ll>> bit;
    Fenwick2D(ll n, ll m) {
        this->n = n;
        this->m = m;
        bit.assign(n+1, vector<ll>(m+1,0));
    }
    void add(ll x, ll y, ll v) {
        for (ll i = x; i <= n; i += (i & -i)) {
            for (ll j = y; j <= m; j += (j & -j)) {
                bit[i][j] += v; 
            }
        }
    }
    ll query(ll x, ll y) {
        ll res = 0;
        for (ll i = x; i > 0; i -= (i & -i)) {
            for (ll j = y; j > 0; j -= (j & -j)) {
                res += bit[i][j];
            }
        }
        return res;
    }
    ll range_query(ll x1, ll y1, ll x2, ll y2) {
        return query(x2, y2) 
             - query(x1 - 1, y2) 
             - query(x2, y1 - 1) 
             + query(x1 - 1, y1 - 1);
    }
    void range_add(int x1, int y1, int x2, int y2, ll v) {
        add(x1, y1, v);
        add(x2 + 1, y1, -v);
        add(x1, y2 + 1, -v);
        add(x2 + 1, y2 + 1, v);
    }
};