#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
ll binexp(ll a, ll b) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
ll maxn = 2e5+10;
void factandinv(vector<ll> &fact, vector<ll> &invFact){
    fact[0] = 1;
    for(ll i=1; i<maxn; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    invFact[maxn-1] = binexp(fact[maxn-1],mod-2);
    for(int i=maxn-2; i>=0; i--){
        invFact[i] = (invFact[i+1]*(i+1))%mod;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    vector<ll> fact(maxn), invfact(maxn);
    factandinv(fact,invfact);
    auto ncr = [&](ll n, ll r)->ll{
        if(r < 0 || r > n) return 0;
        return (((fact[n] * invfact[r]) % mod)
            * invfact[n-r]) % mod;
    }; 

    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        if(n==1){
            cout << 1 << " " << 1 << "\n";
            continue;
        }
        ll cost = n;
        ll extra = 0;
        vi taken(n,0);
        for(ll i=1; i<n-1; i++){
            if(s[i]!=s[i-1]||s[i]!=s[i+1]){
                extra++; taken[i]=1;
            } 
        }
        if(s[0]!=s[1]){
            extra++; taken[0] = 1;
        } 
        if(s[n-1]!=s[n-2]){
            extra++; taken[n-1] = 1;
        } 
        ll count = 1;
        ll rem0 = 0, rem1 = 0;
        for(ll i=0; i<n; i++){
            if(!taken[i]){
                if(s[i]=='0') rem0++;
                else rem1++;
            }
        }
        vi arr;
        ll temp = 1;
        for(ll i=1; i<n; i++){
            if(s[i]!=s[i-1]){
                temp++;
            }else{
                if(temp>1) arr.push_back(temp);
                temp = 1;
            }
        }
        if(temp>1) arr.push_back(temp);
        // for(auto a : arr) cout << a << " ";
        // cout << "\n";
        for(auto a : arr){
            ll ans = 0;
            // b - size3 blocks
            for(ll b=0; b*3<=a; b++){
                
            }
        }

        cout << n+extra << " " << count << "\n";
    }
}