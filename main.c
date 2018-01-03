#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>

static void do_ls(char *path);

int main(int argc, char* argv[]){
	if (argc < 2){
		fprintf(stderr, "useage:\n");
		exit(1);
	}
	int i;
	for (i=1; i< argc; i++){
		do_ls(argv[i]);
	}
}

static void do_ls(char *path){
	DIR *d;
	struct dirent *ent;
	d = opendir(path);
	if(!d){
		perror(path);
		exit(1);
	}
	while(ent = readdir(d)){
		printf("%s\n", ent->d_name);
	}
	closedir(d);
}
