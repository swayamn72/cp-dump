#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree2D {
    int n, m;
    vector<vector<ll>> tree;
    SegTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        tree.assign(4 * n + 1, vector<ll>(4 * m + 1, 0));
    }
    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, ll val) {
        if (ly == ry) {
            if (lx == rx) {
                tree[vx][vy] += val; 
            } else {
                tree[vx][vy] = tree[2 * vx][vy] + tree[2 * vx + 1][vy];
            }
        } else {
            int my = ly + (ry - ly) / 2;
            if (y <= my) update_y(vx, lx, rx, 2 * vy, ly, my, x, y, val);
            else update_y(vx, lx, rx, 2 * vy + 1, my + 1, ry, x, y, val);
            tree[vx][vy] = tree[vx][2 * vy] + tree[vx][2 * vy + 1];
        }
    }

    ll query_y(int vx, int vy, int ly, int ry, int qly, int qry) {
        if (qly > ry || qry < ly) return 0;
        if (qly <= ly && ry <= qry) return tree[vx][vy];
        
        int my = ly + (ry - ly) / 2;
        return query_y(vx, 2 * vy, ly, my, qly, qry) 
             + query_y(vx, 2 * vy + 1, my + 1, ry, qly, qry);
    }
    void update_x(int vx, int lx, int rx, int x, int y, ll val) {
        if (lx != rx) {
            int mx = lx + (rx - lx) / 2;
            if (x <= mx) update_x(2 * vx, lx, mx, x, y, val);
            else update_x(2 * vx + 1, mx + 1, rx, x, y, val);
        }
        update_y(vx, lx, rx, 1, 1, m, x, y, val);
    }

    ll query_x(int vx, int lx, int rx, int qlx, int qrx, int qly, int qry) {
        if (qlx > rx || qrx < lx) return 0;
        if (qlx <= lx && rx <= qrx) return query_y(vx, 1, 1, m, qly, qry);
        
        int mx = lx + (rx - lx) / 2;
        return query_x(2 * vx, lx, mx, qlx, qrx, qly, qry) 
             + query_x(2 * vx + 1, mx + 1, rx, qlx, qrx, qly, qry);
    }
    // Point Update
    void add(int x, int y, ll v) {
        update_x(1, 1, n, x, y, v);
    }
    ll range_query(int x1, int y1, int x2, int y2) {
        return query_x(1, 1, n, x1, x2, y1, y2);
    }
};