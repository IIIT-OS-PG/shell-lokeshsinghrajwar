void PS(char* c)
{
	me["PS1"]="";
	me["HOSTNAME"]="";
	
	me["PS1"]+=(me["USER"]+"@");
	
	if ( ( fd = open (c, O_RDONLY) ) < 0 ) {
				perror("Unable to open data");
				exit (1);
				}
	length = read (fd, buffer, BUFSIZE);
	for(k=0;k<length;k++)
		if(buffer[k]!='\n')
			{
			string s(1,buffer[k]);
			me["HOSTNAME"]+=s;
			}
	
	me["PS1"]+=me["HOSTNAME"];
	
	if (getcwd(buffer, sizeof(buffer)) == NULL)
		perror("getcwd() error");
	else
		{
			string s(buffer);
			me["PS1"]+=(":"+s+"$ ");
		}
}
