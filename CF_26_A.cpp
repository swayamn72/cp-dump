#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;

    vector<ll> divisorcount(n+1, 0);
    for(int i=2; i<=n; i++){
        if(divisorcount[i]==0){
            for(ll j=i; j<=n; j+=i){
                divisorcount[j]++;
            }
        }
    }
    ll res = 0;
    for(ll i=1; i<=n; i++) if(divisorcount[i]==2) res++;
    cout << res;
}