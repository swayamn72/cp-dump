#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n; 
    vector<int> tree;
    
    Fenwick() {}
    Fenwick(int n) {
        this->n = n;
        tree.assign(n + 1, 0); // assign is slightly faster than resize
    }
    
    void add(int i, int v) {
        i++;
        while (i <= n) {
            tree[i] += v;
            i += (i & -i);
        }
    }
    
    int query(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }
    
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

struct CD {
    int n, k1, k2, maxdepth;
    long long paths; // ONLY paths should be 64-bit long long!
    vector<bool> removed;
    vector<int> subtree, count;
    Fenwick ft;

    CD(int n, int k1, int k2) {
        this->n = n;
        this->k1 = k1;
        this->k2 = k2;
        removed.assign(n, false);
        subtree.assign(n, 0);
        // We only care about distances up to k2, saving massive memory
        count.assign(k2 + 1, 0); 
        maxdepth = 0;
        paths = 0;
        ft = Fenwick(k2 + 2); // Cap the BIT size at k2
    }

    // Pass adjacency list as const reference to absolutely guarantee no copies
    int getsubtreesize(int u, int p, const vector<vector<int>>& adj) {
        subtree[u] = 1;
        for (auto v : adj[u]) {
            if (v == p || removed[v]) continue;
            subtree[u] += getsubtreesize(v, u, adj); 
        }
        return subtree[u];
    }

    int getcentroid(int u, int p, int treesize, const vector<vector<int>>& adj) {
        for (auto v : adj[u]) {
            if (v == p || removed[v]) continue;
            if (subtree[v] > (treesize / 2)) {
                return getcentroid(v, u, treesize, adj);
            }
        }
        return u;
    }

    void getdist(int u, int p, int dist, bool iscounting, const vector<vector<int>>& adj) {
        if (dist > k2) return;
        
        if (iscounting) {
            int ql = max(0, k1 - dist);
            int qr = k2 - dist; // No need to min with n anymore
            if (ql <= qr) {
                paths += ft.query(ql, qr);
            }
        } else {
            count[dist]++;
            ft.add(dist, 1);
            maxdepth = max(maxdepth, dist);
        } 
        
        for (auto v : adj[u]) {
            if (v == p || removed[v]) continue;
            getdist(v, u, dist + 1, iscounting, adj);
        }
    }

    void processcentroid(int centroid, const vector<vector<int>>& adj) {
        maxdepth = 0;
        count[0] = 1;
        ft.add(0, 1);
        
        for (auto v : adj[centroid]) {
            if (removed[v]) continue;
            getdist(v, centroid, 1, true, adj);
            getdist(v, centroid, 1, false, adj);
        }
        
        for (int i = 0; i <= maxdepth; i++) {
            if (count[i] > 0) {
                ft.add(i, -count[i]);
                count[i] = 0;
            }
        }
    }

    void decompose(int u, const vector<vector<int>>& adj) {
        int treesize = getsubtreesize(u, -1, adj);
        int centroid = getcentroid(u, -1, treesize, adj);
        
        processcentroid(centroid, adj);
        removed[centroid] = true;
        
        for (auto v : adj[centroid]) {
            if (!removed[v]) {
                decompose(v, adj);
            }
        }
    }

    long long solve(const vector<vector<int>>& adj) {
        decompose(0, adj);
        return paths;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k1, k2; 
    cin >> n >> k1 >> k2;
    
    vector<vector<int>> adj(n); 
    for (int i = 0; i < n - 1; i++) {
        int u, v; 
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    CD cd(n, k1, k2);
    cout << cd.solve(adj) << "\n";
    
    return 0;
}