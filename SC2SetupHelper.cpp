/*
	Starcraft 2 UI Setup Helper
	Written by sellsword
*/

#include <cstdio>
#include <string>
#include <windows.h>
#include <Lmcons.h>

//option names
const int WOL = 1;
const int HOTS = 2;
const std::string get("get");
const std::string put("put");
const std::string wol("wol");
const std::string hots("hots");

//function definitions
void getDirectory(std::string& dir, int v){
	char username[100];
	DWORD n = sizeof(username);
	GetUserName(username,&n);
	dir.assign("C:\\Users\\");
	dir.append(username);
	if(v == HOTS) dir.append("\\Documents\\StarCraft II Beta");
	if(v == WOL) dir.append("\\Documents\\StarCraft II");
}

void getInfo(std::string& dir){
	dir.append("\\Variables.txt");
	FILE *src = fopen(dir.c_str(),"r");
	FILE *dest = fopen("Variables.txt","w");
	int c;
	c = getc(src);
	while(c != EOF){
		putc(c,dest);
		c = getc(src);
	}
	fclose(src);
	fclose(dest);
}

void getInfo(std::string& dir, const std::string& name){
	dir.append("\\Variables.txt");
	FILE *src = fopen(dir.c_str(),"r");
	FILE *dest = fopen(name.c_str(),"w");
	int c;
	c = getc(src);
	while(c != EOF){
		putc(c,dest);
		c = getc(src);
	}
	fclose(src);
	fclose(dest);
}

void putInfo(std::string& dir){
	dir.append("\\Variables.txt");
	FILE *dest = fopen(dir.c_str(),"w");
	FILE *src = fopen("Variables.txt","r");
	int c;
	c = getc(src);
	while(c != EOF){
		putc(c,dest);
		c = getc(src);
	}
	fclose(src);
	fclose(dest);
}

void putInfo(std::string& dir, const std::string& name){
	dir.append("\\Variables.txt");
	FILE *dest = fopen(dir.c_str(),"w");
	FILE *src = fopen(name.c_str(),"r");
	int c;
	c = getc(src);
	while(c != EOF){
		putc(c,dest);
		c = getc(src);
	}
	fclose(src);
	fclose(dest);
}

int
main(int argc, char* argv[]){
	if(argc < 3){
		fprintf(stdout,"Usage: sc2helper.exe version action [name]\n");
		fprintf(stdout,"See readme.txt for additional information\n");
		return 0;
	}
	const std::string vname(argv[1]);
	const std::string action(argv[2]);
	std::string dir;
	if(vname.compare(wol) == 0) getDirectory(dir,WOL);
	else if(vname.compare(hots) == 0) getDirectory(dir,HOTS);
	else{
		fprintf(stdout,"Invalid Version\n");
		return 0;
	}
	
	if(argc == 3){
		if(action.compare(get) == 0){
			getInfo(dir);
			fprintf(stdout,"Variables.txt copied into local directory\n");
			fprintf(stdout,"Exiting\n");
			return 0;
		}
		if(action.compare(put) == 0){
			fprintf(stdout,"Copying local Variables.txt into default SC2 directory\n");
			putInfo(dir);
			fprintf(stdout,"Variables.txt copied into default directory\n");
			fprintf(stdout,"Exiting\n");
			return 0;
		}
		fprintf(stdout,"arg is invalid, exiting\n");
		return 0;
	}
	if(argc == 4){
		const std::string target((std::string(argv[3])).append(".txt"));
		if(action.compare(get) == 0){
			fprintf(stdout,"Copying current Variables.txt into local directory as %s\n",target.c_str());
			getInfo(dir, target);
			fprintf(stdout,"Copied Variables.txt into local directory as %s\n",target.c_str());
			fprintf(stdout,"Exiting\n");
			return 0;
		}
		if(action.compare(put) == 0){
			fprintf(stdout,"Copying %s as Variables.txt into default SC2 directory\n",target.c_str());
			putInfo(dir, target);
			fprintf(stdout,"Copied %s as Variables.txt into default SC2 directory\n",target.c_str());
			fprintf(stdout,"Exiting\n");
			return 0;
		}
		fprintf(stdout,"arg is invalid, exiting\n");
		return 0;
	}
	return 0;
}	