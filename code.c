#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main(){
    int biggest=0;
    char c;
    char carr[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int iarr[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
    srand(time(NULL));
    for(int i=0;i<1000;i++){
        c=rand()%26+97;
        for(int j=0;j<26;j++){
            if(carr[j]==c){
                iarr[j]++;
            }
        }
    }
    for(int i=0;i<26;i++){
        if(iarr[i]>biggest){
            biggest=iarr[i];
        }
    }
    FILE *fptr;
    fptr= fopen("ownchar.txt","w");
    if(fptr==NULL){
        printf("File cannot open");
    } else{
        for(int i=0;i<biggest;i++){
            for(int j=0;j<=26;j++){
                if(j==26){
                    fprintf(fptr,"%c",'\n');
                } else if(iarr[j]<=0){
                    fprintf(fptr,"%c    ",' ');
                } else{
                    fprintf(fptr,"%c    ",97+j);
                }
                iarr[j]--;
            }
        }
    }
    fclose(fptr);
}
