#include<bits/stdc++.h>
using namespace std;

char inp[100005];


bool revv(char a,char b)
{
	if(a=='A' && b=='A') return true;
	if(a=='E' && b=='3') return true;
	if(a=='H' && b=='H') return true;
	if(a=='I' && b=='I') return true;
	if(a=='J' && b=='L') return true;
	if(a=='L' && b=='J') return true;
	if(a=='M' && b=='M') return true;
	if(a=='O' && b=='O') return true;
	if(a=='S' && b=='2') return true;
	if(a=='T' && b=='T') return true;
	if(a=='U' && b=='U') return true;
	if(a=='V' && b=='V') return true;
	if(a=='W' && b=='W') return true;
	if(a=='X' && b=='X') return true;
	if(a=='Y' && b=='Y') return true;
	if(a=='Z' && b=='5') return true;
	if(a=='1' && b=='1') return true;
	if(a=='2' && b=='S') return true;
	if(a=='3' && b=='E') return true;
	if(a=='5' && b=='Z') return true;
	if(a=='8' && b=='8') return true;
	else return false;
}

int main()
{
	while(scanf("%s",inp)!=EOF)
	{
		int len=strlen(inp);
		bool pal=true;
		bool rev=true;
		for(int a=0;a<len;a++)
		{
			if(inp[a]!=inp[len-1-a]) pal=false;
			if(revv(inp[a],inp[len-1-a])==false)
			{
				rev=false;
				//printf("%d %c %c\n",a,inp[a],inp[len-1-a]);
			}
		}
		if(rev==true &&pal ==true) printf("%s -- is a mirrored palindrome.\n",inp);
		else if(rev==true && pal==false) printf("%s -- is a mirrored string.\n",inp);
		else if(rev==false && pal==true) printf("%s -- is a regular palindrome.\n",inp);
		else printf("%s -- is not a palindrome.\n",inp);
		printf("\n");
	}
	return 0;
}
