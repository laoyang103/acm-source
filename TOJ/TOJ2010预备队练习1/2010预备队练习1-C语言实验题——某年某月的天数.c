#include<stdio.h>
#include<string.h>
char days[]="0646565665656";
int main()
{
	char input[10];
	int year,month;
	int i,monthFlag;
	gets(input);
	i=0;
	monthFlag=0;
	month=year=0;
	while(input[i])
	{
		if(input[i]=='\\')
		{
			monthFlag=1;
			++i;
			continue;
		}
		if(!monthFlag)
			year=year*10+input[i]-48;
		else month=month*10+input[i]-48;
		++i;
	}
	if(month==2)
	{
		if(year%4==0 && (year%100!=0 || year%400==0))
		{
			printf("29\n");
		}
		else printf("28\n");
	}
	else printf("%d\n",days[month]-'5'+30);
	return 0;
}
