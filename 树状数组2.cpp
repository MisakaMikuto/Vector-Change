# include<bits/stdc++.h>
using namespace std;
const int maxn = 500100;
int tree[maxn],a[maxn],n,m;

//树状数组实现区间修改，单点查询

int lowbit(int x){
    return x & (-x);
}

void updata(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}

int find(int x){
    int ans = 0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

int main(){
    
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int cur;
    for(int i=1;i<=m;i++){
        cin >> cur;
        if(cur == 1){
            int x,y,k;
            cin >> x >> y >> k;
            updata(x,k);
            updata(y+1,-k);
        }
        if(cur == 2){
            int x;
            cin >> x;
            cout << a[x]+find(x) << endl;
        }
    }
    return 0;
}