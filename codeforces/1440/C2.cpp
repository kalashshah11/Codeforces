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
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    // freopen("mixmilk.in", "r", stdin);
    // freopen("mixmilk.out", "w", stdout);
    cin>>T;
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,m;
        cin>>n>>m;
        vector<vector<int>> x(n,vector<int>(m));
        vector<string> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                x[i][j] = v[i][j] - '0';
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(x[i][j] == 1 && j!= m-1)
                {
                    vector<int> z{i+1,j+1,i+2,j+1,i+2,j+2};
                    ans.push_back(z);
                    // cout<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+1<<" "<<i+2<<" "<<j+2<<endl;
                    x[i][j] = 0;
                    x[i+1][j+1] = 1-x[i+1][j+1];
                    x[i+1][j] = 1-x[i+1][j];
                }
                else if(x[i][j] == 1 && j == m-1)
                {
                    vector<int> z{i+1,j+1,i+2,j+1,i+2,j};
                    ans.push_back(z);
                    // cout<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+1<<" "<<i+2<<" "<<j<<endl;
                    x[i][j] = 0;
                    x[i+1][j-1] = 1-x[i+1][j-1];
                    x[i+1][j] = 1-x[i+1][j];
                }
            }
        }
        int i = n-2; 
        for(int j = 0;j<m-2;j++)
        {
            if(x[i][j] == 0 && x[i+1][j] == 1)
            {
                ans.push_back(vector<int>{i+2,j+1,i+2,j+2,i+1,j+2});
                // cout<<i+2<<" "<<j+1<<" "<<i+2<<" "<<j+2<<" "<<i+1<<" "<<j+2<<endl;
                x[i+1][j] = 0;
                x[i+1][j+1] = 1-x[i+1][j+1];
                x[i][j+1] = 1-x[i][j+1];
            }
            else if(x[i][j] == 1 && x[i+1][j] == 1)
            {
                ans.push_back(vector<int>{i+1,j+1,i+2,j+1,i+2,j+2});
                // cout<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+1<<" "<<i+2<<" "<<j+2<<endl;
                x[i][j] = 0;
                x[i+1][j] = 0;
                x[i+1][j+1] = 1-x[i+1][j+1];
            }
            else if(x[i][j] == 1 && x[i+1][j] == 0)
            {
                ans.push_back(vector<int>{i+1,j+1,i+2,j+2,i+1,j+2});
                // cout<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+2<<" "<<i+1<<" "<<j+2<<endl;
                x[i][j] = 0;
                x[i+1][j+1] = 1-x[i+1][j+1];
                x[i][j+1] = 1-x[i][j+1];
            }
        }
        int j = m-2;
        int count = 0;
        if(x[i][j])
            count++;
        if(x[i+1][j+1])
            count++;
        if(x[i][j+1])
            count++;
        if(x[i+1][j])
            count++;
        if(count == 4)
        {
            ans.push_back(vector<int>{i+1,j+1,i+1,j+2,i+2,j+2});
            
            ans.push_back(vector<int>{i+1,j+2,i+2,j+2,i+2,j+1});
            
            ans.push_back(vector<int>{i+2,j+2,i+2,j+1,i+1,j+1});
           
            ans.push_back(vector<int>{i+2,j+1,i+1,j+1,i+1,j+2});

        }
        else if(count == 3)
        {
            vector<int> v;
            if(x[i][j])
            {
                v.pb(i+1);
                v.pb(j+1);
            }
            if(x[i][j+1])
            {
                v.pb(i+1);
                v.pb(j+2);
            }
            // cout<<i+1<<" "<<j+2<<" ";
            if(x[i+1][j])
            {
                v.pb(i+2);
                v.pb(j+1);
            }
            // cout<<i+2<<" "<<j+1<<" ";
            if(x[i+1][j+1])
            {
                v.pb(i+2);
                v.pb(j+2);
            }
            ans.pb(v);
        }
        else if(count == 2)
        {
            vector<pair<int,int>> v;
            vector<pair<int,int>> v1;
            if(!x[i][j])
            {
                v.pb({i+1,j+1});
            }
            else
            {
                v1.pb({i+1,j+1});
            }
            if(!x[i][j+1])
            {
                v.pb({i+1,j+2});
            }
            else
            {
                v1.pb({i+1,j+2});
            }
            if(!x[i+1][j])
            {
                v.pb({i+2,j+1});
            }
            else
            {
                v1.pb({i+2,j+1});
            }
            if(!x[i+1][j+1])
            {
                v.pb({i+2,j+2});
            }
            else
            {
                v1.pb({i+2,j+2});
            }
            ans.pb(vector<int>{v[0].first,v[0].second,v[1].first,v[1].second,v1[0].first,v1[0].second});
            ans.pb(vector<int>{v[0].first,v[0].second,v[1].first,v[1].second,v1[1].first,v1[1].second});
        }
        else if(count == 1)
        {
            if(x[i][j])
            {
                ans.pb(vector<int>{i+1,j+1,i+1,j+2,i+2,j+1});
                ans.pb(vector<int>{i+1,j+1,i+1,j+2,i+2,j+2});
                ans.pb(vector<int>{i+1,j+1,i+2,j+2,i+2,j+1});
                // cout<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+2<<" "<<i+2<<" "<<j+2<<endl;
                // cout<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+2<<" "<<i+2<<" "<<j+1<<endl;
            }
            if(x[i][j+1])
            {
                ans.pb(vector<int>{i+1,j+1,i+1,j+2,i+2,j+1});
                ans.pb(vector<int>{i+1,j+1,i+1,j+2,i+2,j+2});
                ans.pb(vector<int>{i+2,j+2,i+1,j+2,i+2,j+1});
                // cout<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+2<<" "<<i+2<<" "<<j+1<<endl;
                // cout<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+2<<" "<<i+2<<" "<<j+2<<endl;
                // cout<<i+2<<" "<<j+2<<" "<<i+1<<" "<<j+2<<" "<<i+2<<" "<<j+1<<endl;
            }
            if(x[i+1][j])
            {
                ans.pb(vector<int>{i+1,j+1,i+1,j+2,i+2,j+1});
                ans.pb(vector<int>{i+1,j+1,i+2,j+2,i+2,j+1});
                ans.pb(vector<int>{i+1,j+2,i+2,j+2,i+2,j+1});
                // cout<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+2<<" "<<i+2<<" "<<j+1<<endl;
                // cout<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+2<<" "<<i+2<<" "<<j+1<<endl;
                // cout<<i+1<<" "<<j+2<<" "<<i+2<<" "<<j+2<<" "<<i+2<<" "<<j+1<<endl;
            }
            if(x[i+1][j+1])
            {
                ans.pb(vector<int>{i+1,j+1,i+2,j+2,i+2,j+1});
                ans.pb(vector<int>{i+1,j+1,i+2,j+2,i+1,j+2});
                ans.pb(vector<int>{i+1,j+2,i+2,j+2,i+2,j+1});
                // cout<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+2<<" "<<i+2<<" "<<j+1<<endl;
                // cout<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+2<<" "<<i+1<<" "<<j+2<<endl;
                // cout<<i+1<<" "<<j+2<<" "<<i+2<<" "<<j+2<<" "<<i+2<<" "<<j+1<<endl;
            }
        }
        cout<<ans.size()<<endl;
        for(int  i = 0;i<ans.size();i++)
        {
            // assert(ans[i].size() == 6);
            for(int j = 0;j<ans[i].size();j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    
    
    }

    return 0;
}

