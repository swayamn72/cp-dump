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
        string s; cin >> s;
        set<ll> st;
        int len = 0;
        for(auto a : s){
            if(st.count(a)){
                len += 2;
                st.clear();
            }else{
                st.insert(a);
            }
        }
        cout << s.size() - len << "\n";
    }
}