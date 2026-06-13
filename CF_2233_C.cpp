#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        string s; cin >> s;
        vi arr(n,1);
        ll temp = k;
        for(ll i=0; i<n; i++){
            if(temp==0) break;
            if(s[i]=='('){
                temp--;
                arr[i]==0;
            }
        }
        ll size = 0;
        stack<ll> st;
        for(ll i=0; i<n; i++){
            if(arr[i]==0) continue;
            if(s[i]=='(') st.push(1);
            if(s[i]==')'){
                if(!st.empty()) st.pop();
                else size++;
            }
        }
        ll res = n - size - st.size();

        vi arr2(n,1);
        temp = k;
        for(ll i=n-1; i>=0; i--){
            if(temp==0) break;
            if(s[i]==')'){
                temp--;
                arr2[i] = 0;
            }
        }
        ll size2 = 0;
        stack<ll> st2;
        for(ll i=0; i<n; i++){
            if(arr2[i]==0) continue;
            if(s[i]=='(') st2.push(1);
            if(s[i]==')'){
                if(!st2.empty()) st2.pop();
                else size2++;
            }
        }
        ll res2 = n - size2 - st2.size();
        if(res>res2){
            for(auto a : arr) cout << 1-a;
            cout << "\n";
        }else{
            for(auto a : arr2) cout << 1-a;
            cout << "\n";
        }
    }
}