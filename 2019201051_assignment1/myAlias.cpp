void A(char* c)
{
	string s="";
	int i=0;
	while(c[i]!='=')
	{
		string t(1,c[i]);
		s+=t;
		i++;
	}
	i++;
	string v="";
	if(c[i]!='"')
	{
		while(c[i]!='\0'){
		string t(1,c[i]);
		v+=t;
		i++;
		}
	}
	else
	{
		i++;
		while(c[i]!='"'){
		string t(1,c[i]);
		if(c[i]=='-')
		v+=" ";
		v+=t;
		i++;
		}								
	}
	
	ma[&s[0]]=v;
}
