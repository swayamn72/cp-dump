#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
ll inf = 1e18;
struct SegTree{
    ll n; vi seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,inf);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r) {
            seg[node] = min(seg[node], v);
            return;
        }
        ll m = l + (r - l) / 2;
        if(i <= m) update(2 * node, l, m, i, v);
        else update(2 * node + 1, m + 1, r, i, v);
        seg[node] = min(seg[2 * node], seg[2 * node + 1]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if(ql > r || qr < l) {
            return inf;
        }
        if(ql <= l && qr >= r) {
            return seg[node];
        }
        ll m = l + (r - l) / 2;
        return min(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,p; cin >> n >> p;
        vi yval = {0,n};
        vector<vi> events;
        for(ll i=0; i<p; i++){
            ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            events.push_back({x1,y1,2,i}); // start
            events.push_back({x2,y2,1,i}); // end
            yval.push_back(y1); yval.push_back(y2);
        }
        events.push_back({n,n,2,p});
        sort(yval.begin(),yval.end());
        yval.erase(unique(yval.begin(), yval.end()), yval.end());
    
        auto gety = [&](ll y) {
            return lower_bound(yval.begin(), yval.end(), y) - yval.begin();
        };
        sort(events.begin(),events.end());
        ll numy = yval.size();
        SegTree st(numy);
        st.update(1, 0, numy-1, gety(0), 0);
        vi res(p+1,inf);
        for(auto e : events){
            ll x = e[0], y = e[1];
            ll type = e[2], id = e[3];
            ll compy = gety(y);
        
            if(type == 2) {
                // START event: Find the best previous springboard ending at y_end <= y
                ll min_val = st.query(1, 0, numy - 1, 0, compy);
                res[id] = min_val + x + y;
            } 
            else if (type == 1) {
                // END event: Make this springboard available to future STARTs
                ll val = res[id] - x - y;
                st.update(1, 0, numy - 1, compy, val);
            }
        }
        cout << res[p];
    }
}