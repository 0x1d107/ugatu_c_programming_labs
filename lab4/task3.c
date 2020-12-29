#include <stdio.h>
#include <string.h>
typedef struct ZNAK{
    int TIME[2];
    int BDAY[3];
    char NAME[2][21];
    char ZODIAC[21];
}ZNAK_t;
int main(){
    ZNAK_t BOOK[8]={0};
    for(int i=0;i<8;i++){
        scanf("%i%i",&BOOK[i].TIME[0],&BOOK[i].TIME[1]);
        scanf("%i%i%i",&BOOK[i].BDAY[0],&BOOK[i].BDAY[1],&BOOK[i].BDAY[2]);
        scanf("%s%s",BOOK[i].NAME[0],BOOK[i].NAME[1]);
        scanf("%s",BOOK[i].ZODIAC);
    }
    char name[20]={0};
    scanf("%s",name);
    char found = 0;
    for(int i=0;i<8;i++){
        if(!strcmp(name,BOOK[i].NAME[0])){
            printf("NAME: %s %s\r\n",BOOK[i].NAME[0],BOOK[i].NAME[1]);
            printf("BDAY TIME: %d.%d.%d %d:%d\r\n",BOOK[i].BDAY[0],BOOK[i].BDAY[1],BOOK[i].BDAY[2],
                BOOK[i].TIME[0],BOOK[i].TIME[1]);
            printf("ZODIAC: %s\r\n", BOOK[i].ZODIAC);
            found = 1;
        }
    }
    if(!found){
        printf("Not found\r\n");
    }
}