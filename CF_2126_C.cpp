#include <algorithm>
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
        ll val = arr[k-1];
        vi v; for(auto a : arr) if(a>=val) v.push_back(a);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        bool flag = true;
        ll water = 0, h = v[0]; n = v.size();
        for(ll i=1; i<n; i++){
            ll diff = v[i]-v[i-1];
            if(water+diff>h){
                flag = false;
                break;
            }
            water += diff;
            h = v[i];
        }

        cout << (flag ? "YES" : "NO") << "\n";
    }
} 