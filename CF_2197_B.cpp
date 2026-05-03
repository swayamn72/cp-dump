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
        vector<ll> a(n); for(auto &x : a) cin >> x;
        vector<ll> b(n); for(auto &x : b) cin >> x;
        ll ptr1 = 0, ptr2 = 0;
        while(ptr1<n && ptr2<n){
            if(a[ptr1]==b[ptr2]){
                ptr2++;
            }else{
                ptr1++;
            }
        } 
        if(ptr1==n) cout << "NO";
        else cout << "YES";
        cout << "\n";
    }
}