#include<bits/stdc++.h>
#include<unistd.h>
#include<stdio.h> 
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include <fcntl.h>
#include <cstdlib>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <termios.h>
#include <ctype.h>
#define BUFSIZE 100000
using namespace std;

pid_t pid;
char* args[50], *ptr;
char* pp[100];
int i,fd,length,k,j,c1,c2;
string s;
vector <string> History;
char buffer [ BUFSIZE];

map<string,int> ms;

map<string, string> me;

map<string,string> ma;

struct termios orig_termios;

#include "myPipe.cpp"
#include "myAlias.cpp"
#include "myInput.cpp"
#include "myRedirection.cpp"
#include "myBack.cpp"
#include "myEcho.cpp"
#include "myPrompt.cpp"


//ALARM Catcher
void catcher(int signum) {
  cout<<"\r                                                                                                                                 \r";
  cout<<"ALARM ALERT";
}

//MAIN

int main()
{
	signal(SIGALRM, catcher);
	char prc[100];
	getcwd(prc, 100); 
	string sprc(prc);
	
	sprc+="/myshellrc.txt";
	
	ms["alias"]=1;
	ms["export"]=2;
	ms["cd"]=3;
	ms["echo"]=4;
	ms["fg"]=5;
	ms["type"]=6;
	ms["unalias"]=7;
	ms["alarm"]=8;
	ms["open"]=9;
	
	me["PATH"]="";
	me["HOME"]="";	
	me["USER"]="";
	
	for(auto it=me.begin();it!=me.end();it++)
	{
		string s=(string)(it)->first;
		const char* c=&s[0];
		string v=getenv(c);
		(it)->second+=v;
	}
	me["PS1"]="";	
	me["HOSTNAME"]="";
	
	chdir(&me["HOME"][0]);
	
	
	pid=fork();
	if(pid==0)
	{
		
		fd =open (&sprc[0],O_WRONLY | O_CREAT | O_TRUNC, 0644);
		close(1);
		dup(fd);
		close(fd);
		args[0]=(char*)("hostname");
		args[1]=NULL;
		if(execvp(args[0],args)==-1)
		{
			perror("exec");
		}
	}
	else
	{
		wait(0);		
						
		while(1){
						
			PS(&sprc[0]);
			
			cout<<me["PS1"];
			
			s=getInput(History,me["PS1"]);
			if(s!="")
			History.push_back(s);
			//cout<<endl<<s<<endl;
			
			if(s=="logout")
				exit(0);
			
			if(s=="")
				continue;
			
			
			//&
			length=s.length();
			if(s[length-1]=='&')
			{												
				B(s);			
				continue;
			}
			
			
			//>>>
			
			length=s.length();c1=0,c2=0;
			for(i=0;i<length;i++)
			{
				if(s[i]=='>'&&i+1<length&&s[i+1]=='>')
				{
					c1=1;
					break;
				}
				if(s[i]=='>')
				{
					c2=1;
					break;
				}

			}

			if(c1||c2)
			{
				R(s,c1,c2);
				continue;
			}
														
			
			//Pipe
			
			length=s.length();k=0;
			for(i=0;i<length;i++)
			{
				if(s[i]=='|')
				k++;
			}
			if(k>0)
			{
				P(s,k,"");
				continue;
			}
			
			
			//
			ptr = strtok ((char*)s.c_str()," ");
			
			i=0;
			while (ptr != NULL)
			{ 
			args[i]=ptr;
			ptr= strtok (NULL, " ");
			 i++;
			}
			args[i]=NULL;
				
			//
			
			
			if(ma.find(args[0])!=ma.end()){
				string x=(ma.find(args[0]))->second;
				
				for(int j=1;j<i;j++)
				{
					x+=" ";
					string t(args[j]);
					x+=t;
				}
				
				x+="\0";
				stringstream ss(x);
				string result[50]; 
				i=0;
				while(ss>>result[i]){
					args[i]=&(result[i][0]);
					i++;
				}	
				args[i]=NULL;
			}
					
			
			if(ms.find(args[0])!=ms.end())
			{
				int x=(ms.find(args[0]))->second;
				
				switch(x){
					case 1:{
								char* c=args[1];
								A(c);
								continue;
								break;
						   }
					case 2:{											
								continue;
								break;
							}	   
					case 3:{						
								chdir(args[1]); 							
								continue;
								break;
							}
					case 4:{
								E(args);
								continue;
								break;							
							}
					case 5:{
								string t=string(args[1]);					
								setpgid(stoi(t),getpid());
								waitpid(stoi(t),0,0);	
								cout<<"DONE\n";
								continue;

							}
					case 6:{
								pid=fork();
								
								string s="which";
								args[0]=&s[0];
								if(pid==0)
								{
									
									if(execvp(args[0],args)==-1)
									{
										perror("exec");
									}
								}
								if(pid>0)
								{
									wait(0);
									
								}														
								continue;
								break;
							}
					case 7:{
								ma.erase(string(args[1]));
								continue;
								break;
							}				
					case 8:{								
								alarm(stoi(string(args[1])));								
								continue;
								break;
							}
					case 9:{
								string t="xdg-open";
								args[0]=&t[0];	
								pid=fork();
								if(pid==0)
								{
									
									if(execvp(args[0],args)==-1)
									{
										perror("exec");
									}
								}
								if(pid>0)
								{
									wait(0);
									
								}														
								continue;
								break;
						   }
					
				}
			}
			
			//
			pid=fork();
			
			if(pid==0)
			{
				
				if(execvp(args[0],args)==-1)
				{
					perror("exec");
				}
			}
			if(pid>0)
			{
				wait(0);
				
			}
		
		}
	}
	
	return 0;
}
//	
