void E(char* args[50])
{	
	if(string(args[1])=="~")
	{
		cout<<me["HOME"]<<endl;
		return;
    }
	if((i>1&&strcmp(args[1],"-e")==0)|| (i>2&&strcmp(args[2],"-e")==0))
	{
		j=i-1;
		string t(args[j]);
		int l=t.length();
		if(t[0]=='"'&&t[l-1]=='"')
			{
				for(k=1;k<l-1;k++){
					if(int(t[k])==92&&k<l-2){
						if(t[k+1]=='n')
							cout<<"\n";
						else if(t[k+1]=='t')
							cout<<"\t";
						else if(t[k+1]=='b')
							cout<<"\b";
						else
							cout<<t[k]<<t[k+1];
						k++;
					}
					else if(t[k]=='$')
					{
						if(k+1<l-1&&t[k+1]=='$'){
							cout<<getpid();
							k++;
						}
						else if(k+1<l-1&&t[k+1]=='?'){
							cout<<WEXITSTATUS(j);
							k++;
						}
						else if(k+1<l-1&&t[k+1]==' '||k==l-2){
							cout<<"$";													
						}
						else
						{
							k++;
							string w="";
							while(k<l-1&&t[k]!=' ')
							{
								w+=string(1,t[k]);
								k++;
							}
							w+="\0";
							if(me.find(w)!=me.end())
								cout<<me.find(w)->second;																												
						}
						
					}
					else
						cout<<t[k];
				}
				
			}
		else if(((int)t[0])==39&&((int)t[l-1])==39)
			{											
				for(k=1;k<l-1;k++)
				{
					if(int(t[k])!=92)
						cout<<t[k];
					else if(k<l-2)
					{
						if(t[k+1]=='n')
							cout<<"\n";
						else if(t[k+1]=='t')
							cout<<"\t";
						else if(t[k+1]=='b')
							cout<<"\b";
						else
							cout<<t[k]<<t[k+1];
						k++;
					}
				}
			}
		else
		{
			for(k=0;k<l;k++){
					if(int(t[k])==92){
						continue;
					}
					else if(t[k]=='$')
					{
						if(k+1<l&&t[k+1]=='$'){
							cout<<getpid();
							k++;
						}
						else if(k+1<l&&t[k+1]=='?'){
							cout<<WEXITSTATUS(j);
							k++;
						}
						else if(k+1<l&&t[k+1]==' '||k==l-1){
							cout<<"$";													
						}
						else
						{
							k++;
							string w="";
							while(k<l&&t[k]!=' ')
							{
								w+=string(1,t[k]);
								k++;
							}
							w+="\0";
							if(me.find(w)!=me.end())
								cout<<me.find(w)->second;																												
						}
						
					}
					else
						cout<<t[k];
				}
		}
			
	}
	else
	{
	j=i-1;
	string t(args[j]);
	int l=t.length();
	if(t[0]=='"'&&t[l-1]=='"')
		{
			for(k=1;k<l-1;k++){
				
				 if(t[k]=='$')
				{
					if(k+1<l-1&&t[k+1]=='$'){
						cout<<getpid();
						k++;
					}
					else if(k+1<l-1&&t[k+1]=='?'){
						cout<<WEXITSTATUS(j);
						k++;
					}
					else if(k+1<l-1&&t[k+1]==' '||k==l-2){
						cout<<"$";													
					}
					else
					{
						k++;
						string w="";
						while(k<l-1&&t[k]!=' ')
						{
							w+=string(1,t[k]);
							k++;
						}
						w+="\0";
						if(me.find(w)!=me.end())
							cout<<me.find(w)->second;																												
					}
					
				}
				else
					cout<<t[k];
			}
			
		}
	else if(((int)t[0])==39&&((int)t[l-1])==39)
		{											
			for(k=1;k<l-1;k++)
				{
					if(int(t[k])!=92)
						cout<<t[k];
					else if(k<l-2)
					{
						if(t[k+1]=='n')
							cout<<"\n";
						else if(t[k+1]=='t')
							cout<<"\t";
						else if(t[k+1]=='b')
							cout<<"\b";
						else
							cout<<t[k]<<t[k+1];
						k++;
					}
				}
		}
	else
		{
			for(k=0;k<l;k++){
					if(int(t[k])==92){
						continue;
					}
					else if(t[k]=='$')
					{
						if(k+1<l&&t[k+1]=='$'){
							cout<<getpid();
							k++;
						}
						else if(k+1<l&&t[k+1]=='?'){
							cout<<WEXITSTATUS(j);
							k++;
						}
						else if(k+1<l&&t[k+1]==' '||k==l-1){
							cout<<"$";													
						}
						else
						{
							k++;
							string w="";
							while(k<l&&t[k]!=' ')
							{
								w+=string(1,t[k]);
								k++;
							}
							w+="\0";
							if(me.find(w)!=me.end())
								cout<<me.find(w)->second;																												
						}
						
					}
					else
						cout<<t[k];
				}
		}
		
	}


	if(((i>1&&strcmp(args[1],"-n"))==0)||(i>2&&(args[2],"-n")==0)){}
	else
	cout<<endl;
}
