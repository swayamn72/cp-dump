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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        vi v;
        for(ll i=n-k; i<n; i++) v.push_back(arr[i]);
        for(ll i=n-k-1; i>=0; i--) v.push_back(arr[i]);
        ll count = 1;
        ll sum = v[0];
        for(ll i=1; i<n; i++){
            if(v[i]*i>=sum) count++;
            sum += v[i];
        }
        if(count!=k){
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        for(auto a : v) cout << a << " ";
        cout << "\n";
    }
}