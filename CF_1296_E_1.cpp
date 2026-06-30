#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    string s; cin >> s;
    char ch = s[0];
    vector<ll> vis(n,0);
    vis[0] = 1;
    for(ll i=1; i<n; i++){
        if(s[i]>=ch){
            ch = s[i];
            vis[i] = 1;
        }
    }
    ch = '#';
    bool flag = true;
    for(ll i=1; i<n; i++){
        if(!vis[i]){
            if(ch=='#'){
                ch = s[i];
                continue;
            }else if(s[i]<ch){
                flag = false;
                break;
            }else{
                ch = s[i];
            }
        }
    }
    if(flag){
        cout << "YES" << "\n";
        for(auto a : vis) cout << a;
    }else{
        cout << "NO" << "\n";
    }
}