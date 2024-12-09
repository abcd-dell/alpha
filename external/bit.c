#include<stdio.h>

void main(){
int a[20];
int i=0,j=0,count=0,n=0;
printf("enter the no of frames");
scanf("%d",&n);
printf("Enter the frames");
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for(i=0;i<n;i++){
    printf("%d ",a[i]);
    if(a[i]==1){
        count++;
    }else{
    count=0;
    }
    if(count==5){
        printf("0 ");
    }
}
}
