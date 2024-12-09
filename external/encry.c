#include<stdio.h>
#include<string.h>

void encrypt(char *cipher, char *plain, char *key){
for(int i=0;i<strlen(plain);i++){
    cipher[i]=plain[i]^key[i%strlen(key)];
}
cipher[strlen(plain)]='\0';
}

void decrypt(char *cipher,char *plain,char *key){
for(int i=0;i<strlen(plain);i++){
    cipher[i]=plain[i]^key[i%strlen(key)];
}
cipher[strlen(plain)]='\0';
}

void main(){
char key[11],plain[9],cipher[9],decry[9];
printf("Enter the 10-bit Key\n");
scanf("%10s",key);
printf("Enter the 8-bit text\n");
scanf("%8s",plain);
encrypt(cipher,plain,key);
printf("Encrypted : %s\n",cipher);
decrypt(decry,cipher,key);
printf("Decrypted : %s",decry);

}
