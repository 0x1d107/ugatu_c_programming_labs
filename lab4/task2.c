#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv){
    char* default_input = "input.txt";
    char* input_name=argc >=2?argv[1]:default_input;
    FILE* input = fopen(input_name,"r+");
    size_t line_buf_size=0;
    char* line_buf=NULL;
    ssize_t line_size=0; 
    int lineno = 1;
    int linecount = 1;
    int c;
    int c0 = 0;

    while((c=fgetc(input))!=EOF){
        if(c=='\r'|| (c=='\n'&&c0 !='\r'))
            linecount++;
        c0=c;

        }
    int*space_array = calloc((linecount+1)/2,sizeof(int));
    rewind(input);
    line_size = getline(&line_buf,&line_buf_size,input);
    do{
        int spaces = 0 ;
        if(lineno%2==1){
            for(int i=0;i<line_size;i++)
                if(line_buf[i]==' ')
                    spaces++;
            space_array[lineno/2]=spaces;
        }
        lineno++;
        free(line_buf);
        line_buf=NULL;
        line_size=getline(&line_buf,&line_buf_size,input);
    }while(line_size != -1);
    free(line_buf);
    fseek(input,0L,SEEK_END);
    fprintf(input,"\r\nLine number\tSpace count\r\n");
    for (int i=0;2*i<(linecount);i++)
        fprintf(input,"%i\t\t\t%i\r\n",2*i+1,space_array[i]);
    free(space_array);
    fclose(input);
   
}