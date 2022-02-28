#include<stdio.h>

int main(){
unsigned long int ma[100],x[100];
printf("a*x=1 (mod m)\nenter m:");
scanf("%lu",&(ma[0]));
printf("enter a:");
scanf("%lu",&(ma[1]));
int i;
for(i=0; ma[i+1]>0; i++){
	ma[2+i]=ma[i]%ma[1+i];
}
printf("%d\n",i);
for(x[i]=(i%2==0?1:0),--i;i>=0;i--){
	x[i]=(x[i+1]*ma[i]+(i%2==0?1:-1))/ma[i+1];
}
printf("%ld",x[0]);
return 1;
}
