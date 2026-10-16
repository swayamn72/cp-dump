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
        string s; cin >> s;
        vector<bool> print(n,false);

        stack<ll> st;
        for(ll i=0; i<n; i++){
            char a = s[i];
            if(a=='1'){
                st.push(i);
            }else if(a=='2'){
                if(st.empty()){
                    print[i] = true;
                }else{
                    auto b = st.top(); st.pop();
                    print[b] = true;
                }
            }else{
                print[i] = true;
            }
        }
        ll count = 0;
        vi res;
        for(ll i=0; i<n; i++){
            if(!print[i]){
                res.push_back(i+1);
                count++;
            }
        }
        cout << count << "\n";
        for(auto a : res) cout << a << " ";
        if(count>0) cout << "\n";
    }
}