#include<stdio.h>
#include<string.h>

#define MAX 500
int table[MAX];
void badshifttable(char p[]) {
	int i,j,m;
	m=strlen(p);
	for (i=0;i<MAX;i++)
	  table[i]=m;
	for (j=0;j<m-1;j++)
	  table[p[j]]=m-1-j;
}
int horspool(char src[],char p[]) {
	int i,j,k,m,n;
	n=strlen(src);
	m=strlen(p);
	i=m-1;
	while(i<n) {
		k=0;
		while((k<m)&&(p[m-1-k]==src[i-k]))
		   k++;
		if(k==m)
		   return(i-m+1); else
		   i+=table[src[i]];
	}
	return -1;
}
void main() {
	char text[100],pattern[100];
	int pos;
	
	printf("Enter the text : ");
    gets(text);
	printf("Enter the pattern to be searched: ");
	gets(pattern);
	badshifttable(pattern);
	pos=horspool(text,pattern);
	if(pos>=0)
	  printf("\n The pattern '%s' was found in '%s' starting from position %d\n",pattern,text,pos+1); 
    else
	  printf("\n The pattern was not found in the given text\n");
	
}
