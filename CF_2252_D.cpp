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
        vi diff(n-1);
        for(ll i=0; i<n-1; i++) diff[i] = arr[i+1] - arr[i];
        
        for(ll l=0; l<n-1; ){
            ll r = l;
            while(r<n-1 && ((abs(diff[r])%2) == (abs(diff[l])%2))) r++;
            sort(diff.begin()+l,diff.begin()+r);
            l = r;
        }
        vi res(n);
        res[0] = arr[0];
        for(ll i=1; i<n; i++){
            res[i] = res[i-1]+diff[i-1];
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
} 