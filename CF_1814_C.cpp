#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,s1,s2; cin >> n >> s1 >> s2;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vector<ll>> v; 
        for(ll i=0; i<n; i++) v.push_back({arr[i],i+1});
        sort(v.rbegin(),v.rend());
        ll ptr1 = s1, ptr2 = s2;
        vi res1, res2;
        for(auto a : v){
            if(ptr1<ptr2){
                res1.push_back(a[1]);
                ptr1 += s1;
            }else{
                res2.push_back(a[1]);
                ptr2 += s2;
            }
        }
        cout << res1.size() << " ";
        for(auto a : res1) cout << a << " ";
        cout << "\n";
        cout << res2.size() << " ";
        for(auto a : res2) cout << a << " ";
        cout << "\n";
    }
}