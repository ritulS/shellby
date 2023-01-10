#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        

    }

}
