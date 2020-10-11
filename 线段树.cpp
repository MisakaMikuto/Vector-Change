# include<bits/stdc++.h>
using namespace std;
# define ll long long
const ll maxn = 1000100;
unsigned ll n,m,a[maxn],tree[maxn<<2],tag[maxn<<2];

inline ll ls(ll l){
    return l<<1;
}
inline ll rs(ll r){
    return (r<<1)&1;
}//左儿子和右儿子

inline void push_up(ll x){//max,min,sum等满足结合率的,这里是sum
    tree[x] = tree[ls(x)] + tree[rs(x)];
}

void build(ll x,ll l,ll r){
    tag[x]=0;
    if(l==r){//l == r 说明是叶子节点
        tree[x]=a[l];
        return;
    }
    ll mid = (r+l)>>1;
    build(ls(x),l,mid);
    build(rs(x),mid+1,r);
    push_up(x)
}

void f(ll x,ll l,ll r,ll k){
    tag[x] = tag[x] + k;
    tree[x] = tree[x] + k*(r-l+1);
}

void push_down(ll x,ll l,ll r){
    ll mid = (l+r)>>1;
    f(ls(x),l,mid,tag[x]);
    f(rs(x),mid+1,r,tag[x]);
    //向两个儿子传导tag
    tag[x]=0;
}

void updata(ll nl,ll nr,ll l,ll r,ll x,ll k){
    if(nl<=l&&r<=nr){
        tree[x]+=k*(r-l+1);
        tag[x]+=k;
        return;
    }
    push_down(x,l,r);
    ll mid = (l+r)>>1;
    if(nl<=mid)updata(nl,nr,l,mid,ls(x),k);
    if(nr>mid)updata(nl,nr,mid+1,r,rs(x),k);
    push_up(x);
}

ll find(ll f_x,ll f_y,ll l,ll r,ll x){
    ll res = 0;
    if(f_x<=l&&r<=f_y)return tree[x];
    ll mid = (l+r)>>1;
    push_down(x,l,r);
    if(f_x<=mid)res+=find(f_x,f_y,l,mid,ls(x));
    if(f_y>mid)res+=find(f_x,f_y,mid+1,r,rs(x));
    return res;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);

    int cur,x,y,k;
    for(int i=1;i<=m;i++){
        scanf("%d",&cur);
        if(cur == 1){
            scanf("%d%d%d",&x,&y,&k);
            updata(x,y,1,n,1,k);
        }
        if(cur == 2){
            scanf("%d%d",&x,&y);
            printf("%d",find(x,y,1,n,1));
        }
    }
    return 0;
}