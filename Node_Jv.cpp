/*
 * @Author:  
 * @Date: 2020-11-17 20:35:00
 * @LastEditTime: 2020-12-01 18:31:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \node.jv\main.cpp
 */
//PLEASE READ THIS WITH UTF-8
#include <bits/stdc++.h>
#include <Windows.h>
#ifdef __linux__
#include <gl/glut.h>
#include <openssl/md5.h>
#include <curl/curl.h>
#endif
#undef pascal
#define color(a) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a)
#define pass putchar('\0')
#define _DEBUG_
//预处理器区
using namespace std;
//函数声明区
/**
 * @description:  Dispatch The console Message
 * @param arg
 */
void Dispatch_message(string arg);
/**
 * @description: Display The Welcome Message
 */
void welcome();
/**
 * @description: Display an error
 * @param err_code
 */
void error(errno_t err_code);
/**
 * @description: require a module
 * @param module
 */
void require(string module);
/**
 * @description:download  from Internet 
 * @param f_addr
 */
void wget(string f_addr);
//常量区

//全局函数区
char op = '$';
bool Exit_ = false;
string arg_user;
void *variable[114514];
char tmp[114514];
//类变量
string fname;
//类是否require
bool fs = false, _time = false, net = false;
//对于类操作的判断
bool _Fs_is_create = false;
//main()
int main(int argc, char **argv)
{
	system("chcp 65001>nul");
	system("title Node.Jv");
	ZeroMemory(variable, sizeof(variable));
	welcome();
	while (!Exit_)
	{
		printf("%c ", op);
		getline(cin, arg_user);
		Dispatch_message(arg_user);
	}
	return 0x000000000l;
}
//函数实现区
void wget(string f_addr)
{
	string tmp = "bin\\wget.exe " + f_addr+" --no-check-certificate";
	if (!(WinExec(tmp.c_str(), SW_NORMAL) > 31))
	{
		color(4);
		printf("Download Failed!\n");
		color(7);
		return;
	}
	system("title Node.Jv");
}
void error(errno_t err_code)
{
	color(4);
	switch (err_code)
	{
	case 0:
	{
		//没有分号
		printf("Error: expected ';' was not found on this statement\n");
		break;
	}
	case 1:
	{
		//括号配对不正确
		printf("Error: expected ')' was not found on this statement\n");
		break;
	}
	case 2:
	{
		//""匹配不正确
		printf("Error: expected ' \" ' was not found on this statement\n");
		break;
	}
	case 3:
	{
		printf("Error: module is not require\n");
		break;
	}
	case 4:
	{
		printf("Error: too few args on this statement\n");
		break;
	}
	case 5:
	{
		printf("Error: unkown require module\n");
		break;
	}
	case 6:
	{
		printf("Error: can't create another stream before one stream is closed\n");
		break;
	}
	case 7:
	{
		printf("Error: cannot use stream function before the stream is create\n");
		break;
	}
	default:
	{
		MessageBoxA(NULL, ":(\nNodeJv Crashed!\n\nat NodeJv_runtime.dll:\n\t315:212 Unknown Error Code\n\t921:73   Underfind behavior in \"Node_Jv_source(UINT type)\"\n\nIf problem still happen anyway,please contact to us:\nhttps://www.jvavexec.top/", "NodeJv -- CrashHander", MB_OK | MB_SYSTEMMODAL | MB_ICONHAND);
		exit(0);
		break;
	}
	}
	color(7);
}
void require(string module)
{
	color(8);
	if (module == "fs")
	{
		fs = true;
		printf("module \"fs\" required success\n");
	}
	else if (module == "time")
	{
		_time = true;
		printf("module \"time\" required success\n");
	}

	else if (module == "net")
	{
		net = true;
		printf("module \"net\" required success\n");
	}
	else
	{
		error(5);
	}
	color(7);
}
void welcome()
{
	color(10);
	cout << "Welcome to Node.Jv!\n Type \"help\" for some help\n";
	color(7);
}
void Dispatch_message(string arg)
{
	if (arg == "exit()")
		Exit_ = true;
	else if (arg == "")
		printf("underfined\n");
	else if (arg == "crash")
		error(112);
	else if (arg == "help")
	{
		color(11);

		printf("     |\\     |            |               ---------      (C) 2020                                            \n");
		printf("     | \\    |            |                   |                                                             \n");
		printf("     |  \\   |            |  ___              |                                                             \n");
		printf("     |   \\  |   /-\\   /--| /   \\             |   \\    /                                                    \n");
		printf("     |    \\ |  |   | |   | |---              /    \\  /                                                     \n");
		printf("     |     \\|   \\_/   \\_/| |___|         \\__/      \\/                                                      \n");
		printf("                                                                                                           \n");
		printf("     Version 0.0.1                                                                                    \n");
		printf("     Author:                                                                                               \n");
		printf("            ExecuteIf                                                                                      \n");
		printf("            Hwnd                                                                                           \n");
		printf("            Amiriox                                                                                        \n");
		printf("            Jvav-Top-Programmer                                                                            \n");
		printf("            Caviar-X                                                                            \n");
		printf("            and so on...                                                                                   \n");
		printf("                                                                                                           \n");
		printf("     Github:https://github.com/JvsvScriptDEV/                                                              \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		color(4);
		printf("----------NodeJv help page(1/1)----------\n");
		printf("console.log(strings): output an strings on th screen\n");
		printf("console.clear():clear the screen\n");
		printf("console.setop(op):set another op\n");
		printf("require(module):require a module such as \"fs\"\n");
		printf("exit(): exit The Node.Jv\n");
		printf("crash: crash Node.Jv(你肯定没想到这个程序支持自毁)\n");
		printf("All modules: net,time,fs\n");
		printf(" see module help,type <module name> help\n");
		printf("----------NodeJv help page(1/1)----------\n");

		color(7);
	}
	//console类实现
	else if (!strncmp(arg.c_str(), "console.alert(", strlen("console.alert(")))
	{
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\"')
			error(2);
		else
		{
			for (size_t i = 15; i <= arg.size() - 4; i++)
			{
				tmp[i - 15] = arg[i];
			}
			MessageBoxA(NULL, tmp, "NodeJv -- Alert", MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
			ZeroMemory(tmp, sizeof(tmp));
		}
	}
	else if (!strncmp(arg.c_str(), "console.log(\"", strlen("console.log(\"")))
	{
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\"')
			error(2);
		else
		{
			for (size_t i = 13; i <= arg.size() - 4; i++)
			{
				putchar(arg[i]);
			}
			putchar('\n');
		}
	}
	else if (!strncmp(arg.c_str(), "console.clear(", strlen("console.clear(")))
	{
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else
		{
#ifdef WIN32
			system("cls");
#endif
#ifdef __linux__
			system("clear");
#endif
			welcome();
		}
	}
	else if (!strncmp(arg.c_str(), "console.setop('", strlen("console.setop('")))
	{
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\'')
			error(2);
		else
		{
			op = arg[15];
#ifdef WIN32
			system("cls");
#endif
#ifdef __linux__
			system("clear");
#endif
			welcome();
		}
	}
	//require实现
	else if (!strncmp(arg.c_str(), "require(\"", strlen("require(\"")))
	{
		string req_mod;
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\"')
			error(2);
		else
		{
			for (size_t i = 9; i <= arg.size() - 4; i++)
			{
				req_mod += arg[i];
			}
			require(req_mod);
		}
	}
	//fs类实现
	else if (arg == "fs help")
	{
		color(9);
		printf("----------module fs help----------\n");
		printf("create(filename): create a file named filename\n");
		printf("write(strings):write strings with create file\n");
		//printf("writeline(strings):write strings with create file and auto nextline\n");
		printf("readline(linenumber):read a file\n");
		printf("close(): close this filestream\n");
		printf("----------module fs help----------\n");
		color(7);
	}
	else if (!strncmp(arg.c_str(), "fs.create(\"", strlen("fs.create(\"")))
	{

		if (!fs)
			error(3);
		else if (_Fs_is_create)
			error(6);
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\"')
			error(2);
		else
		{
			for (size_t i = 11; i <= arg.size() - 4; i++)
			{
				fname += arg[i];
			}
			ofstream f(fname);
			f.close();
			color(8);
			printf("File stream create success\n");
			color(7);
			_Fs_is_create = true;
		}
	}
	else if (!strncmp(arg.c_str(), "fs.write(\"", strlen("fs.write(\"")))
	{
		if (!_Fs_is_create)
			error(7);
		else if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\"')
			error(2);
		else if (!fs)
			error(3);
		else
		{

			ofstream l(fname, ios::app);
			string tmp_s;
			for (size_t i = 10; i <= arg.size() - 4; i++)
			{
				tmp_s += arg[i];
			}
			l << tmp_s;
			l.close();
			tmp_s = "";
		}
	}
	else if (!strncmp(arg.c_str(), "fs.writeline(\"", strlen("fs.writeline(\"")))
	{
		if (!_Fs_is_create)
			error(7);
		else if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\"')
			error(2);
		else if (!fs)
			error(3);
		else
		{

			ofstream l(fname, ios::app);
			string tmp_s;
			for (size_t i = 14; i <= arg.size() - 4; i++)
			{
				tmp_s += arg[i];
			}
			tmp_s += '\n';
			l << tmp_s;
			l.close();
			tmp_s = "";
		}
	}
	else if (!strncmp(arg.c_str(), "fs.close(", strlen("fs.close(")))
	{
		if (!_Fs_is_create)
			error(7);
		else if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (!fs)
			error(3);
		else
		{
			fname = "";
			_Fs_is_create = false;
			color(8);
			printf("filestream close success\n");
			color(7);
		}
	}
	/*
		 else if (!strncmp(arg.c_str(), "fs.readline(", strlen("fs.readline(")))
	{
		if (!_Fs_is_create)
			error(7);
		else if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\"')
			error(2);
		else if (!fs)
			error(3);
		else
		{
			string tmp_s, h_line[114514]; 
			for (size_t i = 12; i < arg.size() - 4; i++)
			{
				tmp_s += arg[i];
			}
			size_t linenum = atoi(tmp_s.c_str());
			tmp_s = "";
			ifstream ff(fname);
			for (size_t i = 0; ff.eof() != true; i++)
			{
				ff >> h_line[i];
			}
			cout << h_line[linenum] << '\n';
			ZeroMemory(h_line, sizeof(h_line));
			linenum = 0;
		}
	}
*/
	//time模块实现
	else if (arg == "time help")
	{
		color(9);
		printf("----------module time help----------\n");
		printf("Display_time():display the time now\n");
		printf("Display_UTC_time():display UTC time now\n");
		printf("----------module time help----------\n");
		color(7);
	}
	else if (!strncmp(arg.c_str(), "time.Display_time(", strlen("time.Display_time(")))
	{
		if (!_time)
			error(3);
		else if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else
		{
			time_t T = time(0);
			string __t = ctime(&T);
			cout << __t << '\n';
			T = 0;
			__t = "";
		}
	}
	else if (!strncmp(arg.c_str(), "time.Display_UTC_time(", strlen("time.Display_UTC_time(")))
	{
		if (!_time)
			error(3);
		else if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else
		{
			time_t now = time(0);
			tm *tmp = gmtime(&now);
			string tmp_s = asctime(tmp);
			cout << "UTC: " << tmp_s << '\n';
		}
	}
	//net模块实现
	else if (arg == "net help")
	{
		color(9);
		printf("----------module net help----------\n");
		printf("Download_Url_To_File(strings): download file from url\n");
		printf("----------module net help----------\n");
		color(7);
	}
	else if (!strncmp(arg.c_str(), "net.Download_Url_To_File(\"", strlen("net.Download_Url_To_File(\"")))
	{
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\"')
			error(2);
		else if (!net)
			error(3);
		else
		{
			string ___t;
			for (size_t i = 26; i <= arg.size() - 4; i++)
			{
				___t += arg[i];
			}
			wget(___t);
		}
	}
}
