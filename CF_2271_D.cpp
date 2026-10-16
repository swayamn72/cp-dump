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
        ll n,m,k; cin >> n >> m >> k;
        vector<pair<ll,ll>> arr(n);
        for(auto &[a,b] : arr){cin >> a >> b;}   
        if(k==0){
            cout << 1000000000000000+1 << "\n";
            continue;
        }
        sort(arr.begin(),arr.end());
        vector<pair<ll,ll>> intervals;
        auto [l,r] = arr[0];
        for(ll i=1; i<n; i++){
            auto [a,b] = arr[i];
            if(a<=r){
                r = max(r,b);
            }else{
                intervals.push_back({l,r});
                l = a; r = b;
            }
        }
        intervals.push_back({l,r});
        n = intervals.size();

        
        
        vector<ll> pref(n);
        pref[0] = intervals[0].second - intervals[0].first + 1;
        for(ll i=1; i<n; i++){
            pref[i] = pref[i-1] + (intervals[i].second-intervals[i].first+1);
        }
        auto countupto = [&](ll x)->ll{
            if(x<intervals[0].first) return 0;
            ll left = 0, right = n-1, idx = -1;
            while(left<=right){
                ll m = left+(right-left)/2;
                if(intervals[m].first<=x){
                    idx = m;
                    left=m+1;
                }else{
                    right=m-1;
                }
            }
            ll total = (idx>0) ? pref[idx-1] : 0;
            total += max(0LL,min(x,intervals[idx].second)-intervals[idx].first+1);
            return total;
        };
        auto find = [&](ll cur)->ll{
            return countupto(cur+m-1)-countupto(cur-1);
        };

        ll maxv = 0, pos = 0;
        for(ll i=0; i<n; i++){
            ll v = find(intervals[i].first);
            if(v>=maxv){
                maxv = v;
                pos = intervals[i].first;
            }
        }
        if(maxv<k){
            cout << -1 << "\n";
            continue;
        }
        ll res;
        ll left = pos, right = 1e15+1;
        while(left<=right){
            ll m = left+(right-left)/2;
            ll ans = find(m);
            if(ans==k){
                res = m;
                break;
            }else if(ans>k){
                left=m+1;
            }else{
                right=m-1;
            }
        }
        cout << res << "\n";
    }
}