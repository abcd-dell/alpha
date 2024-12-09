#include<stdio.h>

int a[10][10],n;
void main(){
int i,j,root;
printf("Enter the no of nodes\n");
scanf("%d",&n);
printf("Enter the adjacency matrix\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        scanf("%d",&a[i][j]);
    }
}
printf("Enter the root node\n");
scanf("%d",&root);
adj(root);
}
void adj(int k){
int i,j;
printf("adjacent nodes of root %d are",k);
for(j=0;j<n;j++){
    if(a[k][j]==1||a[j][k]==1){
        printf("%d\t",j);

    }
}
printf("\n");
printf("non adjacent nodes of root %d are",k);
for(i=0;i<n;i++){
    if((a[k][i]==0) && (a[i][k]==0)&& (i!=k)){
        printf("%d\t",i);
    }
}
printf("\n");
}
