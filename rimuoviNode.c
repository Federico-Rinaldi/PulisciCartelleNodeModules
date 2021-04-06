/*
 * Elimina tutte le folder node_modules trovate
 * in una determinata path
 *
 * @Author : FR
 * Language : C
 *
 */

#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <ftw.h>
#include <unistd.h>
#include <string.h>


int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
    if (strstr(fpath, "node_modules") != NULL) {
        int rv = remove(fpath);

        if (rv)
            perror(fpath);

        return rv;
    }else{
          return 0;
    }
}

int rmrf(char *path)
{
    return nftw(path, unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
}

int
main(const int argc, char *argv[])
{
        fprintf(stdout, "************************** RIMOZIONE NODE_MODULES BY PATH **********************'\n");
        fprintf(stdout, "________________________________________________________________________________'\n");
        fprintf(stdout, " Utility per la rimozione delle cartelle node_modules nella cartelle impostate  '\n");
        fprintf(stdout, "________________________________________________________________________________'\n");
        fprintf(stdout, "                      By FR - 1_0_0_build1                                      '\n");
        fprintf(stdout, "********************************************************************************'\n");
        if (argc != 2) {
            fprintf(stderr, "Si prega di inserire una path \n");
            return -1;
        }
	   char options;
	   printf("Tutte le cartelle node_modules presenti nella path verranno eliminate, Confermi? [s] or [n] : ");
	   scanf("%c", &options);
	   if(options == 's'){
		    int rimosso =  rmrf(argv[1]);
			   if(rimosso == 0){
				   fprintf(stdout, "Rimossi correttamente i files e le dir del path '%s'\n",argv[1]);
			   }else{
					fprintf(stdout, "Problemi durante la rimozione de files e delle dir del path '%s'\n",argv[1]);
			   }
	   }else{
		   fprintf(stdout, "Allora non faccio nulla! Grazie alla prossima! \n");
	   }
      
        return 0;
}
