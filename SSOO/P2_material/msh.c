/*-
 * msh.c
 *
 * Minishell C source
 * Show how to use "obtain_order" input interface function
 *
 * THIS FILE IS TO BE MODIFIED
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <linux/kernel.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/time.h>

extern int obtain_order();		/* See parser.y for description */

int main(void) {
	char ***argvv;
	int command_counter;
	int num_commands;
	int args_counter;
	char *filev[3];
	int ret;
    int bg;
    
    int pid;
    char *getcwd(char *buf, size_t size);
    
	setbuf(stdout, NULL);			/* Unbuffered */
	setbuf(stdin, NULL);

	while (1) {
		fprintf(stderr, "%s", "msh> ");	/* Prompt */
		ret = obtain_order(&argvv, filev, &bg);
		if (ret == 0) break;		/* EOF */
		if (ret == -1) continue;	/* Syntax error */
		num_commands = ret - 1;		/* Line */
		if (num_commands == 0) continue;	/* Empty line */

        /*
         * SPECIAL COMMANDS
         */

        //MYTIME
        if (strncmp("mytime", argvv[0][0], 6) == 0){
            struct timeval ti, tf;
            long elapsed;
            gettimeofday(&ti, 0);
                        
            pid = fork();
            if (pid == 0) {
                
                //If there is an entry we close the current one and redirect to the new one
                if (filev[0] != NULL) {
                    close(0);
                    open(filev[0], O_RDONLY);
                }
                
                //The same but printing on screen
                if (filev[1] != NULL) {
                    close(1);
                    open(filev[1], O_CREAT|O_TRUNC|O_RDONLY);
                }
                
                //The same but with the erros.
                if (filev[2] != NULL) {
                    close(2);
                    open(filev[2], O_CREAT|O_TRUNC|O_RDONLY);
                }

                //Print child PID
                printf("Hijo: %i\n\n", pid);
                //Do the exec
                execvp(argvv[1][0], argvv[1]);
            }

            //Parent code, so wait for the child to finish
            //if its the only one in the order
            if (!bg) {
                printf("\nEsperando al hijo: %i\n", pid);
                waitpid(pid, NULL, 0);
            }
            else if (bg) bg = 0;

            else printf("[%i]\n", pid);
            
            gettimeofday(&tf, 0);
            elapsed = (tf.tv_sec-ti.tv_sec)*1000000 + tf.tv_usec-ti.tv_usec;
            printf("%f\n", elapsed);
            
        } else if (strncmp("mypwd", argvv[0][0], 5) == 0){
            
            char cwd[PATH_MAX];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("Current dir: %s\n", cwd);
            } else {
                perror("​Mypwd error​");
            }
            
        /*
         *  NORMAL COMMANDS
         */	
        /*} else if(num_commands > 1){
            //Go command by command
            for(int i=0; i<num_commands; i++){
                //Create a pipe
                int strcat("pipe", i)[2];
                pipe(pipe);

                //Create each son
                pid=fork();
                
                //CHILD
                if(pid==0){
                    dup2(pipe[0], filev[0]);//Redirect the pipe to the standard output
                    dup2(pipe[1], filev[1]);
                    close(pipe[0]);//Close the pipe
                    close(pipe[1]);
                }

                //FATHER
                else{

                    //If there is an entry we close the current one and redirect to the new one
					if (filev[0] != NULL) {
						close(0);
						open(filev[0], O_RDONLY);
					}

					//The same but printing on screen
					if (filev[1] != NULL) {
						close(1);
						open(filev[1], O_CREAT|O_TRUNC|O_RDONLY);
					}

					//The same but with the erros.
					if (filev[2] != NULL) {
						close(2);
						open(filev[2], O_CREAT|O_TRUNC|O_RDONLY);
					}

					//Exec
					execvp(argvv[i][0], argvv[i]);

                    //Close the pipe
                    close(pipe);
                    //Wait for the child to die
                    waitpid(pid, NULL, 0);
                }
            }*/
        } else if (num_commands == 1) {
            //Do the fork
            pid = fork();
            if (pid == 0) {

                //If there is an entry we close the current one and redirect to the new one
                if (filev[0] != NULL) {
                    close(0);
                    open(filev[0], O_RDONLY);
                }

                //The same but printing on screen
                if (filev[1] != NULL) {
                    close(1);
                    open(filev[1], O_CREAT|O_TRUNC|O_RDONLY);
                }

                //The same but with the errors.
                if (filev[2] != NULL) {
                    close(2);
                    open(filev[2], O_CREAT|O_TRUNC|O_RDONLY);
                }

                //Print child's PID
                printf("Hijo: %i\n\n", pid);
                //Do the exec
                execvp(argvv[0][0], argvv[0]);
            }

            if (!bg) {
                printf("\nEsperando al hijo: %i\n", pid);
                waitpid(pid, NULL, 0);
            }
            else if (bg) bg = 0;

            else printf("[%i]\n", pid);
        }

    } //fin while 

	return 0;

} //end main

