#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    map<ll,vi> cache;
    auto ask = [&](ll k)->vi{
        if(cache.count(k)) return cache[k];
        cout << "? " << k << endl;
        ll q; cin >> q;
        vi v; 
        if(!q){
            cache[k] = v;
            return v;
        }
        v.resize(q);
        for(auto &x : v) cin >> x;
        cache[k] = v;
        return v;
    };
    while(t--){
        cache.clear();
        ll n; cin >> n;
        vector<pair<ll,ll>> edges;
        ll currl = 1;
        for(ll u=1; u<=n; u++){
            ll vlast = 0;
            while(true){
                ll l = currl, r = (1LL<<30);
                ll ans = r+1;
                while(l<=r){
                    ll m = l + (r-l)/2;
                    vi p = ask(m);
                    bool flag = false;
                    if(p.empty()){
                        flag = true;
                    }else if(p[0]>u){
                        flag = true;
                    }else if(p[0]<u){
                        flag = false;
                    }else{
                        if(p.size()==1){
                            flag = false;
                        }else{
                            if(p[1]>vlast) flag = true;
                            else flag = false;
                        }
                    }
                    if(flag){
                        ans = m;
                        r=m-1;
                    }else{
                        l=m+1;
                    }
                }
                vi p = ask(ans);
                if(p.empty()||p[0]>u){
                    currl = ans;
                    break;
                }
                ll vnew = p[1];
                edges.push_back({u,vnew});
                vlast = vnew;
                currl = ans+1;
            }
        }
        cout << "! " << edges.size() << endl;
        for(auto [a,b] : edges){
            cout << a << " " << b << endl;
        }
    }
}