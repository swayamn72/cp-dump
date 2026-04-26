#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vector<string> arr(n); for(auto &x : arr) cin >> x;
    pair<ll,ll> start,end;
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++){
        if(arr[i][j]=='A') start = {i,j};
        if(arr[i][j]=='B') end = {i,j};
    }
    vector<vector<ll>> direction(n, vector<ll>(m, -1));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<ll,ll>> q;
    q.push(start);
    ll foundpath = false;
    while(!q.empty()){
        pair<ll,ll> node = q.front(); q.pop();
        ll u = node.first; ll v = node.second;
        vis[node.first][node.second] = true;
        for(ll i=0; i<4; i++){
            ll u1 = u + dx[i]; ll v1 = v + dy[i];
            if(u1<0 || v1<0 || u1 >= n || v1 >= m || arr[u1][v1]=='#' || vis[u1][v1]) continue;
            if(arr[u1][v1]=='B'){
                foundpath = true;
            }
            vis[u1][v1] = true;
            q.push({u1,v1});
            if(i==0) direction[u1][v1] = 3;
            else if(i==1) direction[u1][v1] = 4;
            else if(i==2) direction[u1][v1] = 1;
            else if(i==3) direction[u1][v1] = 2;
        }
        if(foundpath) break;
    }
    if(!foundpath){
        cout << "NO";
        return 0;
    }
    string ans = "";
    ll i = end.first; ll j = end.second;
    while(arr[i][j] != 'A'){
        if(direction[i][j]==3){
            ans += 'R';
            j--;
        }else if(direction[i][j]==4){
            ans += 'L';
            j++;
        }else if(direction[i][j]==1){
            ans += 'D';
            i--;
        } else{
            ans += 'U';
            i++;
        }
    }
    reverse(ans.begin(),ans.end());
    cout << "YES" << "\n";
    cout << ans.size() << "\n";
    cout << ans;
}
