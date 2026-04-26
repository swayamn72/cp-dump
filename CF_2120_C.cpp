#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        ll sum = n * (n+1); sum /= 2;
        if(m>sum || m<n){
            cout << -1 << "\n";
            continue;
        }
        vi res; 
        set<ll> s;
        ll remaining = -1; 
        for(ll i=n; i>0; i--){
            if((m-i) >= (i-1)){
                res.push_back(i);
                s.insert(i);
                m-=i;
            }else{
                remaining = i;
                break;
            }
        }
        if(remaining!=-1){
            res.push_back(m-remaining+1);
            s.insert(m-remaining+1);
        }
        for(ll i=1; i<=n; i++) if(s.find(i)==s.end()) res.push_back(i);
        cout << res[0] << "\n";
        for(ll i=0; i<res.size()-1; i++){
            cout << res[i] << " " << res[i+1] << "\n";
        }
        cout << "\n";
    }
}