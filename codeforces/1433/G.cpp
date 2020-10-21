
// Problem: G. Reducing Delivery Cost
// Contest: Codeforces - Codeforces Round #677 (Div. 3)
// URL: https://codeforces.com/contest/1433/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define SQ(a) (a)*(a)
 
using namespace std;

void read(int n,vector<int>& x)
{
    x.clear();
    x.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }
    
}
void read(int n,int m,vector<vector<int>>& x)
{
    x.clear();
    x.resize(n,vector<int>(m));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0 ;j<m;j++)
            cin>>x[i][j];
    }
}
void read(int n,vector<vector<int>>& x)
{
    x.clear();
    x.resize(n+1);
    for(int i = 0;i<n-1;i++)
    {
         int a,b;
         cin>>a>>b;
         x[a].pb(b);
         x[b].pb(a);
    }
}
void read(int n,vector<vector<int>>& x,int m)
{
    x.clear();
    x.resize(n+1);
    for(int i = 0;i<m;i++)
    {
         int a,b;
         cin>>a>>b;
         x[a].pb(b);
         x[b].pb(a);
    }
}
void read(int n,vector<ll>& x)
{
    x.clear();
    x.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }
}

void dijkstra(int s,vector<vector<pair<int,int>>>& adj, vector<ll> &d, vector<int> &p) {
    int n = adj.size();
    d.assign(n, inf);
    p.assign(n, -1);

    d[s] = 0;
    // using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    //cin>>T;
    for(int t = 1;t<=T;t++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<pair<int,int>>> adj(n);
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            // cout<<a<<" "<<b<<" "<<c;
            a--;
            b--;
            adj[a].pb({b,c});
            adj[b].pb({a,c});
            edges.pb({a,b});
        }
        vector<vector<ll>> distances(n);
        vector<vector<int>> parent(n);
        for(int i = 0;i<n;i++)
        {
        	dijkstra(i,adj,distances[i],parent[i]);
        }
        vector<ll> ans(m);
        for(int i = 0;i<k;i++)
        {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            ll dist_with_edgegone = distances[a][b];
            // cout<<a<<" "<<b<<" "<<dist_with_edgegone<<endl;
            for(int j=0;j<m;j++)
            {
            	dist_with_edgegone = distances[a][b];
            	dist_with_edgegone = min(distances[a][edges[j].first] + distances[b][edges[j].second],dist_with_edgegone);
            	dist_with_edgegone = min(distances[a][edges[j].second] + distances[b][edges[j].first],dist_with_edgegone);
            	// cout<<j<<" "<<dist_with_edgegone<<" "<<edges[j].first<<" "<<edges[j].second<<endl;
            	ans[j] += dist_with_edgegone;
            }
        }
        cout<<*min_element(all(ans))<<endl;
    }

    return 0;
}
