void B(string s)
{
	
	ptr = strtok ((char*)s.c_str()," ");
			
	i=0;
	while (ptr != NULL)
	{ 
	args[i]=ptr;
	ptr= strtok (NULL, " ");
	i++;
	}
	i--;
	args[i]=NULL;
		
	pid=fork();
	
	if(pid==0)
	{
		cout<<"\r                                                                                                  \r";										
		cout<<string(args[0])<<"\t"<<getpid()<<endl;		
		
		setpgid(getpid(),1);
		if(execvp(args[0],args)==-1)
		{
			perror("exec");
		}
	}
	else
	{
		//
	}
}
