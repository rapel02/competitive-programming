#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x1,x2,y1,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	while(x1 && y1 && x2 && y2 !=0)
	{
		if(abs(x1-x2) +abs(y1-y2)==0) printf("0\n");
		else if(abs(x1-x2) == abs(y1-y2)) printf("1\n");
		else if(x1==x2) printf("1\n");
		else if(y1==y2) printf("1\n");
		else printf("2\n");
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);	
	}
}
