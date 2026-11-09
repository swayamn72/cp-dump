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
    while(t--){
        ll s,q; cin >> s >> q;
        set<ll> divisors;
        for(ll i=1; i*i<=s; i++){
            if(s%i==0){
                divisors.insert(i);
                divisors.insert(s/i);
            }
        }
        vector<pair<ll,ll>> v1,v2; 
        for(auto a : divisors){
            // v1.push_back({a,s/a});
            v2.push_back({s/a,a});
        }
        sort(v2.begin(),v2.end());
        v2.erase(unique(v2.begin(),v2.end()),v2.end());
        sort(v2.rbegin(),v2.rend());
        ll n = v2.size();
        
        vi pref(n);
        pref[0] = v2[0].first;
        for(ll i=1; i<n; i++){
            pref[i] = pref[i-1] + v2[i].first*(v2[i].second-v2[i-1].second);
        }
        // for(auto a : divisors) cout << a << " ";
        // cout << "\n";
        while(q--){
            ll x,y; cin >> x >> y;
            ll left = 0, right = n-1;
            ll maxcap = x;
            ll idx = 0;
            // v2 : [6-1, 3-2, 2-3], 1-6
            // x = 4, y = 5
            while(left<=right){
                ll m = left+(right-left)/2;
                if(v2[m].second>y){
                    right = m-1;
                }else{
                    idx = m;
                    left=m+1;
                }
            }
            // idx=2
            ll idx2 = -1;
            left = 0; right = idx;
            while(left<=right){
                ll m = left+(right-left)/2;
                if(x<=v2[m].first){
                    idx2 = m;
                    left=m+1;
                }else{
                    right=m-1;
                }
            }
            // idx2 = 0
            // upto idx2 only maxcap
            ll ans = 0;
            if(idx2!=-1){
                ans += v2[idx2].second*maxcap;
            }

            // idx2+1 to idx normal sum
            ll sum = pref[idx];
            if(idx2!=-1) sum -= pref[idx2];
            ans += sum;
            
            if(idx!=n-1){
                ll nextval = v2[idx+1].first;
                ll diff = y-v2[idx].second;
                ans += diff*min(x,nextval);
            }

            cout << ans << "\n";
        }
    }
}