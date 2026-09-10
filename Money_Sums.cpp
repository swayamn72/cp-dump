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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        vector<bool> res(sum+1,false);
        sort(arr.begin(),arr.end());
        res[0] = true;
        for(auto a : arr){
            for(ll i=sum; i>=a; i--){
                res[i] = res[i] | res[i-a];
            }
        }
        vi v;
        for(ll i=1; i<=sum; i++) if(res[i]) v.push_back(i);
        cout << v.size() << "\n";
        for(auto a : v) cout << a << " ";
    }
} 