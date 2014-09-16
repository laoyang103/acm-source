#include <stdio.h>
#include <string.h>
char input[1001];
char otherChar[1001];
void sort()
{
	int i;
	int iz=0;
	int io=0;
	int ij=0;
	int i7=0;
	int it=0;//ÆäËû
	int len=0;
	for(i=0; input[i] != 0; ++i)
	{
		switch( input[i] )
		{
			case 'Z': ++iz; break;
			case 'O': ++io; break;
			case 'J': ++ij; break;
			case '7': ++i7; break;
			default: otherChar[it++]=input[i];break;
		}
	}
	otherChar[it]=0;
	for(i=0;i<iz;++i)
	{
		input[i]='Z';
	}
	for(len=i+io;i < len; ++i)
	{
		input[i]='O';
	}
	for(len=i+ij;i < len; ++i)
	{
		input[i]='J';
	}
	for(len=i+i7;i < len; ++i)
	{
		input[i]='7';
	}
	strcpy(input+i,otherChar);
}
int main()
{
	while(gets(input) != NULL)
	{
		sort();
		puts(input);
	}
	return 0;
}
