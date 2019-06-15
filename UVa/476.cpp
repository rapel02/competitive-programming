#include<bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
};

struct Rectangle{
	Point ul,lr;
}rect[15];


int main()
{
	int k = 0;
	while(1)
	{
		char temp;
		scanf("%c",&temp); getchar();
		if(temp=='*') break;
		scanf("%lf %lf %lf %lf",&rect[k].ul.x,&rect[k].ul.y,&rect[k].lr.x,&rect[k].lr.y);
		getchar();
		k++;
	}
	int y = 0;
	while(1)
	{
		Point temp;
		scanf("%lf %lf",&temp.x,&temp.y);
		if(temp.x == 9999.9 && temp.y == 9999.9) break;
		bool ada = false;
		for(int a=0;a<k;a++)
		{
			if(temp.x > rect[a].ul.x && rect[a].lr.x > temp.x && temp.y < rect[a].ul.y && rect[a].lr.y < temp.y)
			{
				printf("Point %d is contained in figure %d\n",y+1,a+1);
				ada = true;
			}
		}
		if(ada==false) printf("Point %d is not contained in any figure\n",y+1);
		y++;
	}
}
