#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define maxheap priority_queue < ll, std::vector<ll>, std::less<ll> >
#define minheap priority_queue < ll, std::vector<ll>, std::greater<ll> >   // mxheap.push(), mxheap.top(), mxheap.pop()
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
// using namespace FastIO;
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
struct DSU{
    int tsize;
    vector<ll> parent;
    vector<ll> rank;
    vector<ll> size;
    ll ans = 0;
    void init(int n)
    {
        tsize = n;
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i =1 ;i<=n;i++)
        {
            parent[i] = i;
        }   
    }
    ll getParent(ll a) {
        ll i = a;
        while(parent[i] != i)
        {
            i = parent[i];
        }
        return i;
    }
    int doUnion(ll newa, ll newb) {
        ll a = getParent(newa);
        ll b = getParent(newb);
        if (a != b) {

            if(rank[a] < rank[b])
            {
                ll temp = a;
                a = b;
                b = temp;
            }
            if(rank[a] == rank[b])
            {
                rank[a] += 1;
            }
            parent[b] = a;
            ans += size[a]*size[b];
            size[a] += size[b];
            size[b] = 0;
            return 1;
        } 
        else
            return 0;  
    }
    ll getAns()
    {
        return ans;
    }
};
bool comp(tuple<int,int,int>& a,tuple<int,int,int>& b)
{
    return get<2>(a) < get<2>(b);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    // freopen("mixmilk.in", "r", stdin);
    // freopen("mixmilk.out", "w", stdout);
    //cin>>T;
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,q;
        cin>>n>>q;
        vector<tuple<int,int,int>> edges;
        for(int i = 0;i<n-1;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            edges.pb({a,b,c});
        }
        sort(edges.begin(),edges.end(),comp);
        
        vector<pair<int,int>> queries(q);
        for(int i = 0;i<q;i++)
        {
            cin>>queries[i].first;
            queries[i].second = i;
        }
        sort(queries.begin(),queries.end());
        DSU mydsu;
        mydsu.init(n+1);
        vector<ll> answer(q);
        int j = 0;
        for(int i=0;i<q;i++)
        {
            while(j < edges.size())
            {
                if(get<2>(edges[j]) <= queries[i].first)
                {
                    mydsu.doUnion(get<0>(edges[j]),get<1>(edges[j]));
                    j++;
                }
                else
                {
                    break;
                }
            }
            answer[queries[i].second] = mydsu.getAns();
        }
        for(int i = 0;i<q;i++)
        {
            cout<<answer[i]<<" ";
        }
    }

    return 0;
}

