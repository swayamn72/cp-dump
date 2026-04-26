#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree
{
    ll n;
    vi seg;
    vi lazy;
    SegTree(ll n)
    {
        this->n = n;
        seg.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, -1);
    }
    void push(ll node, ll l, ll r)
    {
        if (lazy[node] == -1)
            return;
        seg[node] = (r - l + 1) * lazy[node];
        if (l != r)
        {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = -1;
    }
    void update(ll node, ll l, ll r, ll ql, ll qr, ll val)
    {
        push(node, l, r);
        if (ql > r || qr < l)
            return;
        if (ql <= l && qr >= r)
        {
            lazy[node] = val;
            push(node, l, r);
            return;
        }
        ll m = l + (r - l) / 2;
        update(2 * node, l, m, ql, qr, val);
        update(2 * node + 1, m + 1, r, ql, qr, val);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr)
    {
        push(node, l, r);
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && qr >= r)
            return seg[node];
        ll m = l + (r - l) / 2;
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    SegTree st(n);
    while (m--)
    {
        ll type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            ll v;
            cin >> v;
            st.update(1, 0, n - 1, l, r - 1, v);
        }
        else
        {
            cout << st.query(1, 0, n - 1, l, r - 1) << "\n";
        }
    }
}