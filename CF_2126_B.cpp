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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi v;
        ll temp = 0;
        for(auto a : arr){
            if(a==0){
                temp++;
            }else{
                if(temp>0) v.push_back(temp);
                temp = 0;
            }
        }        
        if(temp>0) v.push_back(temp);
        // for(auto a : v) cout << a << " ";
        // cout << "\n";
        ll res = 0;
        for(auto a : v){
            ll div = a/(k+1);
            res += div;
            if(a%(k+1)==k) res++;
        }
        cout << res << "\n";
    }
} 