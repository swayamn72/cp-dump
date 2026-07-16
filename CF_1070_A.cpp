#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll d,s; cin >> d >> s;
    bool vis[502][5002];
    ll prev[502][5002];
    char digit[502][5002];

    queue<pair<ll,ll>> q;

    for(ll i=1; i<=9; i++){
        if(i<=s && !vis[i%d][i]){
            vis[i%d][i] = true;
            digit[i%d][i] = i+'0';
            prev[i%d][i] = -1;
            q.push({i%d,i});
        }
    }
    bool found = false;
    string res = "";
    while(!q.empty()){
        auto [r,sum] = q.front(); q.pop();
        if(r==0 && sum==s){
            ll currr = r, currsum = sum;
            while(currr!=-1){
                res += digit[currr][currsum];
                ll p = prev[currr][currsum];
                currsum -= (digit[currr][currsum] - '0');
                currr = p;
            }
            found = true;
            break;
        }
        for(ll i=0; i<=9; i++){
            ll nextr = (r*10+i)%d;
            ll nextsum = sum + i;
            if(nextsum <= s && !vis[nextr][nextsum]){
                vis[nextr][nextsum] = true;
                digit[nextr][nextsum] = '0'+i;
                prev[nextr][nextsum] = r;
                q.push({nextr,nextsum});
            }
        }
    }
    if(found){
        cout << res;
        return 0;
    }
    cout << -1;
}