#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<cstdio>

#define MAX 1000
char st[MAX];
int top = -1;
void push(char st[],char);
char pop(char st[]);
void In2Post(char source[],char target[]);
int Prio(char);

int main()
{
	int i,n,count=0;
	char infix[1000], postfix[1000],str[5],ch;
	scanf("%d", &n);getchar();getchar();
	for(int k=0;k<n;k++)
	{
		i=0;
		while(gets(str))
		{
			if(str[0]=='\0') break;
			ch=str[0];
			infix[i++]=ch;
		}
		infix[i]='\0';
		strcpy(postfix,"");
		In2Post(infix,postfix);
		puts(postfix);
		printf("\n");
	}
	return 0;
}



void In2Post(char source[], char target[])
{
	int i=0, j=0;
	char temp;
	strcpy(target,"");
	while (source[i]!='\0')
	{
		if(source[i]=='(')
		{
			push(st,source[i]);
			i++;
		}
		else if(source[i] ==')')
		{
			while((top!=-1)&& (st[top]!='('))
			{
				target[j] = pop(st);
				j++;
			}
			//if(top==-1)
			//{
			//	printf("INCORRECT EXPRESSION");
			//	exit(1);
			//}
			temp = pop(st); //remove parenthesis
			i++;
		}
		else if(isdigit(source[i])||isalpha(source[i]))
		{
			target[j]=source[i];
			j++;
			i++;
		}
		else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%')
		{
			while( (top!=-1 && (st[top]!= '(') && Prio(st[top])>=Prio(source[i])))
			{
				target[j] = pop(st);
				j++;
			}
			push(st,source[i]);
			i++;
		}
		//else
		//{
		//	printf("\nINCORRECT ELEMENT IN EXPRESSION");
		//	exit(1);
		//}
	}
	while((top!=-1) && (st[top]!='('))
	{
		target[j] = pop(st);
		j++;
	}
	target[j]='\0';
}

int Prio(char op)
{
	if(op=='/'|op=='*'||op=='%')
		return 1;
	else if(op=='+'||op=='-')
		return 0;
}

void push(char st[],char val)
{
	if(top == MAX-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		top++;
		st[top] = val;
	}
}

char pop(char st[])
{
	char val = ' ';
	if(top == -1)
	{
		printf("\nSTACK UNDERFLOW");
	}
	else
	{
		val = st[top];
		top--;
	}
	return val;
}
