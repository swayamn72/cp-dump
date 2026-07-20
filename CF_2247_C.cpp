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
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        if(a==b){
            cout << 0 << "\n";
            continue;
        }
        ll bzeros = 0;
        for(auto x : b) if(x==0) bzeros++;

        ll azeros = 0;
        for(auto x : a) if(x==0) azeros++;

        if(azeros==n || bzeros==0){
            cout << -1 << "\n";
            continue;
        }
        // if(azeros==0){
        //     ll bones = n - bzeros;
        //     ll aones = n - azeros;
        //     if(bones%2){
        //         cout << 1 << "\n";
        //     }else{
        //         cout << 2 << "\n";
        //     }
        //     continue;
        // }
        // if(bzeros==n){
        //     cout << -1 << "\n";
        //     continue;
        // }
        ll ones = 0;
        for(ll i=0; i<n; i++){
            if(a[i]!=b[i]){
                if(a[i]==1) ones++;
            }
        }        
        if(ones%2) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
}