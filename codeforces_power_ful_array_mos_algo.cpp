//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
//using simple mos algorithm
// just a slight conversion in the basic remove and add because of the problem statement
#define sz 200009
long long int ans[sz];
long long int a[sz];
long long int freq[1000006];
long long int bl = 500;
long long int sum = 0;
struct query{
   long long  int left;
    long long int right;
    long long int idx;
}vv[sz];

bool cmp(query A,query B){
    if((A.left/bl) == (B.left/bl)){
        return A.right < B.right;
    }
    else{
        return (A.left/bl) < (B.left/bl);
    }
}
   
    void add(long long int i){
           freq[a[i]]++;
		   	   sum = sum - ((freq[a[i]] - 1) * (freq[a[i]] - 1)*a[i]) + ((freq[a[i]]) * (freq[a[i]])*a[i]);
		   return;
    }
    void remo(long long int i){
        freq[a[i]]--;
        sum = sum + (freq[a[i]] * freq[a[i]] * a[i]) - ((freq[a[i]] + 1) * (freq[a[i]] + 1) * a[i]);
    }
int main(){
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    long long int t,n,i,j;
    long long int l,r;
   // scanf("%lld %lld",&n,&t);
   cin >> n >> t;
    for(i = 0;i<n;i++) scanf("%lld",&a[i]);
    for(i = 0;i<t;i++){
        scanf("%lld %lld",&l,&r);
        vv[i].left = l-1;
        vv[i].right = r-1;
        vv[i].idx = i;
    }
   sort(vv,vv+t,cmp); // VV + T
    l = 0;
    r = -1;
    for(i = 0;i<t;i++){
        while(r < vv[i].right) add(++r);
        while(l < vv[i].left) remo(l++);
        while(r > vv[i].right) remo(r--);
        while(l > vv[i].left) add(--l);
        ans[vv[i].idx] = sum;
    }
    for(i = 0;i<t;i++) printf("%lld\n",ans[i]);
    return 0;
}
