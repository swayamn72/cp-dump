#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        vi res(n);
        multiset<ll> ms;
        ll count = 0;
        for(ll i=0; i<n; i++){
            ll ans = 0;
            ms.insert(a[i]+count);
            while(!ms.empty() && *ms.begin()<= count+b[i]){
                ll val = *ms.begin();
                ans += val - count;
                ms.erase(ms.begin());
            }
            ans += ms.size()*b[i];
            count += b[i];
            res[i] = ans;
        }
        for(auto a : res) cout << a << " ";
        cout << endl;
    } 
}