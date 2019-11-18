#include<stdio.h>
#include<string.h>
struct D
{
	char sn[10];
	char rn[10];
	int fre;
}S[10000];
struct h
{
	char hn[10];
}H[10000];
struct R
{
	char o[10];
}r[10000];
int main()
{
	FILE *fp;
	int i,j,c,k,l,a,m,n;
	char filename[10];
	gets(filename);
	fp = fopen(filename,"r");
	if (fp == NULL)
	{
		printf("error\n");
		return -1;
	}
	i=0;
	rewind(fp);
	while(feof(fp)==0)
	{
		fscanf(fp,"%s %s %d\n",&S[i].sn,&S[i].rn,&S[i].fre);
		i++;
	}
	fclose(fp);
	c=0;
	for (j=0;j<=i;j++)
	{
		if (int(S[j].fre) >= 100)
		{	
			strcpy(H[c].hn,S[j].sn);
			c++;
		}
	}
	strcpy(H[0].hn,S[0].sn);
	a=0;
	for (k=0;k<=c;k++)
	{
		if (strcmp(H[a].hn,S[k].sn)==0)
			continue;
		else
		{
			a++;
			strcpy(r[a].o,S[k].sn);
		}
	}
	printf("%d\n",a+1);
	for (l=0;l<=a;l++)
		printf("%s\n",r[l].o);
	return 0;
}