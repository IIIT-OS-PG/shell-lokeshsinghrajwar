string getInput(vector<string> History,string PS1)
{
	tcgetattr(STDIN_FILENO, &orig_termios);
	struct termios termios_p = orig_termios;
	termios_p.c_lflag &= ~( ECHO | ICANON );
	tcsetattr( STDIN_FILENO, TCSAFLUSH, &termios_p);
	
	string command="";
	
	char c;
	string s="";
	int x=PS1.length(),y=x;
	char ch[3]={1,0,0};
	long count=0, k=History.size();
	while(ch[0]!='\n')
	{
		ch[0]=getchar();
		if(ch[0] == 3)
		{
			command="";
			break;
		}
		else if( ch[0] == 0x7f)
		{
			if(y>x)
			{
				cout<<"\b \b";
				command = command.substr(0, command.size()-1 );
				y--;
			}
		}
		else if(ch[0]==27)
		{
			ch[1]=getchar();
			ch[2]=getchar();
			if(ch[2]=='A')
			{
				cout<<"\r                                                                                                                   \r";
				k--;
				cout<<PS1;
				if(k>=0)
				{
					y=x+History[k].length();
					cout<<History[k];
					command = History[k];
				}
			}
			else if(ch[2]=='B')
			{
				cout<<"\r                                                                                                                   \r";
				k++;
				cout<<PS1;
				if(k<History.size())
				{
					y=x+History[k].length();
					cout<<History[k];
					command = History[k];
				}
			}
			
		}
		else
		{
			y++;
			cout<<ch[0];
			command+=ch[0];
			
		}
	}
	command = command.substr(0, command.size()-1 );
	
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
	return command;
}

