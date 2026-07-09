#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, 
rb_tree_tag, tree_order_statistics_node_update> omset;
ll mod = 998244353;
struct Fenwick{
    ll n; vi tree;
    Fenwick(ll n){
        this->n = n;
        tree.resize(4*n+1,0);
    }
    void add(ll idx, ll delta){
        for(ll i=idx; i<=n; i+=(i&-i)){
            tree[i] += delta;
        }
    }
    ll query(ll idx){
        ll sum = 0;
        for(ll i=idx; i>0; i-=(i&-i)) sum += tree[i];
        return sum;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto binexp = [](ll a, ll b)->ll{
        ll res = 1;
        while(b>0){
            if(b&1) res = (res*a)%mod;
            a = (a*a)%mod;
            b>>=1;
        }
        return res;
    };
    ll fact[2005];
    fact[0] = 1;
    for(ll i=1; i<2005; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        if(n==1){
            cout << 0 << "\n";
            continue;
        }
        ll inva = 0;
        for(ll i=0; i<n; i++){
            for(ll j=i+1; j<n; j++){
                if(a[i]>a[j]) inva++;
            }
        }
        vi arr;
        
        vector<vector<ll>> v(n, vector<ll>(n));
        for(ll i=0; i<n; i++){
            ll val = a[i];
            for(ll j=0; j<n; j++){
                v[i][j] = val * b[j];
                arr.push_back(v[i][j]);
            }
            sort(v[i].begin(),v[i].end());
        }        
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        auto getid = [&](ll x){
            return lower_bound(arr.begin(),arr.end(),x) - arr.begin() + 1;
        };
        Fenwick ft(arr.size());
        ll count = 0;
        ll inserted = 0;
        for(ll i=0; i<n; i++){
            ft.add(getid(v[0][i]),1);
            inserted++;
        }
        for(ll i=1; i<n; i++){

            for(ll j=0; j<n; j++){
                ll val = v[i][j];
                ll id = getid(val);
                ll dist = inserted - ft.query(id);
                count = (count+dist)%mod;
            }

            for(ll j=0; j<n; j++){
                ft.add(getid(v[i][j]),1);
                inserted++;
            }
        }
        count = (count-(inva*n)%mod + mod)%mod;
        ll den = n*(n-1)%mod;
        ll inve = binexp(den,mod-2);
        ll res = (count*inve)%mod;
        cout << res << "\n";
    }
}