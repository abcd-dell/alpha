#include<stdio.h>

void main(){
int w,i,n,frame[50];
printf("Enter the window size\n");
scanf("%d",&w);
printf("Enter the no of frames\n");
scanf("%d",&n);
printf("Enter the frames: \n");
for(int i=0;i<n;i++){
    scanf("%d",&frame[i]);
}
printf("With the sliding window protocol\n");
printf("After sending %d frames ack is sent by receiver\n ");
for(int i=0;i<n;i++){
    printf("%d\t",frame[i]);
    if((i+1)%w==0||i==n-1){
        printf("ACK is received\n ");
    }
}
return 0;
}
