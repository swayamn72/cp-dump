#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi b(n);
        for(ll i=0; i<n; i++){
            b[i] = arr[i]-(i+1);
        }
        // for(auto a : b) cout << a << " ";
        // cout << "\n";
        ll res = 1;
        ll temp = 1;
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        for(ll i=1; i<b.size(); i++){
            if(b[i]==b[i-1]+1){
                temp++;
                res = max(res,temp);
            }else{
                temp = 1;
            }
        }
        cout << res << "\n";
    }
}