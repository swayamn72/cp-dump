#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    string s; cin >> s;
    stack<char> st;
    ll res = 0;
    st.push(s[0]);
    for(ll i=1; i<s.size(); i++){
        if(!st.empty()&&st.top()==s[i]){
            st.pop();
            res++;
        }else{
            st.push(s[i]);
        }
    }
    cout << (res%2 ? "Yes" : "No") << "\n"; 
}