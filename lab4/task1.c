#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swapper(char* buf,char*new_buf,size_t buf_len,char* a,size_t a_len,char* b,size_t b_len){
    
    for(int i=0;i<a-buf;i++)
        *(new_buf++) = buf[i];
    for(int i=0;i<b_len;i++)
        *(new_buf++) = b[i];
    for(int i=a_len;i<b-(a);i++)
        *(new_buf++) = a[i];
    for(int i=0;i<a_len;i++)
        *(new_buf++) = a[i];
    for(int i=b_len;i<buf_len-(b - buf);i++)
        *(new_buf++) = b[i];
}
int main(){
    char* line = NULL;
    while(1){
        size_t line_buf_size;
        ssize_t line_size = getline(&line,&line_buf_size,stdin);
        char* fwstart = line;
        while(*fwstart==' '||*fwstart=='\t')
            fwstart++;
        char* fwend = fwstart+1;
        char* lwend= line + line_size-1;
        while(*lwend==' '||*lwend=='\t'||*lwend=='\r'||*lwend=='\n')
            lwend--;
        lwend++;
        char* lwstart =lwend-1;
        
        while(*fwend!=' '&&*fwend!='\0')fwend++;
        while(*lwstart !=' '&&lwstart!=fwstart-1)lwstart--;
        lwstart++;

        if(!strncmp(lwstart,"quit",4))
            break;
        if(lwstart==lwend){
            printf("%s",line);
            continue;
        }
        char* swapped = calloc(line_buf_size,sizeof(char));
        swapper(line,swapped,line_buf_size,fwstart,fwend-fwstart,lwstart,lwend-lwstart);
        printf("%s",swapped);
        free(line);
        line = NULL;
    }
    return 0;
}