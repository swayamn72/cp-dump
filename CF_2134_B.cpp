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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(k%2==1){
            for(auto &a : arr){
                if(a%2==1) a+=k;
            }
            for(auto a : arr) cout << a << " ";
            cout << "\n";
            continue;
        }        
        ll maxv = *max_element(arr.begin(),arr.end());
        if(maxv==1) maxv = k+1;
        for(auto &a : arr){
            while(a%maxv!=0) a+=k;
        }
        for(auto a : arr) cout << a << " ";
        cout << "\n";
    }
}