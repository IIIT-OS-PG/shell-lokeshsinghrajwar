void R(string s,int c1,int c2)
{
	if(c1)
	{
		ptr = strtok ((char*)s.c_str(),">>");

		j=0;
		while (ptr != NULL)
		{ 
			pp[j]=ptr;
			ptr= strtok (NULL, ">>");
			j++;
		}

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
			string t=string(pp[1]);
			stringstream ss(t);
			ss>>t;
			pp[1]=&t[0];
			
			fd =open (pp[1],O_WRONLY | O_CREAT | O_APPEND, 0644);
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
	else
	{
		ptr = strtok ((char*)s.c_str(),">");

		j=0;
		while (ptr != NULL)
		{ 
			pp[j]=ptr;
			ptr= strtok (NULL, ">");
			j++;
		}
		
		s=string(pp[0]);

		string z=s;

		ptr = strtok ((char*)s.c_str()," ");

		i=0;
		while (ptr != NULL)
		{ 
			args[i]=ptr;
			ptr= strtok (NULL, " ");
			i++;
		}
		args[i]=NULL;
		
		s=z;
		length=s.length();k=0;
		for(i=0;i<length;i++)
		{
			if(s[i]=='|')
			k++;
		}
		if(k>0)
		{
			string t=string(pp[1]);
			stringstream ss(t);
			ss>>t;
			P(s,k,t);		
		}
		
		else
		{
			pid=fork();

			if(pid==0)
			{
				string t=string(pp[1]);
				stringstream ss(t);
				ss>>t;
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
}

