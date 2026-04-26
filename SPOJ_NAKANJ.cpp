#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll dx[8] = {2,2,1,1,-2,-2,-1,-1};
ll dy[8] = {1,-1,2,-2,1,-1,2,-2};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        string s,d; cin >> s >> d;
        if(s==d){
            cout << 0 << "\n";
            continue;
        }
        set<string> vis;
        queue<string> q;
        q.push(s);
        ll size = 1;
        ll res = 1;
        ll ans = -1;
        while(!q.empty()){
            string node = q.front(); q.pop(); vis.insert(node); size--;
            for(ll i=0; i<8; i++){
                char first = node[0] + dx[i];
                char second = node[1] + dy[i];
                if(first > 'h' || second > '8' || first<'a' || second <'1') continue;
                
                string str = ""; str+=first; str+=second;
                if(vis.find(str)!=vis.end()) continue;
                if(str==d){
                    ans = res;
                    break;
                }
                q.push(str); vis.insert(str);
            }
            if(ans!=-1) break;
            if(size==0){
                res++; size = q.size();
            }
        }
        cout << ans << "\n";
    }
}