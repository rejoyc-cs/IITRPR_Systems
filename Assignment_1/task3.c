#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	if(strcmp(argv[1],"-h")==0){
		printf("\nHELP:\n\n");
		printf("This program shows the Total number of files, folders, and maximum depth of a folder specified in argument.\n\n");
		printf("To pass directory execute the program as follows:\n./task3 -d folder_name\n\n");
	}
	else{
		if(strcmp(argv[1],"-d")==0){
			
			system("touch log2.txt");
			system("truncate -s 0 log2.txt");
			
			char command[3][1000];
			
			system("echo -n \"Total normal files \" >> log2.txt");
			sprintf(command[0], "find %s -mindepth 1 -type f ! -name \"readme.txt\" | wc -l >> log2.txt", argv[2]);
			system(command[0]);
			
			system("echo -n \"Total Folders \" >> log2.txt");
			sprintf(command[1],"find %s -mindepth 1 -type d ! -name %s | wc -l >> log2.txt",argv[2],argv[2]);
			system(command[1]);
			
			
			system("echo -n \"Maximum levels \" >> log2.txt");
			sprintf(command[2],"find %s -type d ! -empty | awk -F/ '{print NF-1}' | sort -rn | head -1 >> log2.txt",argv[2]);
			system(command[2]);

			char command2[3][1000];
			
			system("echo -n \"Total normal files \" ");
			sprintf(command2[0], "find %s -mindepth 1 -type f ! -name \"readme.txt\" | wc -l", argv[2]);
			system(command2[0]);
			
			system("echo -n \"Total Folders \" ");
			sprintf(command2[1],"find %s -mindepth 1 -type d | wc -l ",argv[2]);
			system(command2[1]);
			
			
			system("echo -n \"Maximum levels \" ");
			sprintf(command2[2],"find %s -type d ! -empty | awk -F/ '{print NF-1}' | sort -rn | head -1",argv[2]);
			system(command2[2]);
		}
	}
	return 0;
}
