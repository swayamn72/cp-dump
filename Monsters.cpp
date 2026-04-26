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
    vector<string> grid(n); for(auto &x : grid) cin >> x;
    vector<vector<ll>> monster(n, vector<ll>(m, LLONG_MAX));
    ll startx,starty;
    queue<pair<ll,ll>> mq;
    vector<vector<ll>> m_vis(n, vector<ll>(m, false));
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++){
        if(grid[i][j]=='M'){
            mq.push({i,j});
            m_vis[i][j] = true;
            monster[i][j] = 0;
        }
        if(grid[i][j]=='A'){
            startx = i; starty = j;
        }
    }
    
    ll m_curr = 0;
    ll m_size = mq.size();
    while(!mq.empty()){
        auto node = mq.front(); mq.pop(); m_size--;
        ll u = node.first; ll v = node.second;
        
        for(ll i=0; i<4; i++){
            ll u1 = u + dx[i]; ll v1 = v + dy[i];
            if(u1<0 || v1<0 || u1>=n || v1>=m || m_vis[u1][v1] || grid[u1][v1]=='#') continue;
            mq.push({u1,v1});
            m_vis[u1][v1] = true;
            monster[u1][v1] = m_curr + 1;
        }
        if(m_size==0){
            m_size = mq.size(); m_curr++;
        }
    }

    vector<vector<ll>> parent(n, vector<ll>(m,-1));
    queue<pair<ll,ll>> q;
    vector<vector<ll>> vis(n, vector<ll>(m, false));
    q.push({startx, starty});
    vis[startx][starty] = true; 
    
    ll curr = 0;
    ll size = q.size();
    bool foundpath = false;
    ll borderx, bordery;
    
    while(!q.empty()){
        auto node = q.front(); q.pop(); size--;
        ll u = node.first; ll v = node.second;
        
        if(u==0 || u==n-1 || v==0 || v==m-1){
            foundpath = true;
            borderx = u; bordery = v;
            break;
        }    
        for(ll i=0; i<4; i++){
            ll u1 = u + dx[i]; ll v1 = v + dy[i];
            if(u1<0 || v1<0 || u1>=n || v1>=m || vis[u1][v1] || grid[u1][v1]=='#' || monster[u1][v1]<=curr+1) continue;   
            q.push({u1,v1});
            vis[u1][v1] = true;
            if(i==0){
                parent[u1][v1] = 3;
            }else if(i==1){
                parent[u1][v1] = 4;
            }else if(i==2){
                parent[u1][v1] = 1;
            }else{
                parent[u1][v1] = 2;
            }
        }
        if(size==0){
            size = q.size(); curr++;
        }
    }
    
    if(!foundpath){
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    pair<ll,ll> p = {borderx, bordery};
    string ans = "";
    
    while(parent[p.first][p.second] != -1){
        ll u = p.first; ll v = p.second;
        if(parent[u][v] == 3){
            ans += 'R'; p.second--;
        }else if(parent[u][v]== 4){
            ans += 'L'; p.second++;
        }else if(parent[u][v]==1){
            ans += 'D'; p.first--; 
        }else{
            ans += 'U'; p.first++; 
        }
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    cout << ans; 
}