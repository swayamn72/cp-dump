#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vector<vector<ll>> seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n, vector<ll>(26,0));
    }
    vector<ll> merge(vector<ll>&a, vector<ll>&b){
        vector<ll> v(26,0);
        for(ll i=0; i<26; i++){
            v[i] = a[i]+b[i];
        }
        return v;
    }
    void build(ll node, ll l, ll r, string &s){
        if(l==r){
            char ch = s[l];
            seg[node][ch-'a'] = 1;
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,s);
        build(2*node+1,m+1,r,s);
        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }
    void update(ll node, ll l, ll r, ll i, char ch, char ch2){
        if(l==r){
            seg[node][ch-'a']++;
            seg[node][ch2-'a']--;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,ch,ch2);
        else update(2*node+1,m+1,r,i,ch,ch2);
        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }
    void query(ll node, ll l, ll r, ll ql, ll qr, set<ll>&s){
        if(qr<l || ql>r) return; 
        if(ql<=l && qr>=r){
            for(ll i=0; i<26; i++) if(seg[node][i] > 0) s.insert(i);
            return;
        }
        ll m = l + (r-l)/2;
        query(2*node,l,m,ql,qr,s);
        query(2*node+1,m+1,r,ql,qr,s);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    ll n = s.size();
    ll q; cin >> q;
    SegTree st(n);
    st.build(1,0,n-1,s);
    while(q--){
        ll type; cin >> type;
        if(type==1){
            ll index; char ch; cin >> index >> ch;
            index--;
            st.update(1,0,n-1,index,ch,s[index]);
            s[index] = ch;
        }else{
            ll l,r; cin >> l >> r;
            set<ll> s;
            st.query(1,0,n-1,l-1,r-1,s);
            cout << s.size() << "\n";
        }
    }
}