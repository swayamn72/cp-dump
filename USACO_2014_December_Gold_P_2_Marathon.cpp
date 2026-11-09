#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct SegTreeSum{
    ll n; vi seg;
    SegTreeSum(ll n){
        this->n = n;
        seg.resize(4*n+1);
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = seg[2*node]+seg[2*node+1];
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return 0LL;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return query(2*node,l,m,ql,qr) + query(2*node+1,m+1,r,ql,qr);
    }
};
struct SegTreeMax{
    ll n; vi seg;
    SegTreeMax(ll n){
        this->n = n;
        seg.resize(4*n+1);
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return 0LL;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return max(query(2*node,l,m,ql,qr),query(2*node+1,m+1,r,ql,qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vector<pair<ll,ll>> arr(n); 
        for(auto &[a,b] : arr) cin >> a >> b;
        vi diff(n,0);
        for(ll i=1; i<n-1; i++){
            auto [x,y] = arr[i];
            auto [a,b] = arr[i-1];
            auto [p,q] = arr[i+1];
            ll dist1 = abs(a-x)+abs(b-y);
            ll dist2 = abs(p-x)+abs(q-y);
            ll dist3 = abs(a-p)+abs(b-q);
            diff[i] = dist1+dist2-dist3;
        }
        vi sumarr(n,0);
        for(ll i=1; i<n; i++){
            auto [x,y] = arr[i];
            auto [a,b] = arr[i-1];
            ll dist = abs(x-a)+abs(y-b);
            sumarr[i] = dist;
        }
        auto getdist = [](pair<ll,ll> a, pair<ll,ll> b)->ll{
            return abs(a.first-b.first) + abs(a.second-b.second);
        };
        SegTreeSum sts(n);
        sts.build(1,0,n-1,sumarr);
        SegTreeMax stm(n);
        stm.build(1,0,n-1,diff);
        while(q--){
            char ch; cin >> ch;
            if(ch=='U'){
                ll i,x,y; cin >> i >> x >> y; i--;
                arr[i] = {x,y};
                if(i > 0){
                    sumarr[i] = getdist(arr[i-1], arr[i]);
                    sts.update(1, 0, n-1, i, sumarr[i]);
                }
                if(i < n-1){
                    sumarr[i+1] = getdist(arr[i], arr[i+1]);
                    sts.update(1, 0, n-1, i+1, sumarr[i+1]);
                }

                for(ll k = i-1; k <= i+1; k++){
                    if(k > 0 && k < n-1){
                        ll d1 = getdist(arr[k-1], arr[k]);
                        ll d2 = getdist(arr[k], arr[k+1]);
                        ll d3 = getdist(arr[k-1], arr[k+1]);
                        diff[k] = d1 + d2 - d3;
                        stm.update(1, 0, n-1, k, diff[k]);
                    }
                }
            }else if(ch=='Q'){
                ll l, r; cin >> l >> r; l--; r--;
                ll totaldist = sts.query(1, 0, n-1, l+1, r);
                ll maxsavings = 0;
                if(l + 1 <= r - 1){
                    maxsavings = stm.query(1, 0, n-1, l+1, r-1);
                }
                
                cout << totaldist - maxsavings << "\n";
            }
        }
    }
}