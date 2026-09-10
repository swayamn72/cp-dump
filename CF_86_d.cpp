#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<ll> arr(n+1); for(ll i=1; i<=n; i++) cin >> arr[i];
        vector<vector<ll>> queries(m,vector<ll>(3));
        for(ll i=0; i<m; i++){
            ll l,r; cin >> l >> r;
            queries[i] = {l,r,i};
        }
        ll blocksize = max(1LL,(ll)ceil(sqrt(n)));
        sort(queries.begin(),queries.end(),[&](vector<ll>&a, vector<ll>&b){
            ll ab = a[0]/blocksize;
            ll bb = b[0]/blocksize;
            if(ab!=bb) return ab<=bb;
            return a[1]<=b[1];
        });

        ll maxn = 1e6+1;
        vector<ll> sum(maxn,0), freq(maxn,0);
        ll ans = 0;
        vector<ll> res(m);
        ll left = 1, right = 0;
        for(auto a : queries){
            ll l = a[0], r = a[1], i = a[2];
            while(l<left){
                left--;
                ans += (2*freq[arr[left]]+1)*arr[left];
                freq[arr[left]]++;
            }
            while(r>right){
                right++;
                ans += (2*freq[arr[right]]+1)*arr[right];
                freq[arr[right]]++;
            }
            while(l>left){
                freq[arr[left]]--;
                ans -= (2*freq[arr[left]]+1)*arr[left];
                left++;
            }
            while(r<right){
                freq[arr[right]]--;
                ans -= (2*freq[arr[right]]+1)*arr[right];
                right--;
            }
            res[i] = ans;
        }

        for(auto a : res) cout << a << "\n";
    }
} 