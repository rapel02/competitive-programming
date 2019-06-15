#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e+5;

struct node{
	int val;
	int tot;
	int lval;
	int ltot;
	int rval;
	int rtot;
}ST[4*MAXN + 5];

int arr[MAXN + 5];

void build(int idx,int l,int r)
{
	if(l == r)
	{
		ST[idx].val = arr[l];
		ST[idx].tot = 1;
		ST[idx].lval = ST[idx].rval = arr[l];
		ST[idx].ltot = ST[idx].rtot = 1;
		//printf("%d %d %d %d\n",idx,l,r,ST[idx].val,ST[idx].tot);
		return ;
	}
	int mid = (l + r)/2;
	build(2*idx,l,mid);
	build(2*idx + 1,mid+1,r);
	int le = 2 * idx;
	int ri = 2 * idx + 1;
	int v1 = ST[le].tot;
	int v2 = ST[le].rtot;
	if(ST[ri].lval == ST[le].rval) v2 += ST[ri].ltot;
	int v3 = ST[ri].tot;
	int tar = 0;
	int rem = 0;
	//printf("MID: %d\n",mid);
	//printf("Value: %d %d\n",ST[ri].lval,ST[le].rval);
	//printf("Total: %d %d\n",ST[ri].ltot,ST[le].rtot);
	//printf("%d %d %d\n",v1,v2,v3);
	if(v1 >= v2 && v1 >= v3) tar = v1,rem = ST[le].val;
	else if(v2 >= v1 && v2 >= v3) tar = v2,rem = ST[le].rval;
	else tar = v3,rem = ST[ri].val;
	//printf("rem: %d tar: %d\n",rem,tar);
	ST[idx].val = rem;
	ST[idx].tot = tar;
	ST[idx].lval = ST[le].lval;
	ST[idx].ltot = ST[le].ltot;
	if(ST[le].lval == ST[ri].lval) ST[idx].ltot += ST[ri].ltot;
	ST[idx].rval = ST[ri].rval;
	ST[idx].rtot = ST[ri].rtot;
	if(ST[ri].rval == ST[le].rval) ST[idx].rtot += ST[le].rtot;
	//printf("%d %d %d %d\n",idx,l,r,ST[idx].val,ST[idx].tot);
}

node query(int idx,int l,int r,int lb,int ub)
{
	if(lb <= l && r <= ub) return ST[idx];
	if(l > ub || r < lb)
	{
		node temp;
		temp.tot = -1;
		return temp;
	}
	int mid = (l + r)/2;
	node le = query(2*idx,l,mid,lb,ub);
	node ri = query(2*idx+1,mid+1,r,lb,ub);
	if(le.tot == -1) return ri;
	if(ri.tot == -1) return le;
	node ans;
	int v1 = le.tot;
	int v2 = le.rtot;
	if(ri.lval == le.rval) v2 += ri.ltot;
	int v3 = ri.tot;
	int tar = 0;
	int rem = 0;
	if(v1 >= v2 && v1 >= v3) tar = v1,rem = le.val;
	else if(v2 >= v1 && v2 >= v3) tar = v2,rem = le.rval;
	else tar = v3,rem = ri.val;
	ans.val = rem;
	ans.tot = tar;
	ans.lval = le.lval;
	ans.ltot = le.ltot;
	if(le.lval == ri.lval) ans.ltot += ri.ltot;
	ans.rval = ri.rval;
	ans.rtot = ri.rtot;
	if(le.rval == ri.rval) ans.rtot += le.rtot;
	return ans;
}

int main()
{
	int n,q;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		scanf("%d",&q);
		for(int a=1;a<=n;a++) scanf("%d",&arr[a]);
		build(1,1,n);
		for(int a=1;a<=q;a++)
		{
			int l,r;
			scanf("%d %d",&l,&r);
			node ANS = query(1,1,n,l,r);
			printf("%d\n",ANS.tot);
		}
	}
}
