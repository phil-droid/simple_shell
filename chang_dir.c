#include "main.h"

void  parseo(char *line, char **argv);

int main(void) {

    char  cad[TAM];             
    char  *argv[TAM]; 
    char  *gdir;
    char  *dir;
    char  *to;
    char buf[TAM];
    pid_t pid;
    int status;

   while (1) {                   

        printf("user@PC: ");    
        fgets(cad, 1000, stdin);

        // if we find a line break (press enter)
        if (cad[strlen(cad) - 1] == '\n')                                                           
            cad[strlen(cad) - 1] = '\0';    // do not mark as end of statement
	

        parseo(cad, argv);


        // Exit para salir del shell
        if (!strcmp(argv[0], "exit")) exit(0);  

        if (!strcmp(argv[0], "cd")){

            gdir = getcwd(buf, sizeof(buf));
            dir = strcat(gdir, "/");
            to = strcat(dir, argv[1]);

            chdir(to);
            //printf("folder access done\n");

        }            

        pid = fork();

        if (pid == 0) {   

            if (execvp(*argv, argv) < 0) {
                printf("%s: order not found \n", argv[0]);
                exit(1);
            }
        }else {  

            waitpid(pid,&status,0);
        }   

    }
    return 0;
}

void  parseo(char *line, char **argv){

    while (*line != '\0') {       
        while (*line == ' ' || *line == '\t' || *line == '\n')

            *line++ = '\0';     
            *argv++ = line; 

        while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n') 
            line++;             
    } 
    *argv = '\0';             // end mark
}
