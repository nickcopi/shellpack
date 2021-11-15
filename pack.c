#define _GNU_SOURCE
#include <unistd.h>
#include <sys/mman.h>
#include "binary.h"

int main(int argc, char *argv[], char *envp[]){
	int temp_fd = memfd_create("multicall",0);
	write(temp_fd,temp_script_sh, temp_script_sh_len);
        lseek(temp_fd,0,SEEK_SET);
	fexecve(temp_fd,argv,envp);

}
