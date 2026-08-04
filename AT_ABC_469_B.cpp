#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; string s; cin >> n >> s;
    ll res = 0;
    if(n==1){
        if(s[0]=='x') res++;
        cout << res;
        return 0;
    }
    for(ll i=1; i<n-1; i++){
        if(s[i]=='x' && s[i-1]=='x' && s[i+1]=='x') res++;
    }
    if(n>=2){
        if(s[0]=='x' && s[1]=='x') res++;
        if(s[n-1]=='x' && s[n-2]=='x') res++;
    }
    cout << res;
}