#include<bits/stdc++.h>
//HERE WE HAVE USED THE LAZY_PROPAGATION_DATA_STRUCTURE TO CALCULATE WHICH INDEX CAME HOW MANY TIMES INSIDE THE QUERY
//SO THAT WE CAN DETERMINE AND REORDER THE MAIN ARRAY USING THOSE INDEX IN SUCH A WAY THAT WE ALWAYS GET THE SUM OF THE
// QUERIES MAXIMUM  
using namespace std;
#define maxN 200003
long long int ar[maxN];
long long int st[4*maxN] , lazy[4*maxN];
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
void build(long long int si , long long int ss , long long int se)
{
	if(ss == se)
	{
		st[si] = ar[ss];
		return;
	}
	
	long long int mid = (ss + se) / 2;
	
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);
	
	st[si] = st[2*si] + st[2*si+1];
}

long long int query(long long int si , long long int ss , long long int se , long long int qs , long long int qe)
{
	if(lazy[si] != 0)
	{
		long long int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);
		
		if(ss != se)
		lazy[2*si] += dx , lazy[2*si+1] += dx;
	}
	
	if(ss > qe || se < qs) return 0;
	
	if(ss >= qs && se <= qe)
	return st[si];
	
	long long int mid = (ss + se) / 2;
	return query(2*si , ss , mid , qs , qe) + query(2*si+1 , mid+1 , se , qs , qe);
}

void update(long long int si , long long int ss , long long int se , long long int qs ,long long  int qe , long long int val)
{
	if(lazy[si] != 0)
	{
		long long int dx = lazy[si];
		lazy[si] = 0;                                                                                                        
		st[si] += dx * (se - ss + 1);
		
		if(ss != se)
		lazy[2*si] += dx , lazy[2*si+1] += dx;
	}
	
	if(ss > qe || se < qs) return;
	
	if(ss >= qs && se <= qe)
	{
		long long int dx = (se - ss + 1) * val;
		st[si] += dx;
		if(ss != se)
		lazy[2*si] += val , lazy[2*si+1] += val;
		return;
	}
	
	long long int mid = (ss + se) / 2;
	update(2*si , ss , mid , qs , qe , val);
	update(2*si+1 , mid+1 , se , qs , qe , val);
	
	st[si] = st[2*si] + st[2*si+1];
}


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
    for(i = 0;i<n;i++) cin >> arr[i];
	build(1 , 0 , n-1);
	while(q--)
       {	
            cin >> l >> r;
            get.l = l-1;
            get.r = r-1;
            vv.push_back(get);
			update(1 , 0 , n-1 , l-1 , r-1 , 1);
       }
    for(i = 0;i<n;i++) {
        ge.idx = i;
        ge.val = query(1,0,n-1,i,i);
        bb.push_back(ge);
    }
    sort(bb.begin(),bb.end(),cmp);
    sort(arr,arr+n);
    // below is the reordering of the main array so that the sum gets maximum according to all the queries of our input.
    for(i = n-1;i>=0;i--){
        temp[bb[i].idx] = arr[i];
    }
    long long int sum = temp[0];
    long long int result = 0;
    //prefix sum calculated 
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
// THIS PROBLEM IS ONE OF MY BEST IN CODEFORCES !!!!
//KEEP CODING CONSISTENTLY !!!!






