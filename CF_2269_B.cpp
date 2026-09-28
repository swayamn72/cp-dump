#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi group(n);
        for(ll i=0; i<n; i++) group[i] = i;
        for(ll op=0; op<100; op++){
            map<ll,ll> mp;
            for(ll i=0; i<n; i++){
                ll a = arr[i];
                ll sum = 0;
                while(a>0){
                    ll d = a%10;
                    sum += (d*d);
                    a/=10;
                }
                if(mp.count(sum)){
                    group[i] = mp[sum]; 
                }else{
                    mp[sum] = i;
                }
                arr[i] = sum;
            }
        }
        vi freq(n,0);
        for(auto a : group) freq[a]++;
        ll res = 0;
        for(auto a : freq) res += (a*(a-1))/2;
        cout << res << "\n";
    }
}