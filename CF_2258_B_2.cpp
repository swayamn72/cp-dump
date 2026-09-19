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
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp;
        for(auto a : arr) mp[a]++;
        vi res(m);
        ll k = min(18LL,m);


        for(ll i=0; i<k; i++){
            ll total = 0;
            ll ans = 0;
            ll val;
            for(auto a : mp) total += a.second;
            for(auto a : mp){
                ll temp = total;
                if(mp.count(2*a.first)) temp += mp[2*a.first];
                if(temp>ans){
                    ans = temp;
                    val = a.first;
                }
                total -= a.second;
            }    
            for(auto a : mp){
                if(a.first>=val){
                    mp[val]+=a.second;
                    mp[a.first-val]+=a.second;
                    mp.erase(a.first);
                }
            }
            res[i] = ans;
        }   
        for(ll i=k; i<m; i++){
            res[i] = res[i-1];
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";     
    }
} 