#include<bits/stdc++.h>
using namespace std;
//HERE INSTEAD OF USING COMPLEX DATA STRUCTURES I HAVE USED A VERY SIMPLE AND EASY TO UNDERSTAND CUMSUM RELATED TECHNIQUE
//HOPE YOU ENJOY THIS SOLUTION MORE THAN THE PREVIOUS ONE
#define maxN 200003
struct edge{
    long long int l,r;
};
struct ed{
   long long int idx,val;
};
bool cmp(ed A,ed B){
    return A.val < B.val;
}
vector <ed> bb;
vector <edge> vv;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    edge get;
    ed ge;
    long long int i,j;
	long long int n , q , code , l , r , val;
	cin>>n>>q;
    long long int arr[n];
    long long int temp[n];
    long long int tt[n];
    memset(tt,0,sizeof(tt));
    for(i = 0;i<n;i++) cin >> arr[i];
	while(q--)
       {
           cin >> l >> r;
           get.l = l-1;
           get.r = r-1;
           //the cumsum technique
            l--;
            r--;
            tt[l]++;
            if(r+1 <= (n-1)) tt[r+1]--;
            vv.push_back(get);
       }
       // the freq array of the index
       for(i = 1;i<n;i++) tt[i] = tt[i] + tt[i-1];
       for(i = 0;i<n;i++){
           ge.idx = i;
           ge.val = tt[i];
           bb.push_back(ge);
       }
    sort(bb.begin(),bb.end(),cmp);
    sort(arr,arr+n);
    for(i = n-1;i>=0;i--){
        temp[bb[i].idx] = arr[i];
    }
    long long int sum = temp[0];
    long long int result = 0;
    for(i = 1;i<n;i++){
        sum = sum + temp[i];
        temp[i] = sum;
    }
    long long int len = vv.size();
    for(i = 0;i<len;i++){
        if(vv[i].l != 0){
            result += temp[vv[i].r] - temp[vv[i].l - 1];
        }
        else{
            result += temp[vv[i].r];
        }
    }
    cout << result << "\n";
  return 0;
}







