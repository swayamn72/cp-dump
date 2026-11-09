#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    vi primes = {1};
    ll maxn = 1e5+200;
    vi spf(maxn);
    iota(spf.begin(),spf.end(),0);
    for(ll i=2; i<maxn; i++){
        if(spf[i]==i){
            primes.push_back(i);
            for(ll j=i*i; j<maxn; j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    // cout << primes.size() << "\n";
    ll t=1; 
    cin >> t;
    while(t--){
        ll a,b; cin >> a >> b;
        if(a==b){
            cout << 0 << "\n";
            continue;
        }
        vi res;
        queue<ll> q;
        q.push(a);
        
        while(!q.empty()){
            auto node = q.front(); q.pop();
        }

        cout << res.size() << "\n";
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}