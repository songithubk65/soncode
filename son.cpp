#include<bits/stdc++.h>
#define LL long long
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define ii pair<int,int>
#define iii pair<LL,ii>
#define st first
#define nd second
#define TASK "steinertree"
using namespace std;
///---------------------------------------------------
const int N = 1e5 + 5;
vector <ii> a[N];
int n, m, k, ok[N], s;
LL D[N][35];
///---------------------------------------------------
void nhap(){
    cin>>n>>m;
    fo(i,1,m){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    cin>>k;
    fo(i,1,k){
        int tmp;
        cin>>tmp;
        ok[tmp] = i;
    }
    s =(1<<k)-1;
    fo(i,1,n) fo(j,0,34) D[i][j] =  1e9;
}
///---------------------------------------------------
void solve(){
    priority_queue<iii,vector<iii>,greater<iii> > q;
    fo(i,1,n) if(ok[i]){
        int cnt = 1<<(ok[i]-1);
        q.push({0,{i,cnt}});
        D[i][cnt]=0;
    }
    while(!q.empty()){
        int i = q.top().nd.st, tmp = q.top().nd.nd, c = q.top().st;
        q.pop();
        if (D[i][tmp]!=c) continue;
        if(tmp==s) {cout<<D[i][s]<<'\n'; return;}
        rep(j,0,a[i].size()){
            int v = a[i][j].st, prev = tmp;
            c = a[i][j].nd;
            if (ok[v]) prev|=(1<<(ok[v]-1));
            if (D[v][prev]<=D[i][tmp]+c) continue;
            D[v][prev]=D[i][tmp]+c;
            q.push({D[v][prev],{v,prev}});
        }
        fo(j,0,34) if(D[i][j|tmp]>D[i][j]+D[i][tmp]){
                D[i][j|tmp]=D[i][j]+D[i][tmp];
                q.push({D[i][j|tmp],{i,j|tmp}});
        }
    }
}
///---------------------------------------------------
int main(){
    #ifndef ONLINE_JUDGE
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    nhap();
    solve();
}