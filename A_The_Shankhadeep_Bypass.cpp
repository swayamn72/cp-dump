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
        vi count(n+1,0);
        for(auto a : arr) count[a]++;
        ll mex1 = 0;
        for(ll i=0; i<n; i++){
            if(count[i]==0) break;
            count[i]--;
            mex1++;
        }        
        ll mex2 = 0;
        for(ll i=0; i<n; i++){
            if(count[i]==0) break;
            count[i]--;
            mex2++;
        }        
        cout << mex1 + mex2 << "\n";
    }
}