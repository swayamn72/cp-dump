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
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi count(m+2), pref(m+2);
        for(auto a : arr) count[a]++;
        for(ll i=1; i<=m+1; i++) pref[i] = pref[i-1] + count[i];

        auto check = [&](ll k)->ll{
            ll maxv = 0;
            ll maxj = (k>=20 ? m : (1LL<<k)-1);
            for(ll i=1; i<=m; i++){
                ll curr = 0;
                ll jlimit = min(maxj,m/i);
                for(ll j=1; j<=jlimit; j++){
                    ll left = j*i;
                    ll right = min(m,(j+1)*i-1);
                    if(left<=right){
                        ll cnt = pref[right] - pref[left-1];
                        curr += (cnt*j);
                    }
                }
                ll limit = (k>=20) ? m+1 : (1LL<<k);
                ll temp = limit*i;
                if(temp<=m){
                    curr += (count[temp]*limit);
                    if(temp<m){
                        ll greater = pref[m]-pref[temp];
                        curr += (greater*(limit-1));
                    }
                }
                maxv = max(maxv,curr);
            }
            return maxv;
        };
        vi res(m);
        res[0] = check(1);
        for(ll i=1; i<m; i++){
            res[i] = check(i+1);
            if(res[i]==res[i-1]){
                for(ll j=i+1; j<m; j++){
                    res[j] = res[j-1];
                }
                break;
            }
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}