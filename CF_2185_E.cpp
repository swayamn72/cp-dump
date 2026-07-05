#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        vi robots(n); for(auto &x : robots) cin >> x;
        vi spikes(m); for(auto &x : spikes) cin >> x;
        string s; cin >> s;
        
        vector<vector<ll>> v; 
        for(auto a : robots) v.push_back({a,0});
        for(auto a : spikes) v.push_back({a,1});
        sort(v.begin(),v.end());

        stack<ll> st;
        vector<vector<ll>> r(n,vector<ll>(2,-1));
        ll index = 0;
        ll left = -1;
        vi temp(n);
        for(auto a : v){
            if(a[1]==0){
                if(left!=-1){
                    r[index][0] = a[0] - left;
                }
                st.push(index);
                temp[index] = a[0];
                index++;
            }else{
                left = a[0];
                while(!st.empty()){
                    r[st.top()][1] = a[0] - temp[st.top()];
                    st.pop();
                }
            }
        }
        // for(auto a : r) cout << a[0] << " " << a[1] << "   ";
        // cout << "\n";
        map<ll,vector<ll>> toleft, toright;

        for(ll i=0; i<n; i++){
            if(r[i][0]!=-1){
                toleft[r[i][0]].push_back(i);
            }
            if(r[i][1]!=-1){
                toright[r[i][1]].push_back(i);
            }
        }
        ll res = n;
        vector<bool> removed(n,false);
        ll pos = 0;
        ll maxl = 0, maxr = 0;
        for(auto a : s){
            if(a=='L'){
                pos--;
            }else{
                pos++;
            }
            if(pos<0){
                if(pos<maxl){
                    maxl = pos;
                    for(auto b : toleft[abs(pos)]){
                        if(removed[b]) continue;
                        removed[b] = true;
                        res--;
                    }
                }
            }else{
                if(pos>maxr){
                    maxr = pos;
                    for(auto b : toright[abs(pos)]){
                        if(removed[b]) continue;
                        removed[b] = true;
                        res--;
                    }
                }
            }
            cout << res << " ";
        }
        cout << "\n";
    }
}