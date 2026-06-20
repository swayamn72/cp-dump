#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;

        bool flag = true;
        vector<bool> vis(n,false);
        vector<bool> filled(n,false);
        for(ll i=0; i<n; i++){
            if(b[i]!=-1)filled[b[i]-1] = true;
        }
        for(ll i=0; i<n; i++){
            if(b[i]!=-1){
                vis[i] = true;
                if(b[a[i]-1]==-1){
                    if(filled[a[b[i]]]){
                        flag = false;
                        break;
                    }
                    b[a[i]-1] = a[b[i]-1];
                }else{
                    if(b[a[i]-1]!=a[b[i]-1]){
                        flag = false;
                        break;
                    }
                }
            }
        }        
        if(!flag){
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
    }
}