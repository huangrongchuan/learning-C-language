#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
	char s[100];
	char p[100];
	char *pa[100]={0};//每次在s中匹配到的指针； 
	char find[10][100]={0};
	int *position[10]={0};
	char choose;
	char save;
	int h=0;
	
	int i,j,a;//计数 
	
	printf("输入 s:");//输入s、p字符串，选择是否忽略大小写 
	gets(s);
	printf("输入 p:");
	gets(p);
	printf("是否忽略大小写（y/n）:");
	choose=getchar();
	
	if(choose=='y');//若忽略大小写，将所有字符改为小写 
	{
		for(i=0;i<100;i++)
		{
			if(s[i]>=65&&s[i]<=90)
				s[i]=s[i]+32;
			if(p[i]>=65&&p[i]<=90)
				p[i]=p[i]+32;
		}
	}
	/*strcpy(find[0],p);
	for(i=0,j=0,a=0;p[j]!='\0';i++,j++)//将p进行切割 
	{
		if(p[j]==46||p[j]==42)//46为.42为*
		{
			strcpy(find[a+1],find[a]+i+1);
			find[a][i]='\0';
			i=0; a++;
		} 
	}
	
	for(i=0;p[i]==0;i++)//i为找到的个数 
	{
		for(j=0;find[j][0]!='\0';j++)//将切开的字符逐个比较 
		{
			found[j]=strstr(s,find[j]);
			if(found==NULL)
				break;
			else
			{
				
			}	
		}
	}*/
	for(a=0;position[a-1]+h!='0';)
	{
		if(a==0)
			pa[0]=strchr(s,p[0]);
		if(a!=0)
			pa[0]=strchr(position[a-1]+h,p[0]);
		for(i=0,j=0;p[i+1]!='\0';i++)
		{
			if(p[i+1]!=42&&p[i+1]!=46)
			{
				pa[j+1]=strchr(pa[0],p[i+1]);
				
				if(pa[j+1]==NULL||pa[j+1]<pa[j])
				{
				//	a--;
					h++;
					goto here;
				}
				j++;
			}	
		}
	
		for(i=0,j=0;p[j+1]!='\0';i++,j++)//pa[]指针是否连续 
		{
			if((pa[i+1]-pa[i])!=1)
			{
				if(p[j+1]=='*')
					j++;
				if(p[j+1]=='.')
				{
					if((pa[i+1]-pa[i])==2)
						j++;
					else
					{
						//a--;
						h++;
						goto here;
					}
						
				}
			}
		}
		strcpy(find[a],pa[0]);
		find[a][pa[i]-pa[0]+1]='\0';
		position[a]=pa[i];
		puts(find[a]);
		a++;
		h=0;
		here:
		for(i=0;i<10;i++)
		{
			pa[i]=0;
		}
		//getchar();
	}
	
	
	for(i=0;find[i][0]!='\0';i++)
	{
		puts(find[i]);
	}
	/*puts(s);
	puts(p);*/
}









