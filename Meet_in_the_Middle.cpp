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
        ll n,x; cin >> n >> x;
        vi arr(n); for(auto &x : arr) cin >> x;

        vi arr1, arr2;
        unordered_map<ll,ll> mp2;

        auto dfs = [&](auto &&self, ll v, ll i, ll end)->void{
            if(i==end){
                arr1.push_back(v);
                return;
            }
            self(self,v+arr[i],i+1,end);
            self(self,v,i+1,end);
        };
        dfs(dfs,0,0,n/2);
        // for(auto a : arr1) cout << a << " ";
        auto dfs2 = [&](auto &&self, ll v, ll i, ll end)->void{
            if(i==end){
                arr2.push_back(v);
                return;
            }
            self(self,v+arr[i],i+1,end);
            self(self,v,i+1,end);
        };
        dfs2(dfs2,0,n/2,n);
        sort(arr2.begin(),arr2.end());
        ll res = 0;
        for(auto a : arr1){
            auto it1 = lower_bound(arr2.begin(),arr2.end(),x-a);
            if(it1==arr2.end() || *it1!=x-a) continue;
            auto it2 = upper_bound(arr2.begin(),arr2.end(),x-a);
            it2--;
            res += (it2-it1+1);
        }
        cout << res;
    }
} 