#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t = 1;
    while(t--){
        ll n,m; cin >> n >> m;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(m); for(auto &x : b) cin >> x;
        sort(a.begin(),a.end()); sort(b.begin(),b.end());
        ll ptr1 = 0, ptr2 = 0;
        ll res = 0;
        while(ptr1<n && ptr2<m){
            if(b[ptr2]<=2*a[ptr1]){
                res++;
                ptr1++;
                ptr2++;
            }else{
                ptr1++;
            }
        }
        cout << res;
    }
}

// .#.....
// .......
// ..#....
// .......
// ....#..

