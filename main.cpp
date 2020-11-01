#include <bits/stdc++.h>

#ifdef WIN32
	#include <winsock2.h>
	#include <windows.h>
#endif

#include <gl/glut.h>
#include <openssl/md5.h>
#include <curl/curl.h>

using namespace std;

const int maxn = 114514;

char a[maxn];
char tmp[maxn/2];

/*

		else if(!strncmp(a,"",sizeof()))
		{

		}
*/
int main(int argc, char** argv)
{
	void *pvars = NULL;
	int vari=0;
	register int f,def;
	int tmpa=0;
	float tmpb=0;
	char tmpc=0;
	cout<<"Welcome to Node.Jv V 1.0.0.1\n";
	cout<<"Type \".help\" for more information.\n";
	while(1)
	{
		f=0;
		def=0;
		cout<<"> ";
		memset(a,'\0',sizeof(a));
		gets(a);
		if(a[0]=='\0')
		{
			f=1;
		}
		else if(!strncmp(a,"console.log(\"",strlen("console.log(\"")))
		{
			if(a[strlen(a)-1]==';'&&a[strlen(a)-2]==')'&&a[strlen(a)-3]=='\"')
			{
				for(int i=13;i<=strlen(a)-4;i++)
				{
					putchar(a[i]);
				}
				puts("");
				f=1;
			}
		}
		else if(!strncmp(a,"console.clear(",strlen("console.clear(")))
		{
			if(a[strlen(a)-1]==';'&&a[strlen(a)-2]==')')
			{
				#ifdef WIN32
					system("cls");
				#else
					system("clear");
				#endif
				f=1;
			}
		}
		else if(!strncmp(a,".help",strlen(".help")))
		{
			printf("     |\\     |            |               ---------      (C) 2020                                            \n");
			printf("     | \\    |            |                   |                                                             \n");
			printf("     |  \\   |            |  ___              |                                                             \n");
			printf("     |   \\  |   /-\\   /--| /   \\             |   \\    /                                                    \n");
			printf("     |    \\ |  |   | |   | |---              /    \\  /                                                     \n");
			printf("     |     \\|   \\_/   \\_/| |___|         \\__/      \\/                                                      \n");
			printf("                                                                                                           \n");
			printf("     Version 1.0.0.5.                                                                                      \n");
			printf("     Author:                                                                                               \n");
			printf("            ExecuteIf                                                                                      \n");
			printf("            Hwnd                                                                                           \n");
			printf("            Amiriox                                                                                        \n");
			printf("            Jvav-Top-Programmer                                                                            \n");
			printf("            and so on...                                                                                   \n");
			printf("                                                                                                           \n");
			printf("     Github:https://github.com/JvsvScriptDEV/                                                              \n");
			printf("                                                                                                           \n");
			printf("                                                                                                           \n");
			printf("                                                                                                           \n");
			printf("                                                                                                           \n");
			printf("                                                                                                           \n");
			f=1;
			def=1;
		}
		else if(!strncmp(a,"help",strlen("help")))
		{
			cout<<"Are you looking for command \".help\"?\n";
			f=0;
		}
		else if(!strncmp(a,"exit",strlen("exit")))
		{
			def=1;
			f=1;
			cout<<"Are you really want to exit?(Y/N)";
			cin>>tmpa;
			if(tmpa=='Y'||tmpa=='y')
			{
				exit(0);
			}
			else
			{
				fflush(stdin);
				goto o;
			}
		}
		else if(!strncmp(a,"getvar;",sizeof("getvar;")))
		{
			if(pvars=malloc(sizeof(int)))
			{
				vari++;
				cout<<"Var which named \""<<vari<<"\"got successfully.\n";
				def=0;
				f=1;
			}
			else
			{
				cout<<"Var get failed!\n";
				def=0;
				f=1;
			}
		}
		else if(!strncmp(a,"varcount",sizeof("carcount")))
		{
			cout<<"This function is comming soon.\n";
			def=0;
			f=1;
		}

		/// insert new function here......
		else
		{
			f=0;
		}
		if(f==0)
		{
			cout<<"Invalid or incomplete input statement \"";
			for(int i=0;i<strlen(a);i++)
			{
				putchar(a[i]);
			}
			cout<<"\".\n";
		}
		if(f==1)
		{
			if(def==0)
			{
				cout<<"undefined\n";
			}
			if(def==1)
			{
				puts("");
			}
		}
		o:;
	}
	return 0;
}

