#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
struct Fenwick{
    ll n,m; 
    vector<vi> bits;
    Fenwick(ll n, ll m){
        this->n = n;
        this->m = m;
        bits.assign(n+1,vi(m+1,0));
    }
    void add(ll x, ll y, ll v){
        for(ll i=x; i<=n; i+=(i&-i)){
            for(ll j=y; j<=m; j+=(j&-j)){
                bits[i][j] ^= v;
            }
        }
    }
    ll query(ll x, ll y){
        ll res = 0;
        for(ll i=x; i>0; i-=(i&-i)){
            for(ll j=y; j>0; j-=(j&-j)){
                res ^= bits[i][j];
            }
        }
        return res;
    }
    void rangeadd(ll x1, ll y1, ll x2, ll y2, ll v){
        add(x1,y1,v);
        add(x2+1,y1,v);
        add(x1,y2+1,v);
        add(x2+1,y2+1,v);
    }
};
// struct SegTree2d{
//     ll n,m;
//     vector<vi> seg;
//     SegTree2d(ll n, ll m){
//         this->n = n;
//         this->m = m;
//         seg.assign(4*n+1,vi(4*m+1,0));
//     }
//     void updatey(int vx, int vy, int ly, int ry, int qly, int qry, ll val) {
//         if (qly > ry || qry < ly) return;
//         if (qly <= ly && ry <= qry) {
//             seg[vx][vy] ^= val;
//             return;
//         }
        
//         int my = ly + (ry - ly) / 2;
//         updatey(vx, 2 * vy, ly, my, qly, qry, val);
//         updatey(vx, 2 * vy + 1, my + 1, ry, qly, qry, val);
//     }
//     ll queryy(int vx, int vy, int ly, int ry, int qy) {
//         ll res = seg[vx][vy];
//         if (ly == ry) return res;
//         int my = ly + (ry - ly) / 2;
//         if (qy <= my) {
//             res ^= queryy(vx, 2 * vy, ly, my, qy);
//         } else {
//             res ^= queryy(vx, 2 * vy + 1, my + 1, ry, qy);
//         }
//         return res;
//     }
//     void updatex(int vx, int lx, int rx, int qlx, int qrx, int qly, int qry, ll val) {
//         if (qlx > rx || qrx < lx) return;
//         if (qlx <= lx && rx <= qrx) {
//             updatey(vx, 1, 1, m, qly, qry, val);
//             return;
//         }
//         int mx = lx + (rx - lx) / 2;
//         updatex(2 * vx, lx, mx, qlx, qrx, qly, qry, val);
//         updatex(2 * vx + 1, mx + 1, rx, qlx, qrx, qly, qry, val);
//     }
//     ll queryx(int vx, int lx, int rx, int qx, int qy) {
//         ll res = queryy(vx, 1, 1, m, qy);
//         if (lx == rx) return res;
//         int mx = lx + (rx - lx) / 2;
//         if (qx <= mx) {
//             res ^= queryx(2 * vx, lx, mx, qx, qy);
//         } else {
//             res ^= queryx(2 * vx + 1, mx + 1, rx, qx, qy);
//         }
//         return res;
//     }
//     void rangeadd(int x1, int y1, int x2, int y2, ll val) {
//         updatex(1, 1, n, x1, x2, y1, y2, val);
//     }
//     ll pointquery(int x, int y) {
//         return queryx(1, 1, n, x, y);
//     }
// };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m,q; cin >> n >> m >> q;
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        map<vi,ll> mp;
        Fenwick ft(n,m);
        while(q--){
            ll type; cin >> type;
            ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            if(type==1){
                ll rnd = rng();
                mp[{r1,c1,r2,c2}] = rnd;
                ft.rangeadd(r1,c1,r2,c2,rnd);
            }else if(type==2){
                ll v = mp[{r1,c1,r2,c2}];
                ft.rangeadd(r1,c1,r2,c2,v);
            }else{
                if(ft.query(r1,c1)==ft.query(r2,c2)){
                    cout << "Yes" << "\n";
                }else{
                    cout << "No" << "\n";
                }
            }
        }
    }
} 