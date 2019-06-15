#include<bits/stdc++.h>
using namespace std;

string in1,in2;

bool sy[50];
bool ad[50];

int main()
{
	int idx;
	while(cin>>idx)
	{
		if(idx==-1) break;
		cin>>in1>>in2;
		memset(sy,0,sizeof(sy));
		memset(ad,0,sizeof(ad));
		bool iswin = false;
		int app = 0;
		int err = 0;
		int tot = 0;
		int len = in1.length();
		for(int a=0;a<len;a++)
		{
			if(ad[in1[a]-'a']==false) tot++;
			ad[in1[a]-'a'] = true;
		}
		len = in2.length();
		for(int a=0;a<len;a++)
		{
			if(sy[in2[a]-'a'] == true) continue;
			else if(ad[in2[a]-'a'] == true)
			{
				app++;
				if(app == tot && err < 7) iswin = true; 
			}
			else err++;
			sy[in2[a]-'a'] = true;
		}
		printf("Round %d\n",idx);
		if(iswin==true) printf("You win.\n");
		else if(iswin==false && err < 7) printf("You chickened out.\n");
		else printf("You lose.\n");
	}
}
