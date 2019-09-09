void P(string s,int k,string t){
	
	ptr = strtok ((char*)s.c_str(),"|");

	j=0;
	while (ptr != NULL)
	{ 
	pp[j]=ptr;
	ptr= strtok (NULL, "|");
	j++;
	}

	//j=0
	s=string(pp[0]);

	ptr = strtok ((char*)s.c_str()," ");

	i=0;
	while (ptr != NULL)
	{ 
		args[i]=ptr;
		ptr= strtok (NULL, " ");
		i++;
	}
	args[i]=NULL;

	pid=fork();

	if(pid==0)
	{
		
		fd =open ("pp.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);
		close(1);
		dup(fd);
		close(fd);					
		if(execvp(args[0],args)==-1)
		{
			perror("exec");
		}
	}
	else
	{
		wait(0);
	}
					
	//j=k-1;
	for(j=1;j<k;j++)
	{
		s=string(pp[j]);

		ptr = strtok ((char*)s.c_str()," ");

		i=0;
		while (ptr != NULL)
		{ 
			args[i]=ptr;
			ptr= strtok (NULL, " ");
			i++;
		}
		//					
		int in = open("pp.txt", O_RDONLY );
			if(in<0)
			{
				perror("Unable to open data");
				exit (1);
			}
																	
		int out = open("pp2.txt", O_CREAT | O_TRUNC | O_RDWR, 0666 );
		if(out==-1)
		{
		
			perror("Unable to write data");
			exit (1);
		}
		
		for ( ;; )
		{
			ssize_t bytesRead = read( in, buffer, sizeof( buffer ) );
			if ( bytesRead <= 0 )
				{
					break;
				}
			write( out, buffer, bytesRead );
		}
		close(in);
		close(out);		
		//	
		args[i]=(char*)"pp2.txt";
		i++;
		args[i]=NULL;
		
		pid=fork();
		
		if(pid==0)
		{
			
			fd =open ("pp.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);
			close(1);
			dup(fd);
			close(fd);					
			if(execvp(args[0],args)==-1)
			{
				perror("exec");
			}
		}
		else
		{
			wait(0);
		}
	}

	//j=k
	s=string(pp[k]);

		ptr = strtok ((char*)s.c_str()," ");

		i=0;
		while (ptr != NULL)
		{ 
		args[i]=ptr;
		ptr= strtok (NULL, " ");
		 i++;
		}
		args[i]=(char*)"pp.txt";
		i++;
		args[i]=NULL;
	
	
		if(t=="")
		{
			pid=fork();
			
			if(pid==0)
			{									
				if(execvp(args[0],args)==-1)
				{
					perror("exec");
				}
			}
			else
			{
				wait(0);
			}
		}
		else
		{
			pid=fork();

			if(pid==0)
			{
				pp[1]=&t[0];
				fd =open (pp[1],O_WRONLY | O_CREAT | O_TRUNC, 0644);
				close(1);
				dup(fd);
				close(fd);	

				
				if(execvp(args[0],args)==-1)
				{
					perror("exec");
				}
			}
			else
			{
				wait(0);
			}
		}
}

