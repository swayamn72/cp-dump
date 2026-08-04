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
        ll n,m; cin >> n >> m;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(m); for(auto &x : b) cin >> x;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        map<ll,ll> mp; for(auto x : a) mp[x]++;

        if(n<2*m){
            cout << "NO" << "\n";
            continue;
        }
        bool flag = true;
        ll ptr = 0, ptr2 = n-m;
        for(ll i=0; i<m; i++){
            if(b[i]>a[ptr2] || b[i]<a[ptr]){
                flag = false;
                break;
            }
            ptr++; ptr2++;
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}