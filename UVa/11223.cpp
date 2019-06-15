#include<bits/stdc++.h>
using namespace std;

string conv(string in)
{
	if(in==".-") return "A";
	if(in=="-...") return "B";
	if(in=="-.-.") return "C";
	if(in=="-..") return "D";
	if(in==".") return "E";
	if(in=="..-.") return "F";
	if(in=="--.") return "G";
	if(in=="....") return "H";
	if(in=="..") return "I";
	if(in==".---") return "J";
	if(in=="-.-") return "K";
	if(in==".-..") return "L";
	if(in=="--") return "M";
	if(in=="-.") return "N";
	if(in=="---") return "O";
	if(in==".--.") return "P";
	if(in=="--.-") return "Q";
	if(in==".-.") return "R";
	if(in=="...") return "S";
	if(in=="-") return "T";
	if(in=="..-") return "U";
	if(in=="...-") return "V";
	if(in==".--") return "W";
	if(in=="-..-") return "X";
	if(in=="-.--") return "Y";
	if(in=="--..") return "Z";
	if(in=="-----") return "0";
	if(in==".----") return "1";
	if(in=="..---") return "2";
	if(in=="...--") return "3";
	if(in=="....-") return "4";
	if(in==".....") return "5";
	if(in=="-....") return "6";
	if(in=="--...") return "7";
	if(in=="---..") return "8";
	if(in=="----.") return "9";
	if(in==".-.-.-") return ".";
	if(in=="--..--") return ",";
	if(in=="..--..") return "?";
	if(in==".----.") return "'";
	if(in=="-.-.--") return "!";
	if(in=="-..-.") return "/";
	if(in=="-.--.") return "(";
	if(in=="-.--.-") return ")";
	if(in==".-...") return "&";
	if(in=="---...") return ":";
	if(in=="-.-.-.") return ";";
	if(in=="-...-") return "=";
	if(in==".-.-.") return "+";
	if(in=="-....-") return "-";
	if(in=="..--.-") return "_";
	if(in==".-..-.") return "\"";
	if(in==".--.-.") return "@";
}

int main()
{
	int ntc;
	scanf("%d",&ntc); getchar();
	for(int tc=1;tc<=ntc;tc++)
	{
		if(tc!=1) printf("\n");
		string in="";
		printf("Message #%d\n",tc);
		int ct = 0;
		char temp;
		do
		{
			scanf("%c",&temp);
			if(temp==' ')
			{
				if(ct==0) cout<<conv(in);
				ct++;
				in = "";
				if(ct>1) printf(" ");
				continue;
			}
			else if(temp!='\n')
			{
				ct = 0;
				in += temp;
			}
		}while(temp!='\n');
		if(ct==0) cout<<conv(in);
		printf("\n");
	}
}
