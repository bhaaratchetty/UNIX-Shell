//Recursively traverse a directory
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<error.h>

int count=0;
void ListDirectory(const char *DirName, int Level){
	DIR *Dir;
	struct dirent *DirEntry;
	if(!(Dir=opendir(DirName))){
		perror("Directory cant be opened\n");
		exit(0);	
	}

	while((DirEntry=readdir(Dir))!=NULL){
		if(DirEntry->d_type==DT_DIR){
			printf("The Element %s is a directory\n",DirEntry->d_name);
			
			char DirPath[1024];
			if(strcmp(DirEntry->d_name,".")==0 || strcmp(DirEntry->d_name,"..")==0)
				continue;
			
			printf("\tCurrent Level is %d\n",Level);
			snprintf(DirPath, sizeof(DirPath),"%s/%s",DirName,DirEntry->d_name);
			printf("\tCurrent Path is %s\n",DirPath);
			//count++;
			ListDirectory(DirPath,Level+2);
		}
		else if(DirEntry->d_type==DT_REG){
			printf("The Element %s is a regular file\n",DirEntry->d_name);
		count++;
		
		printf("The curent file Count=%d\n",count);
		}
		/*else if(DirEntry->d_type==DT_CHR)
			printf("The Element %s is a character device\n",DirEntry->d_name);
		else if(DirEntry->d_type==DT_FIFO)
			printf("The Element %s is a named pipe(FIFO)\n",DirEntry->d_name);
		else if(DirEntry->d_type==DT_BLK)
			printf("The Element %s is a block device\n",DirEntry->d_name);
		else if(DirEntry->d_type==DT_LNK)
			printf("The Element %s is a symbolic link\n",DirEntry->d_name);
	
		else if(DirEntry->d_type==DT_REG)
			printf("The Element %s is a regular file\n",DirEntry->d_name);
		else if(DirEntry->d_type==DT_SOCK)
			printf("The Element %s is a UNIX Domain Socket\n",DirEntry->d_name);
		else if(DirEntry->d_type==DT_UNKNOWN)
			printf("The Element %s is a unknown device\n",DirEntry->d_name); */
	}
	closedir(Dir);
}
int main(int argc,char *argv[]){
	
	ListDirectory(argv[1],0);
/*
	printf("Value of DT_BLK which is a block device is %d\n",DT_BLK);
	printf("Value of DT_CHR which is a character device is %d\n",DT_CHR);
	printf("Value of DT_DIR which is a directory is %d\n",DT_DIR);
	printf("Value of DT_FIFO which is a named pipe is %d\n",DT_FIFO);
	printf("Value of DT_LNK which is a symbolic link is %d\n",DT_LNK);
	printf("Value of DT_REG which is a regular file is %d\n",DT_REG);
	printf("Value of DT_SOCK which is a UNIX Domain Socket is %d\n",DT_SOCK);
	printf("Value of DT_UNKNOWN whose file type is unknown is %d\n",DT_UNKNOWN);
	printf("\n\n\n\n\n\n\n");
*/
	exit(0);
}

/* 
*	DT_BLK	This is a block device
*	DT_CHR	This is a character deice
*	DT_DIR	This is a directory
*	DT_FIFO	This is a named pipe (FIFO)
*	DT_LNK	This is a symbolic link
*	DT_REG	This is a regular file
*/	
