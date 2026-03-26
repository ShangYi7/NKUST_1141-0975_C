#include <stdio.h>

int main() {
    int cont[5];
    int a=0,b=0,c=0,s=0;
    for(int i=0;i<5;i++){
        scanf("%d",&cont[i]);
        if(cont[i]==100){
            s++;
        }
        else if(cont[i]>=80){
            a++;
        }
        else if(cont[i]>=60){
            b++;
        }
        else{
            c++;
        }
    }
    printf("S=%d\n",s);
    printf("A=%d\n",a);
    printf("B=%d\n",b);
    printf("C=%d\n",c);
    printf("AVG=%d\n",(cont[0]+cont[1]+cont[2]+cont[3]+cont[4])/5);
    return 0;
}