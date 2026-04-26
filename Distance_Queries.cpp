#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct LCA
{
    int n, root, timer;
    vector<ll> seg, first, euler, depth;
    LCA(ll n, ll root, vector<vector<ll>> &adj)
    {
        this->n = n;
        this->root = root;
        first.assign(n, -1);
        euler.reserve(2 * n);
        depth.reserve(2 * n);
        timer = 0;
        dfs(0, -1, 0, adj);
        ll m = euler.size();
        seg.assign(4 * m + 1, 0);
        build(1, 0, m - 1);
    }
    void dfs(ll u, ll p, ll d, vector<vector<ll>> &adj)
    {
        first[u] = timer++;
        euler.push_back(u);
        depth.push_back(d);
        for (auto v : adj[u])
        {
            if (v != p)
            {
                dfs(v, u, d + 1, adj);
                timer++;
                euler.push_back(u);
                depth.push_back(d);
            }
        }
    }
    void build(ll node, ll l, ll r)
    {
        if (l == r)
        {
            seg[node] = l;
            return;
        }
        ll m = l + (r - l) / 2;
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);
        ll leftindex = seg[2 * node], rightindex = seg[2 * node + 1];
        seg[node] = (depth[leftindex] < depth[rightindex]) ? leftindex : rightindex;
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr)
    {
        if (ql > r || qr < l)
            return -1;
        if (ql <= l && qr >= r)
            return seg[node];
        ll m = l + (r - l) / 2;
        ll leftindex = query(2 * node, l, m, ql, qr);
        ll rightindex = query(2 * node + 1, m + 1, r, ql, qr);
        if (leftindex == -1)
            return rightindex;
        if (rightindex == -1)
            return leftindex;
        return (depth[leftindex] < depth[rightindex]) ? leftindex : rightindex;
    }
    ll get(ll u, ll v)
    {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        ll minindex = query(1, 0, euler.size() - 1, left, right);
        return euler[minindex];
    }
    ll getdistance(ll u, ll v)
    {
        ll lcanode = get(u, v);
        return depth[first[u]] + depth[first[v]] - 2 * depth[first[lcanode]];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    LCA lca(n, 0, adj);
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << lca.getdistance(a, b) << "\n";
    }
}