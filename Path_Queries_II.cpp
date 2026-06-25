#include <bits/stdc++.h>
using namespace std;

// Using standard int instead of long long to prevent CPU cache misses
// Max value in problem is 10^9, which easily fits in signed 32-bit int.

struct IterativeSegTree {
    int n;
    vector<int> seg;
    
    IterativeSegTree() {}
    
    // Bottom-up initialization
    IterativeSegTree(int n, vector<int>& arr) {
        this->n = n;
        seg.assign(2 * n, 0);
        // Insert leaves
        for (int i = 0; i < n; i++) {
            seg[n + i] = arr[i];
        }
        // Build the tree by calculating parents
        for (int i = n - 1; i > 0; --i) {
            seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
        }
    }
    
    void update(int i, int v) {
        // Jump straight to the leaf, then climb up using bitwise shifts
        for (seg[i += n] = v; i > 1; i >>= 1) {
            seg[i >> 1] = max(seg[i], seg[i ^ 1]);
        }
    }
    
    int query(int l, int r) {
        int res = 0;
        // l and r point to leaves. Move them upwards and merge.
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, seg[l++]);
            if (r & 1) res = max(res, seg[--r]);
        }
        return res;
    }
};

struct HLD {
    int n, timer;
    vector<int> depth, size, parent, heavy, head, pos;
    IterativeSegTree st;
    
    HLD(int n, vector<vector<int>>& adj, vector<int>& arr) {
        this->n = n;
        timer = 0;
        depth.resize(n, 0);
        size.resize(n, 0);
        parent.resize(n, -1);
        heavy.resize(n, -1);
        head.resize(n, 0);
        pos.resize(n, 0);
        
        dfs1(0, -1, 0, adj);
        dfs2(0, -1, 0, adj);
        
        vector<int> flatarr(n);
        for(int i = 0; i < n; i++){
            flatarr[pos[i]] = arr[i];
        }
        st = IterativeSegTree(n, flatarr);
    }
    
    void dfs1(int u, int p, int d, vector<vector<int>>& adj) {
        parent[u] = p;
        depth[u] = d;
        size[u] = 1;
        int maxsub = 0;
        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs1(v, u, d + 1, adj);
            size[u] += size[v];
            if(size[v] > maxsub) {
                maxsub = size[v];
                heavy[u] = v;
            }
        }
    }
    
    void dfs2(int u, int p, int h, vector<vector<int>>& adj) {
        head[u] = h;
        pos[u] = timer++;
        if(heavy[u] != -1) dfs2(heavy[u], u, h, adj);
        for(auto v : adj[u]) {
            if(v == p || v == heavy[u]) continue;
            dfs2(v, u, v, adj);
        }
    }
    
    void updatenode(int u, int val) {
        st.update(pos[u], val);
    } 
    
    int querypath(int u, int v) {
        int res = 0;
        while(head[u] != head[v]) {
            if(depth[head[u]] < depth[head[v]]) swap(u, v);
            res = max(res, st.query(pos[head[u]], pos[u]));
            u = parent[head[u]];
        }
        if(depth[u] > depth[v]) swap(u, v);
        res = max(res, st.query(pos[u], pos[v]));
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q; 
    cin >> n >> q; 
    
    vector<int> arr(n); 
    for(auto &x : arr) cin >> x;
    
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    HLD hld(n, adj, arr);
    
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int s, x; cin >> s >> x;
            s--;
            hld.updatenode(s, x);
        } else {
            int a, b; cin >> a >> b;
            a--; b--;
            cout << hld.querypath(a, b) << " ";
        }
    }
    cout << "\n";
    return 0;
}