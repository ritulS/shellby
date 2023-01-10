#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prompt.c"

int main(int argc, char** argv){
    char *cmd;

    do{
        print_prompt1();
        cmd = read_cmd();
        
        // if no cmd
        if(!cmd){
            exit(EXIT_SUCCESS);
        }// if cmd argc is none
        if(cmd[0] == '\0' || strcmp(cmd,"\n") == 0){
            free(cmd);
            continue;
        }// if cmd is exit
        if(cmd == "exit\n"){
            free(cmd);
            break;

        }
        printf("%s\n", cmd);
    } while(1);
    exit(EXIT_SUCCESS);

}



char *read_cmd(void){
    char buf[1024];
    char *ptr;
    int ptrlen;

    while(fgets(buf,1024,stdin))
    {   
        int buflen = strlen(buf);

        if(!ptr)
        {
            ptr = malloc(buflen+1);
        }
        else
        {   
            char *ptr2 = realloc(ptr,ptrlen+buflen+1);

            if (ptr2)
            {
                ptr = ptr2;
            }
            else
            {
                free(ptr);
                ptr = NULL;
            }

        }
        strcpy(ptr+ptrlen, buf);

        if(buf[buflen-1] == '\n') // When enter is pressed
        {
            if(buflen ==1 || buf[buflen-2] != '\\') // check if enter is pressed after backslash
            {
                return ptr;
            }

            ptr[ptrlen + buflen-2] = '\0';
            buflen -= 2; // removing the backslash and newline character
            print_prompt2();
        }

    return ptr;
}
