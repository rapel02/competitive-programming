#include<bits/stdc++.h>
using namespace std;

int tot = 0;
int k,x,y;

bool iscenter(int a,int b,int c){
	if(a-b<=c && c<=a+b) return true;
	return false;
}

bool isinside(int px,int py,int k)
{
	return iscenter(px,k,x) && iscenter(py,k,y);
}

void process(int px,int py,int k)
{
	if(k==0) return ;
	if(isinside(px,py,k)==true) tot++;
	process(px-k,py-k,k/2);
	process(px+k,py-k,k/2);
	process(px+k,py+k,k/2);
	process(px-k,py+k,k/2);
}

int main()
{
	while(cin>>k>>x>>y)
	{
		tot = 0;
		if(k==0 && x==0 && y==0) break;
		process(1024,1024,k);
		printf("%3d\n",tot);
	}
}
