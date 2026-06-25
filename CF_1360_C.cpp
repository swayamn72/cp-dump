#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        if(n%2==1){
            cout << "NO" << "\n";
            continue;
        }
        bool flag = false;
        ll odd = 0, even = 0;
        if(arr[0]%2){odd++;}else{even++;}
        for(ll i=1; i<n; i++){
            if(arr[i]%2){odd++;}else{even++;}
            if(arr[i]==arr[i-1]+1)flag = true;
        }
        if((odd%2==0 && even%2==0) || flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}