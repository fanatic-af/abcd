#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char w1[20],w2[20];
    int n;

    printf("Give word to be replace : ");
    scanf("%s", w1);
    printf("Give the word that will replace : ");
    scanf("%s", w2);
    printf("Give number of times the replacement to be done = ");
    scanf("%d", &n);

    int l = strlen(w1);
    FILE *ptr;
    char h[5000];
    ptr = fopen("FILE.txt", "r");
    int  k = 0;

    char c = fgetc(ptr);
    
    while(c!=EOF){
        h[k] = c;
        ++k;
        c = fgetc(ptr);
    }

    fclose(ptr);

    ptr = fopen("FILE.txt","w");

    int x = 0;

    for(int i = 0; i<k; i++){
        if(n<0 || x<n){
        for(int j = 0; j<l;j++){
            if(h[i+j]==w1[j]){continue;}
            else{goto next;}
        }
        fprintf(ptr,"%s",w2);
        i+=l;
        x++;}
        next:
        fputc(h[i],ptr);
    }
    
    (x!=n && n>=0) ? printf("Replacement done %d times", x) : printf("");

    return 0;}
