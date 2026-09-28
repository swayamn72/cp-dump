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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        bool flag = true;
        vector<pair<ll,ll>> good, bad;
        for(ll i=0; i<n; i++){
            ll k = i+1;
            if(arr[i]>(n+i)/(k)){
                flag = false;
                break;
            }
            bad.push_back({arr[i]*k,arr[i]*k+k-1});
            for(ll j=0; j<arr[i]; j++){
                good.push_back({j*k,j*k+k-1});
            }
        }
        if(!flag){
            cout << 0 << "\n";
            continue;
        }
        vi diff(n+1,0);
        for(auto a : bad){
            diff[min(n,a.first)]++;
            diff[min(n,a.second+1)]--;
        }
        for(ll i=1; i<=n; i++) diff[i] = diff[i-1]+diff[i];
        vi goodnums;
        for(ll i=0; i<n; i++){
            if(!diff[i]) goodnums.push_back(i);
        }
        sort(good.begin(),good.end(),[](const pair<ll,ll>&a, const pair<ll,ll>&b){
            return (a.second-a.first) < (b.second-b.first);
        });
        set<pair<ll,ll>> s;
        for(auto a : good){
            auto it = s.lower_bound({a.first,0});
            if(it!=s.end() && it->second<=a.second) continue;
            s.insert(a);
        }
        vector<pair<ll,ll>> v(s.begin(),s.end());
        ll l = 0, r = 0;
        vi dp(v.size()+1,0);
        dp[0] = 1;
        ll pos = 1;
        for(auto a : goodnums){
            while(l<v.size() && v[l].second < a){
                pos = (pos-dp[l]+mod)%mod; l++;
            }
            while(r<v.size() && v[r].first <= a){
                r++;
            }
            dp[r] = (dp[r]+pos)%mod;
            pos = (pos*2)%mod;
        }
        cout << dp[v.size()] << "\n";
    }
}