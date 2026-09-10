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
        map<ll,ll> mp;
        ll res = 0;
        for(auto a : arr) mp[a]++;
        for(auto a : mp) res = max(res,a.second);
        
        ll odd = 0;
        ll evena = 0, evenb = 0;
        for(auto a : arr){
            if(a%2){
                odd++;
            }else{
                if(a%4==0) evena++;
                else evenb++; 
            }
        }
        res = max({res,odd,evena,evenb});
        cout << res << "\n";
    }
} 