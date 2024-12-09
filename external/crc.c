#include<stdio.h>
#include<string.h>

int main(){
int i,j,k;
char poly[30],frame[30],trans[30];
printf("Enter the poly");
scanf("%s",poly);
printf("Enter the frame");
scanf("%s",frame);
int m=strlen(poly);
int n=strlen(frame);
for(i=0;i<m+n-1;i++){
    trans[i]=frame[i];
}

for(i=n;i<m+n-1;i++){
    trans[i]='0';
}
trans[i]='\0';
for(i=0;i<n;i++){
    if(trans[i]=='1'){
        for(j=i,k=0;k<m;k++,j++){
            trans[j]=(trans[j]==poly[k])?'0':'1';
        }
    }
}
for(i=0;i<n;i++){
    trans[i]=frame[i];
}
printf("frame+crc %s",trans);
}
