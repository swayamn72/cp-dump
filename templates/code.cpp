// ============================================================================
//  ICPC TEMPLATE LIBRARY
//  Merged from: pasted snippets + ICPC_NOTES.docx + ICPC_STUDY.docx
//  Everything lives under one mod/type system so pieces compose cleanly.
//  Copy out only what you need into your solution file.
// ============================================================================
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll   = long long;
using ull  = unsigned long long;
using i128 = __int128;
using vi   = vector<ll>;
using pll  = pair<ll,ll>;

ll MOD = 1e9 + 7;

// ============================================================================
// 0. PBDS ORDERED SET / MULTISET
// ============================================================================
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ordered multiset: pair second field is a unique tiebreaker (e.g. insertion timer)
template<typename T>
using omset = tree<pair<T, ll>, null_type, less<pair<T, ll>>, rb_tree_tag, tree_order_statistics_node_update>;

// kth smallest (0-indexed):      auto it = s.find_by_order(k);
// count strictly less than k:    ll a = s.order_of_key(k);
// (for omset)                    ll a = s.order_of_key({k, -1});
// count strictly greater than k: ll c = s.size() - s.order_of_key({k, (ll)1e18});

// ============================================================================
// 1. MODULAR ARITHMETIC — mulmod / binexp / modinv
// ============================================================================
ll mulmod(ll a, ll b, ll mod = MOD) {
    return (ll)((i128)a * b % mod);
}
ll binexp(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod; if (a < 0) a += mod;
    while (b > 0) {
        if (b & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}
ll modinv(ll a, ll mod = MOD) {
    return binexp(a, mod - 2, mod); // requires mod prime
}

// ============================================================================
// 2. EXTENDED GCD
// ============================================================================
int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// ============================================================================
// 3. MILLER-RABIN PRIMALITY TEST
// ============================================================================
bool checkcomposite(ll n, ll a, ll d, int s) {
    ll x = binexp(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = mulmod(x, x, n);
        if (x == n - 1) return false;
    }
    return true;
}
bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0) return n == p;
    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0) { d >>= 1; s++; }
    for (ll a : {2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL}) {
        if (a % n == 0) return true;
        if (checkcomposite(n, a, d, s)) return false;
    }
    return true;
}

// ============================================================================
// 4. EULER'S TOTIENT FUNCTION
// ============================================================================
// phi[1..n] in O(n log log n)
vi eulerSieve(ll n) {
    vi phi(n + 1);
    for (ll i = 0; i <= n; i++) phi[i] = i;
    for (ll i = 2; i <= n; i++)
        if (phi[i] == i)
            for (ll j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
    return phi;
}
// phi of a single n in O(sqrt n)
ll phiSingle(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

// ============================================================================
// 5. BRIDGES AND ARTICULATION POINTS
// ============================================================================
namespace BridgesAP {
    ll timer = 0;
    vi tin, low;
    vector<bool> vis;
    vector<pll> bridges;
    vi articulation;

    void dfsBridges(ll u, ll p, vector<vi> &adj) {
        vis[u] = true;
        tin[u] = low[u] = timer++;
        for (ll v : adj[u]) {
            if (v == p) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfsBridges(v, u, adj);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) bridges.push_back({min(u, v), max(u, v)});
            }
        }
    }

    void dfsAP(ll u, ll p, vector<vi> &adj) {
        vis[u] = true;
        tin[u] = low[u] = timer++;
        ll children = 0;
        for (ll v : adj[u]) {
            if (v == p) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfsAP(v, u, adj);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u] && p != -1) articulation.push_back(u);
                children++;
            }
        }
        if (p == -1 && children > 1) articulation.push_back(u);
    }

    void init(ll n) {
        timer = 0;
        tin.assign(n, -1); low.assign(n, -1); vis.assign(n, false);
        bridges.clear(); articulation.clear();
    }
}

// ============================================================================
// 6. nCr — factorial + inverse-factorial precompute (main method)
// ============================================================================
ll MAXN_NCR = 2e5 + 10;
vi fact, invFact;
void factandinv(ll maxn = -1, ll mod = MOD) {
    if (maxn < 0) maxn = MAXN_NCR;
    fact.assign(maxn, 1);
    invFact.assign(maxn, 1);
    for (ll i = 1; i < maxn; i++) fact[i] = mulmod(fact[i - 1], i, mod);
    invFact[maxn - 1] = modinv(fact[maxn - 1], mod);
    for (ll i = maxn - 2; i >= 0; i--) invFact[i] = mulmod(invFact[i + 1], i + 1, mod);
}
ll nCr(ll n, ll r, ll mod = MOD) {
    if (r < 0 || r > n) return 0;
    return mulmod(mulmod(fact[n], invFact[r], mod), invFact[n - r], mod);
}
// Small-r direct nCr, no precompute needed, unsigned overflow risk for large n*r — use only for small r.
ll nCrDirect(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    ll res = 1;
    for (ll i = 1; i <= r; i++) res = res * (n - i + 1) / i;
    return res;
}
// STARS AND BARS
//   (n+k-1) C (n) : ways to place n identical items into k bins, empty bins allowed
//   (n-1) C (k-1) : same, but every bin must be non-empty

// ============================================================================
// 7. TARJAN'S SCC
// ============================================================================
ll tarjanSCC(ll n, vector<vi> &edges) {
    vi tin(n, -1), low(n, -1), roots(n, -1), st;
    vector<vi> components, adj(n);
    for (auto &e : edges) adj[e[0]].push_back(e[1]);
    ll timer = 0;

    auto dfs = [&](auto &&self, ll u) -> void {
        low[u] = tin[u] = timer++;
        st.push_back(u);
        for (ll v : adj[u]) {
            if (tin[v] == -1) {
                self(self, v);
                low[u] = min(low[u], low[v]);
            } else if (roots[v] == -1) {
                low[u] = min(low[u], tin[v]);
            }
        }
        if (low[u] == tin[u]) {
            components.push_back({});
            while (true) {
                ll a = st.back(); st.pop_back();
                roots[a] = u;
                components.back().push_back(a);
                if (a == u) break;
            }
        }
    };

    for (ll i = 0; i < n; i++)
        if (tin[i] == -1) dfs(dfs, i);
    return (ll)components.size();
}

// ============================================================================
// 8. KOSARAJU'S SCC
// ============================================================================
ll kosaraju(ll n, vector<vi> &edges) {
    vector<vi> adj(n), revadj(n);
    for (auto &e : edges) { adj[e[0]].push_back(e[1]); revadj[e[1]].push_back(e[0]); }

    vector<bool> vis(n, false);
    vi order;
    auto dfs1 = [&](auto &&self, ll v, vector<vi> &graph) -> void {
        vis[v] = true;
        for (ll a : graph[v]) if (!vis[a]) self(self, a, graph);
        order.push_back(v);
    };
    auto dfs2 = [&](auto &&self, ll v, vector<vi> &graph) -> void {
        vis[v] = true;
        for (ll a : graph[v]) if (!vis[a]) self(self, a, graph);
    };

    for (ll i = 0; i < n; i++) if (!vis[i]) dfs1(dfs1, i, adj);
    reverse(order.begin(), order.end());

    ll res = 0;
    vis.assign(n, false);
    for (ll i : order) if (!vis[i]) { res++; dfs2(dfs2, i, revadj); }
    return res;
}

// ============================================================================
// 9. MO'S ALGORITHM
// ============================================================================
namespace Mo {
    vi freq;
    ll res = 0, blocksize;

    bool compare(const vi &a, const vi &b) {
        ll blocka = a[0] / blocksize, blockb = b[0] / blocksize;
        if (blocka != blockb) return blocka < blockb;
        if (blocka % 2 == 0) return a[1] < b[1];
        return a[1] > b[1];
    }
    void add(ll val)      { if (freq[val]++ == 0) res++; }
    void subtract(ll val) { if (freq[val]-- == 1) res--; }

    // arr: 0-indexed array, queries: {l, r} 1-indexed inclusive, returns ans per query (input order)
    vi solve(vi &arr, vector<pll> &queriesIn, ll maxVal = 1e6 + 5) {
        ll n = arr.size(), q = queriesIn.size();
        freq.assign(maxVal, 0); res = 0;
        blocksize = max(1LL, (ll)sqrt((double)n));
        vector<vi> queries(q);
        for (ll i = 0; i < q; i++) {
            ll l = queriesIn[i].first - 1, r = queriesIn[i].second - 1;
            queries[i] = {l, r, i};
        }
        sort(queries.begin(), queries.end(), compare);
        vi ans(q);
        ll curl = 0, curr = -1;
        for (auto &a : queries) {
            ll l = a[0], r = a[1];
            while (curl > l) { curl--; add(arr[curl]); }
            while (curr < r) { curr++; add(arr[curr]); }
            while (curl < l) { subtract(arr[curl]); curl++; }
            while (curr > r) { subtract(arr[curr]); curr--; }
            ans[a[2]] = res;
        }
        return ans;
    }
}

// ============================================================================
// 10. BELLMAN-FORD
// ============================================================================
// edges: {u, v, w}. Returns dist array; check adj negative cycle by running one extra pass.
vi bellmanFord(ll n, ll src, vector<vi> &edges) {
    vi dist(n, LLONG_MAX);
    dist[src] = 0;
    for (ll i = 0; i < n - 1; i++) {
        bool relaxed = false;
        for (auto &a : edges) {
            ll u = a[0], v = a[1], w = a[2];
            if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                relaxed = true;
            }
        }
        if (!relaxed) break;
    }
    return dist;
}

// ============================================================================
// 11. BINARY LIFTING LCA
// ============================================================================
struct BinaryLift {
    ll n, root, l, timer;
    vi tin, tout, depth;
    vector<vi> up;

    BinaryLift(ll n, ll root, vector<vi> &adj) {
        this->n = n; this->root = root; timer = 0;
        l = (ll)ceil(log2(max(2LL, n)));
        tin.resize(n); tout.resize(n); depth.resize(n);
        up.assign(n, vi(l + 1));
        dfs(root, root, 0, adj);
    }
    void dfs(ll u, ll p, ll d, vector<vi> &adj) {
        tin[u] = timer++;
        depth[u] = d;
        up[u][0] = p;
        for (ll i = 1; i <= l; i++) up[u][i] = up[up[u][i - 1]][i - 1];
        for (ll v : adj[u]) if (v != p) dfs(v, u, d + 1, adj);
        tout[u] = timer++;
    }
    bool isAncestor(ll u, ll v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
    ll lca(ll u, ll v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;
        for (ll i = l; i >= 0; i--)
            if (!isAncestor(up[u][i], v)) u = up[u][i];
        return up[u][0];
    }
};

// ============================================================================
// 12. MATRIX EXPONENTIATION (min-plus / shortest-path semiring)
// ============================================================================
struct Matrix {
    ll n;
    vector<vi> mat;
    Matrix(ll n) : n(n) { mat.assign(n, vi(n, LLONG_MAX)); }
};
Matrix matMultiply(Matrix &a, Matrix &b) {
    ll n = a.n;
    Matrix res(n);
    for (ll i = 0; i < n; i++)
        for (ll k = 0; k < n; k++) {
            if (a.mat[i][k] == LLONG_MAX) continue;
            for (ll j = 0; j < n; j++) {
                if (b.mat[k][j] == LLONG_MAX) continue;
                res.mat[i][j] = min(res.mat[i][j], a.mat[i][k] + b.mat[k][j]);
            }
        }
    return res;
}
Matrix matPower(Matrix a, ll k) {
    ll n = a.n;
    Matrix res(n);
    for (ll i = 0; i < n; i++) res.mat[i][i] = 0;
    while (k > 0) {
        if (k & 1) res = matMultiply(res, a);
        a = matMultiply(a, a);
        k >>= 1;
    }
    return res;
}
// For standard (+,*) matrix exponentiation (e.g. linear recurrences), replace
// matMultiply's min/+ with sum-of-products, and identity diagonal with 1s.

// ============================================================================
// 13. FORD-FULKERSON / EDMONDS-KARP MAX FLOW — O(V * E^2)
// ============================================================================
ll edmondsKarpBfs(ll source, ll sink, vector<vi> &adj, vector<vi> &capacity, vi &parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pll> q;
    q.push({source, LLONG_MAX});
    while (!q.empty()) {
        auto [curr, currflow] = q.front(); q.pop();
        for (ll a : adj[curr]) {
            if (parent[a] == -1 && capacity[curr][a] > 0) {
                parent[a] = curr;
                ll newflow = min(currflow, capacity[curr][a]);
                if (a == sink) return newflow;
                q.push({a, newflow});
            }
        }
    }
    return 0;
}
ll maxflow(ll n, ll source, ll sink, vector<vi> &adj, vector<vi> &capacity) {
    ll totalflow = 0;
    vi parent(n);
    ll newflow;
    while ((newflow = edmondsKarpBfs(source, sink, adj, capacity, parent))) {
        totalflow += newflow;
        ll curr = sink;
        while (curr != source) {
            ll prev = parent[curr];
            capacity[prev][curr] -= newflow;
            capacity[curr][prev] += newflow;
            curr = prev;
        }
    }
    return totalflow;
}

// ============================================================================
// 14. MOBIUS FUNCTION — linear sieve, O(N)
// ============================================================================
namespace Mobius {
    vector<int> mu, primes;
    vector<bool> isComposite;
    void build(int MAXN) {
        mu.assign(MAXN, 0);
        isComposite.assign(MAXN, false);
        primes.clear();
        mu[1] = 1;
        for (int i = 2; i < MAXN; i++) {
            if (!isComposite[i]) { primes.push_back(i); mu[i] = -1; }
            for (int p : primes) {
                if ((ll)i * p >= MAXN) break;
                isComposite[i * p] = true;
                if (i % p == 0) { mu[i * p] = 0; break; }
                else mu[i * p] = -mu[i];
            }
        }
    }
}
// Alternative O(N log N) sieve (simpler, use if N is small):
//   mu[1] = 1;
//   for (int i = 1; i < MAXN; i++)
//       for (int j = i * 2; j < MAXN; j += i) mu[j] -= mu[i];

// ============================================================================
// 15. LAZY SEGMENT TREE — range add, range sum
// ============================================================================
struct SegTreeLazyAdd {
    ll n;
    vi seg, lazyadd;

    SegTreeLazyAdd() {}
    SegTreeLazyAdd(ll n) : n(n) {
        seg.assign(4 * n + 1, 0);
        lazyadd.assign(4 * n + 1, 0);
    }
    void applyadd(ll node, ll l, ll r, ll val) {
        lazyadd[node] += val;
        seg[node] += val * (r - l + 1);
    }
    void push(ll node, ll l, ll r) {
        if (l == r) return;
        ll m = l + (r - l) / 2;
        if (lazyadd[node] != 0) {
            ll val = lazyadd[node];
            applyadd(2 * node, l, m, val);
            applyadd(2 * node + 1, m + 1, r, val);
            lazyadd[node] = 0;
        }
    }
    void updateadd(ll node, ll l, ll r, ll ql, ll qr, ll v) {
        if (qr < l || ql > r) return;
        if (ql <= l && qr >= r) { applyadd(node, l, r, v); return; }
        push(node, l, r);
        ll m = l + (r - l) / 2;
        updateadd(2 * node, l, m, ql, qr, v);
        updateadd(2 * node + 1, m + 1, r, ql, qr, v);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && qr >= r) return seg[node];
        push(node, l, r);
        ll m = l + (r - l) / 2;
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

// ============================================================================
// GENERIC (non-lazy) SEGMENT TREE SKELETON — fill in `type` and `merge`
// ============================================================================
/*
struct SegTreeGeneric {
    ll n; vi seg; // change vi -> vector<type> and identity value as needed

    SegTreeGeneric(ll n) : n(n) { seg.resize(4 * n + 1); }

    ll merge(ll a, ll b) { return a + b; } // <-- replace with your combine logic

    void build(ll node, ll l, ll r, vi &arr) {
        if (l == r) { seg[node] = arr[l]; return; }
        ll m = l + (r - l) / 2;
        build(2 * node, l, m, arr);
        build(2 * node + 1, m + 1, r, arr);
        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if (ql > r || qr < l) return 0; // <-- replace with identity element
        if (ql <= l && qr >= r) return seg[node];
        ll m = l + (r - l) / 2;
        return merge(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
    }
    void update(ll node, ll l, ll r, ll i, ll v) {
        if (l == r) { seg[node] = v; return; }
        ll m = l + (r - l) / 2;
        if (i <= m) update(2 * node, l, m, i, v);
        else update(2 * node + 1, m + 1, r, i, v);
        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }
};
*/

// ============================================================================
// 16. HEAVY-LIGHT DECOMPOSITION (vertex-based, uses SegTreeLazyAdd above)
// ============================================================================
struct HLD {
    ll n, timer;
    vi depth, size, parent, heavy, head, pos;
    SegTreeLazyAdd st;

    HLD(ll n, vector<vi> &adj) {
        this->n = n; timer = 0;
        depth.assign(n, 0); size.assign(n, 0); parent.assign(n, -1);
        heavy.assign(n, -1); head.assign(n, 0); pos.assign(n, 0);
        st = SegTreeLazyAdd(n);
        dfs1(0, -1, 0, adj);
        dfs2(0, -1, 0, adj);
    }
    void dfs1(ll u, ll p, ll d, vector<vi> &adj) {
        parent[u] = p; depth[u] = d; size[u] = 1;
        ll maxsub = 0;
        for (ll v : adj[u]) {
            if (v == p) continue;
            dfs1(v, u, d + 1, adj);
            size[u] += size[v];
            if (size[v] > maxsub) { maxsub = size[v]; heavy[u] = v; }
        }
    }
    void dfs2(ll u, ll p, ll h, vector<vi> &adj) {
        head[u] = h; pos[u] = timer++;
        if (heavy[u] != -1) dfs2(heavy[u], u, h, adj);
        for (ll v : adj[u]) {
            if (v == p || v == heavy[u]) continue;
            dfs2(v, u, v, adj);
        }
    }
    void updatepath(ll u, ll v, ll val) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            st.updateadd(1, 0, n - 1, pos[head[u]], pos[u], val);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        // Edge update note: if updating edges (not vertices), use pos[u]+1 below
        st.updateadd(1, 0, n - 1, pos[u], pos[v], val);
    }
    ll querypath(ll u, ll v) {
        ll res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            res += st.query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        // Edge query note: if querying edges (not vertices), use pos[u]+1 below
        res += st.query(1, 0, n - 1, pos[u], pos[v]);
        return res;
    }
};

// ============================================================================
// 17. CENTROID DECOMPOSITION — count paths of length exactly k
// ============================================================================
struct CD {
    ll n, k, paths, maxdepth;
    vector<bool> removed;
    vi subtree, count;

    CD(ll n, ll k) : n(n), k(k) {
        removed.assign(n, false);
        subtree.assign(n, 0);
        count.assign(n + 1, 0);
        maxdepth = 0; paths = 0;
    }
    ll getsubtreesize(ll u, ll p, vector<vi> &adj) {
        subtree[u] = 1;
        for (ll v : adj[u]) {
            if (v == p || removed[v]) continue;
            subtree[u] += getsubtreesize(v, u, adj);
        }
        return subtree[u];
    }
    ll getcentroid(ll u, ll p, ll treesize, vector<vi> &adj) {
        for (ll v : adj[u]) {
            if (v == p || removed[v]) continue;
            if (subtree[v] > treesize / 2) return getcentroid(v, u, treesize, adj);
        }
        return u;
    }
    void getdist(ll u, ll p, ll dist, bool iscounting, vector<vi> &adj) {
        if (dist > k) return;
        if (iscounting) {
            paths += count[k - dist];
        } else {
            count[dist]++;
            maxdepth = max(maxdepth, dist);
        }
        for (ll v : adj[u]) {
            if (v == p || removed[v]) continue;
            getdist(v, u, dist + 1, iscounting, adj);
        }
    }
    void processcentroid(ll centroid, vector<vi> &adj) {
        maxdepth = 0;
        count[0] = 1;
        for (ll v : adj[centroid]) {
            if (removed[v]) continue;
            getdist(v, centroid, 1, true, adj);
            getdist(v, centroid, 1, false, adj);
        }
        fill(count.begin() + 1, count.begin() + maxdepth + 1, 0);
    }
    void decompose(ll u, vector<vi> &adj) {
        ll treesize = getsubtreesize(u, -1, adj);
        ll centroid = getcentroid(u, -1, treesize, adj);
        processcentroid(centroid, adj);
        removed[centroid] = true;
        for (ll v : adj[centroid])
            if (!removed[v]) decompose(v, adj);
    }
    ll solve(vector<vi> &adj) {
        decompose(0, adj);
        return paths;
    }
};

// ============================================================================
// 18. SOS DP (Sum over Subsets)
// ============================================================================
// dp initialized with dp[mask] = initial_value[mask] before calling.
void sosDP(vector<int> &dp, int N, bool countingVariant /* false = propagation */) {
    for (int i = 0; i < N; i++) {
        for (int mask = (1 << N) - 1; mask >= 0; mask--) {
            if (mask & (1 << i)) {
                if (!countingVariant) {
                    // TYPE A: Subsequence/Subset Propagation
                    if (dp[mask] != 0) dp[mask ^ (1 << i)] = dp[mask];
                } else {
                    // TYPE B: Summing Over Subsets (counting problems)
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }
    }
}

// ============================================================================
// 19. KMP
// ============================================================================
// Returns first index in s where p occurs, or -1. (Adapt to collect all matches if needed.)
int kmp(string s, string p) {
    int n = s.size(), m = p.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (p[i] == p[len]) {
            len++; lps[i] = len; i++;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            i++;
        }
    }
    int j = 0; i = 0;
    while (i < n) {
        if (s[i] == p[j]) { i++; j++; }
        if (j == m) return i - m;
        else if (i < n && s[i] != p[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}

// ============================================================================
// 20. SUM AND NUMBER OF DIVISORS (prime factorization)
// ============================================================================
// N = p1^k1 * p2^k2 * ... * pn^kn
//   Number of divisors = (k1+1)(k2+1)...(kn+1)
//   Sum of divisors     = product of (p^(k+1) - 1) / (p - 1) over each prime factor
//   Modulo trap: if (p-1) % mod == 0 you cannot invert (p-1); the geometric-series
//     term degenerates to just (k+1) % mod.
//   Exponent reduction: p^(k*B + 1) reduces the exponent mod (mod - 1) via Fermat
//     (requires mod prime and gcd(p, mod) == 1).

// Returns sum of divisors of (a^b) modulo mod, in O(sqrt(a)).
ll sum_of_divisors(ll a, ll b, ll mod) {
    if (a == 1 || b == 0) return 1;
    ll res = 1;
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            ll k = 0;
            while (a % i == 0) { k++; a /= i; }
            if ((i - 1) % mod == 0) {
                ll terms = (k * b + 1) % mod;
                res = mulmod(res, terms, mod);
            } else {
                ll exp = ((k % (mod - 1)) * (b % (mod - 1)) + 1) % (mod - 1);
                ll num = (binexp(i, exp, mod) - 1 + mod) % mod;
                ll den = modinv(i - 1, mod);
                res = mulmod(res, mulmod(num, den, mod), mod);
            }
        }
    }
    if (a > 1) { // a is prime > sqrt(initial a)
        if ((a - 1) % mod == 0) {
            ll terms = (b + 1) % mod;
            res = mulmod(res, terms, mod);
        } else {
            ll exp = (b % (mod - 1) + 1) % (mod - 1);
            ll num = (binexp(a, exp, mod) - 1 + mod) % mod;
            ll den = modinv(a - 1, mod);
            res = mulmod(res, mulmod(num, den, mod), mod);
        }
    }
    return res;
}

// Divide & conquer geometric series: (1 + p + p^2 + ... + p^x) % mod.
// Use when mod is NOT prime (so modular inverse is unavailable).
ll geometric_sum(ll p, ll x, ll mod) {
    if (x == 0) return 1;
    if (x == 1) return (1 + p) % mod;
    if (x % 2 == 1) {
        ll half = geometric_sum(p, x / 2, mod);
        ll factor = (1 + binexp(p, (x + 1) / 2, mod)) % mod;
        return mulmod(half, factor, mod);
    } else {
        ll sum_minus_one = geometric_sum(p, x - 1, mod);
        ll last_term = binexp(p, x, mod);
        return (sum_minus_one + last_term) % mod;
    }
}

// ============================================================================
// 21. TERNARY SEARCH (unimodal function f; here set up for MINIMUM)
// ============================================================================
ll f(ll x); // define elsewhere — must be unimodal over [l, r]

ll ternarysearch(ll l, ll r) {
    while (r - l > 2) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    ll ans_val = LLONG_MAX;
    for (ll i = l; i <= r; i++) {
        ll current_val = f(i);
        if (current_val < ans_val) ans_val = current_val; // flip to > for MAXIMUM
    }
    return ans_val;
}

// ============================================================================
// 22. DIGIT DP — count of digit '1' across [0, n]
// ============================================================================
// General digit-DP shape: dp[idx][state][tight] = number of ways to fill
// positions idx..len-1 given `state` accumulated so far and whether the
// prefix is still tight (bounded by n's digits). Swap `state` (here just a
// count) and the transition for whatever you're actually counting.
ll countDigitOne(ll n) {
    string s = to_string(n);
    ll len = s.size();
    // dp[idx][count][tight]
    vector<vector<array<ll, 2>>> dp(len + 1, vector<array<ll, 2>>(len + 2, {0, 0}));
    dp[0][0][1] = 1;
    for (ll idx = 0; idx < len; idx++) {
        for (ll count = 0; count <= idx; count++) {
            for (ll tight = 0; tight < 2; tight++) {
                if (dp[idx][count][tight] == 0) continue;
                ll limit = tight ? s[idx] - '0' : 9;
                for (ll d = 0; d <= limit; d++) {
                    ll nexttight = tight && (d == limit);
                    ll nextcount = count + (d == 1);
                    dp[idx + 1][nextcount][nexttight] += dp[idx][count][tight];
                }
            }
        }
    }
    ll res = 0;
    for (ll count = 0; count <= len; count++) {
        res += count * dp[len][count][0];
        res += count * dp[len][count][1];
    }
    return res;
}
// Memoized-recursion skeleton (often easier to adapt than the tabulated form
// above — swap `state` for whatever you're tracking, e.g. digit sum, last
// digit, mod-k remainder, tight bound, leading-zero flag, etc.):
/*
string s;
ll memo[20][STATE_RANGE][2];
bool visited[20][STATE_RANGE][2];

ll rec(ll idx, ll state, bool tight) {
    if (idx == (ll)s.size()) return state; // or whatever terminal value you need
    if (!tight && visited[idx][state][tight]) return memo[idx][state][tight];
    ll limit = tight ? s[idx] - '0' : 9;
    ll res = 0;
    for (ll d = 0; d <= limit; d++) {
        ll nextstate = state; // update based on d
        res += rec(idx + 1, nextstate, tight && d == limit);
    }
    if (!tight) { visited[idx][state][tight] = true; memo[idx][state][tight] = res; }
    return res;
}
// call: s = to_string(n); rec(0, 0, true);
*/

// ============================================================================
// __int128 PRINT HELPER
// ============================================================================
void print128(__int128 n) {
    if (n == 0) { cout << 0 << "\n"; return; }
    bool neg = n < 0;
    if (neg) n = -n;
    string s;
    while (n > 0) { s += (char)('0' + (int)(n % 10)); n /= 10; }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

// ============================================================================
// MISC NOTES 
// ============================================================================
// Coupon collector's problem: expected number of trials to collect all k
//   distinct items is roughly k * ln(k).
// For a forest: number of connected components = (number of vertices) - (number of edges).

// ============================================================================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Template library — paste the sections you need above into your solution.

    return 0;
}