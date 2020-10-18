
// Problem: B. Putting Bricks in the Wall
// Contest: Codeforces - Codeforces Round #676 (Div. 2)
// URL: https://codeforces.com/contest/1421/problem/B
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
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    for(int t = 1;t<=T;t++)
    {
        int n;
        cin>>n;
        vector<string> v(n);
        for(int i = 0;i<n;i++)
        {
        	cin>>v[i];
        }
        int a,b,c,d,e;
        a = v[0][1] - '0';
        b = v[1][0] - '0';
        c = v[n-2][n-1] - '0';
        d = v[n-1][n-2] - '0';
        int count = 0;
        vector<pair<int,int>>  ans;
        if(a == 1 && b == 1)
        {
        	if(c == 1)
        	{
        		count++;
        		ans.pb({n-2,n-1});
        	}
        	if(d == 1)
        	{
        		count++;
        		ans.pb({n-1,n-2});
        	}
        }
        if(a == 0 && b == 0)
        {
        	if(c == 0)
        	{
        		count++;
        		ans.pb({n-2,n-1});
        	}
        	if(d == 0)
        	{
        		count++;
        		ans.pb({n-1,n-2});
        	}
        }
        if(a == 0 && b == 1)
        {
        	if(c == 1)
        	{
        		count++;
        		ans.pb({1,0});
        		if(d == 0)
        		{
        			count++;
        			ans.pb({n-1,n-2});
        		}
        	}
        	else
        	{
        		count++;
        		ans.pb({0,1});
        		if(d == 1)
        		{
        			count++;
        			ans.pb({n-1,n-2});
        		}
        	}
        }
        if(a == 1 && b == 0)
        {
        	if(c == 1)
        	{
        		count++;
        		ans.pb({0,1});
        		if(d == 0)
        		{
        			count++;
        			ans.pb({n-1,n-2});
        		}
        	}
        	else
        	{
        		count++;
        		ans.pb({1,0});
        		if(d == 1)
        		{
        			count++;
        			ans.pb({n-1,n-2});
        		}
        	}
        }
        cout<<count<<endl;
        for(int i  =0;i<count;i++)
        {
        	cout<<ans[i].first + 1<<" "<<ans[i].second + 1<<endl;
        }
        
        
        
    }

    return 0;
}
