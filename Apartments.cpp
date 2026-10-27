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
    // cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(m); for(auto &x : b) cin >> x;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll ptr1 = 0, ptr2 = 0;
        ll res = 0;
        while(ptr1<n && ptr2<m){
            if(abs(a[ptr1]-b[ptr2])<=k){
                res++; ptr1++; ptr2++;
            }else if(a[ptr1]>b[ptr2]){
                ptr2++;
            }else{
                ptr1++;
            }
        }        
        cout << res;
    }
}