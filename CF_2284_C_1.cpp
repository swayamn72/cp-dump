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
    vi primes;
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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        // cout << sum << "\n";   
        // sort(arr.begin(),arr.end());
        set<ll> seen;  
        vi prev;   
        for(auto &a : arr){
            bool flag = false;
            if(spf[a]==a) continue;
            ll temp = a;
            while(temp>1){
                ll p = spf[temp];
                if(seen.count(p)) flag = true;
                seen.insert(p);
                while(temp%p==0) temp/=p;
            }
            if(!flag) continue;
            ll nextprime = *upper_bound(primes.begin(),primes.end(),a);
            ll diff = nextprime - a;
            if(gcd(diff,a)==1){
                a += diff;
                prev.push_back(a);
                continue;
            }
            if(prev.empty()){
                a+=diff;
                prev.push_back(a);
                continue;
            }
            // for(ll i=prev.size()-1; i>=0; i--){
            //     ll b = prev[i];
            //     ll val = a/b*b + b;
            //     a = val;
            //     prev.push_back(a);
            // }

            
        }
        for(auto a : arr) cout << a << " ";
        cout << "\n";
    }
}