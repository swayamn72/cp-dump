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
        sort(arr.begin(),arr.end());
        vi v(m+1);
        for(auto a : arr){
            if(a%2==0) v[a/2]++;
        }       
        ll res = 0; 
        ll ptr = 0;
        for(ll i=1; i<=m; i++){
            while(ptr<n && arr[ptr]<i) ptr++;
            ll num = n-ptr;
            res = max(res,num+v[i]);
        }
        cout << res << "\n";
    }
} 