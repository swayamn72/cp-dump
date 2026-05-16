#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        vi arr(k); for(auto &x : arr) cin >> x;
        bool flag1 = false, flag2 = false;
        
        ll res1 = 0;
        bool has31 = false;
        for(auto a : arr){
            ll v = a/n;
            if(v>=2){
                res1 += v;
                if(v>=3) has31 = true;
            }
        }
        if(res1>=m && (m%2==0 || has31)) flag1 = true;

        ll res2 = 0;
        bool has32 = false;
        for(auto a : arr){
            ll v = a/m;
            if(v>=2){
                res2 += v;
                if(v>=3) has32 = true;
            }
        }
        if(res2>=n && (n%2==0 || has32)) flag2 = true;

        if(flag1 || flag2) cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
}