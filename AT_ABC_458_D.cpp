#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    multiset<ll> st;
    st.insert(n);
    auto it = st.begin();
    ll q; cin >> q;
    while(q--){
        ll a,b; cin >> a >> b;
        st.insert(a);
        st.insert(b);
        if(a>=*it && b>=*it){
            it++;
        }else if(a<*it && b<*it){
            it--;
        }
        cout << *it << "\n";
    }
}