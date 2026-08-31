#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll maxv = n;
        ll idx;
        for(ll i=0; i<n; i++){
            if(arr[i]==maxv){
                idx = i;
                break;
            }
        }        
        vi v1; for(ll i=0; i<=idx; i++) v1.push_back(arr[i]);
        vi v2; for(ll i=idx; i<n; i++) v2.push_back(arr[i]);
        // for(auto a : v1) cout << a << " ";
        // cout << "\n";
        // for(auto a : v2) cout << a << " ";
        // cout << "\n";
        auto func = [](vi &v)->ll{
            ll m = v.size();
            vi pref(m), suff(m);
            set<ll> s;
            s.insert(v[0]);
            pref[0] = 1;
            for(ll i=1; i<m; i++){
                auto it = s.lower_bound(v[i]);
                if(it==s.begin()){
                    s.insert(v[i]);
                }else{
                    it--;
                    s.erase(it);
                    s.insert(v[i]);
                }
                pref[i] = s.size();
            }
            suff[m-1] = 1;
            s.clear();
            s.insert(v[m-1]);
            for(ll i=m-2; i>=0; i--){
                auto it = s.lower_bound(v[i]);
                if(it==s.begin()){
                    s.insert(v[i]);
                }else{
                    it--;
                    s.erase(it);
                    s.insert(v[i]);
                }
                suff[i] = s.size();
            }
            if(m==1) return 1;
            ll ans = 0;
            for(ll i=0; i<m-2; i++){
                ans = max(ans,pref[i]+suff[i+1]);
            }
            return ans;
        };
        ll res = func(v1);
        res = max(res,func(v2));
        cout << res << "\n";
    }
} 