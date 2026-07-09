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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi v;
        v.push_back(arr[0]);
        for(ll i=1; i<n; i++){
            if(arr[i]==arr[i-1]) continue;
            v.push_back(arr[i]);
        }        
        if(v.size()==1){
            cout << 1 << "\n";
            continue;
        }
        n = v.size();
        ll res = 0;
        if(v[0]>v[1]) res++;
        if(v[n-1]>v[n-2]) res++;
        for(ll i=1; i<n-1; i++){
            if(v[i]>v[i-1] && v[i]>v[i+1]){
                res++;
            }
        }
        cout << res << "\n";
    }
}