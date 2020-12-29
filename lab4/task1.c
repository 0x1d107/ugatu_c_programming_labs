#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swapper(char* buf,char*new_buf,size_t buf_len,char* a,size_t a_len,char* b,size_t b_len){
    
    for(int i=0;i<a-buf;i++)
        *(new_buf++) = buf[i];
    for(int i=0;i<b_len;i++)
        *(new_buf++) = b[i];
    if(a==b)
        return;

    for(int i=a_len;i<b-(a);i++)
        *(new_buf++) = a[i];
    for(int i=0;i<a_len;i++)
        *(new_buf++) = a[i];
    

}
int main(){
    char* line = NULL;
    while(1){
        size_t line_buf_size;
        ssize_t line_size = getline(&line,&line_buf_size,stdin);
        char* fwstart = line;
        char* fwend = strchr(line,' ');
        if(!fwend)
            fwend = fwstart+line_size-1;
        char* lwend= line + line_size-1;
        char* lwstart ;
        lwstart = strrchr(line,' ');
        if(!lwstart)
            lwstart = fwstart;
        else
            lwstart++;

        if(!strncmp(lwstart,"quit",4)){
            free(line);
        
            break;
        
        }
        if(lwstart==lwend){
            printf("%s",line);
            continue;
        }
        char* swapped = calloc(line_buf_size,sizeof(char));
        swapper(line,swapped,line_buf_size,fwstart,fwend-fwstart,lwstart,lwend-lwstart);
        printf("%s\r\n",swapped);
        free(line);
        line = NULL;
        free(swapped);
        swapped = NULL;
    }
    return 0;
}