#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        ll res = n-1;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        for(ll i=0; i<n; i++){
            ll toremove = i;
            for(ll j=i+1; j<n; j++){
                if(arr[j]%arr[i]!=0) toremove++;
            }
            res = min(res,toremove);
        }        
        cout << res << "\n";
    }
}