#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m,x,y; cin >> n >> m >> x >> y;
        vi a(x); for(auto &p : a) cin >> p;
        vi b(y); for(auto &p : b) cin >> p;

        set<ll> s1; for(auto p : a) s1.insert(p);
        set<ll> s2; for(auto p : b) s2.insert(p);
        set<ll> s3;
        for(auto p : s1) if(s2.count(p)){
            s3.insert(p); 
        }
        for(auto p : s3){
            s2.erase(p);
            s1.erase(p);
        }
        vector<vector<ll>> v;
        for(auto p : s1) v.push_back({p,1});
        for(auto p : s2) v.push_back({p,2});
        for(auto p : s3) v.push_back({p,3});
        sort(v.rbegin(),v.rend());

        ll one=0, two=0, both=0;
        ll res = 0;
        for(auto p : v){
            if(one+two+both>=(n+m-1)) break;
            if(p[1]==1){
                if(one<n){
                    one++;
                    res += p[0];
                }
            }else if(p[1]==2){
                if(two<m){
                    two++;
                    res += p[0];
                }
            }else{
                both++;
                res += p[0];
            }
        }
        cout << res << "\n";
    }
}
