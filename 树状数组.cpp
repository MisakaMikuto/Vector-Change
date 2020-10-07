#include <bits/stdc++.h>
using namespace std;
const int maxn = 500100;
/*
已知一个数列，你需要进行下面两种操作：

将某一个数加上 x(修改)

求出某区间每一个数的和(区间和)
*/

int n,m,tree[maxn];

int lowbit(int x){
    return x & (-x);
}

void updata(int x,int k){
    while(x<=n){
        tree[x] += k;
        x += lowbit(x);
    }
}

long long sum(int x){
    long long ans = 0;
    while(x){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main(){
    cin >> n >> m ;
    int a ;
    for(int i=1;i<=n;i++){
        cin >> a;
        updata(i,a);
    }
    int cur,x,k;
    for(int i=1;i<=m;i++){
        cin >> cur >> x >> k;
        if(cur == 1){
            updata(x,k);
        }
        else if(cur == 2){
            cout << sum(k) - sum(x-1) << endl;
        }
    }
    return 0;
}