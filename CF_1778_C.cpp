#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k; 
        string a,b; cin >> a >> b;
        set<char> st;
        for(ll i=0; i<n; i++){
            if(a[i]!=b[i]) st.insert(a[i]);
        }    
        vector<char> v; for(auto x : st) v.push_back(x);    
        ll m = v.size();
        k = min(k,m);
        vector<vector<char>> arr;
        auto func = [&](auto &&self, ll i, vector<char> &temp)->void{
            if(temp.size()==k){
                arr.push_back(temp);
                return;
            }
            if(i==m) return;
            temp.push_back(v[i]);
            self(self,i+1,temp);
            temp.pop_back();
            self(self,i+1,temp);
        };
        vector<char> temp;
        func(func,0,temp);
        ll res = 0;
        for(auto x : arr){
            set<char> st1; 
            for(auto x1 : x) st1.insert(x1);
            string s1 = a, s2 = b;
            for(ll i=0; i<n; i++){
                if(s1[i]!=s2[i] && st1.count(s1[i])){
                    s1[i] = s2[i];
                }
            }
            ll ans = 0;
            ll left = 0;
            for(ll i=0; i<n; i++){
                if(s1[i]!=s2[i]){
                    ll len = i-left;
                    ans += (len*(len+1))/2;
                    left = i+1;
                }
            }
            ll len = n-left;
            if(len!=0){
                ans += (len*(len+1))/2;
            }
            res = max(res,ans);
        }
        cout << res << "\n";
    }
}