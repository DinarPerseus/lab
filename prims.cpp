#include <bits/stdc++.h>
#define ll long long int
#define fo(i, n) for (int i = 0; i < n; i++)
#define ce cout << '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
using namespace std;



// BeginGraphClass
class graph
{
    int n;
    list<pll> *adj;
 
public:
    graph(int n)
    {
        this->n = n;
        adj = new list<pll>[n];
    }
 
    void addedge(int u,int v,int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
 
    int parent(int x,int dis[]){
        while (dis[x]!=x)
        {
            x=dis[x];
        }
        return x;
    }
   
 
 
    void solve(){
        priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> pq;
        bool visited[n]={0};
        visited[0]=1;
        for(auto v:adj[0])pq.push({v.second,{0,v.first}});
 
        ll cost =0,step=0;
        while (step<n-1&&!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            if (!visited[x.second.second])
            {
                step++;
                cost+=x.first;
                visited[x.second.second]=1;
                for(auto v:adj[x.second.second])pq.push({v.second,{x.second.second,v.first}});
 
            }
            
        }
 
        if (step==n-1)
        {
            cout<<cost;
        }else
        {
            cout<<"IMPOSSIBLE";
        }
        cout<<'\n';


    }
    
    
};
// EndGraph

 
// code gose here
void solve()
{
    int n,m;
    cin>>n>>m;
    graph g(n);
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u-1,v-1,w);
 
    }
 
    g.solve();

}
 
int main()
{

    // clock_t z = lock();
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}