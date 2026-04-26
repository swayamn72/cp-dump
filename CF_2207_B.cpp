#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m,l; cin >> n >> m >> l;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi v(m,0);
        ll index = 0;
        ll flashesremaining = n;
        for(ll i=0; i<l; i++){
            ll pos = min(m-1, flashesremaining);
            v[pos]++;
            sort(v.rbegin(),v.rend());
            if(index<n && arr[index]==i+1){
                v[0] = 0;
                sort(v.rbegin(),v.rend());
                index++;
                flashesremaining--;
            }
        }
        cout << v[0] << "\n";
    }
}