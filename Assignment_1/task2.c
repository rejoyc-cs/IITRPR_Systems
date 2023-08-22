#include <stdio.h>
#include <stdlib.h>

int main(){
	
	/*
	system("touch log.txt");
	system("truncate -s 0 log.txt");
	
	system("echo -n \"Total normal files \" >> log.txt");
	system("find . -mindepth 1 -type f ! -name \"readme.txt\" | wc -l >> log.txt");
	
	system("echo -n \"Total Folders \" >> log.txt");
	system("find . -mindepth 1 -type d | wc -l >> log.txt");
	
	system("echo -n \"Maximum levels \" >> log.txt");
	system("find . -type d ! -empty -printf '%d\n' | sort -rn | head -1 >> log.txt");
	
	
	system("echo -n \"Total normal files \" ");
	system("find . -mindepth 1 -type f ! -name \"readme.txt\" | wc -l");
	
	system("echo -n \"Total Folders \" ");
	system("find . -mindepth 1 -type d | wc -l");
	
	system("echo -n \"Maximum levels \" ");
	system("find . -type d ! -empty -printf '%d\n' | sort -rn | head -1");
	* */
	
	system("touch log.txt");
	system("truncate -s 0 log.txt");
	
	system("echo -n \"Total normal files \" >> log.txt");
	system("find . -mindepth 1 -type f | wc -l >> log.txt");
	
	system("echo -n \"Total Folders \" >> log.txt");
	system("find . -mindepth 1 -type d | wc -l >> log.txt");
	
	system("echo -n \"Maximum levels \" >> log.txt");
	system("find . -type d ! -empty -printf '%d\n' | sort -rn | head -1 >> log.txt");
	
	
	system("echo -n \"Total normal files \" ");
	system("find . -mindepth 1 -type f | wc -l");
	
	system("echo -n \"Total Folders \" ");
	system("find . -mindepth 1 -type d | wc -l");
	
	system("echo -n \"Maximum levels \" ");
	system("find . -type d ! -empty -printf '%d\n' | sort -rn | head -1");
	
	
	return 0;
}
