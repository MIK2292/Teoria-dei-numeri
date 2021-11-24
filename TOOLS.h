#ifndef TOOLS_H
#define TOOLS_H


#include <string>
#include <time.h>
using namespace std;

string Title(string str)
{
	if (str[0] <= 'z' and str[0] >= 'a')
		str[0] += 'A' - 'a';
	
	for (int index = 1; str[index] != '\0'; index++)
	{
		if (str[index] <= 'Z' and str[index] >= 'A')
			str[index] -= 'A' - 'a';
		
//		else if (str[index] == ' ' and str[index+1] <= 'z' and str[index+1] >= 'a')
//			str[++index] += 'A' - 'a';
	}	
	return str;
} // Title("parola") = "Parola", funziona solo con parole singole


//string operator*(string str, int num)
//{
//	string to_return;
//	for(int i = 0; i < num; i++)
//		to_return += str;
//	return to_return;
//}

string formatta_tab(int num)
{
	if (num <= 99999999)
		return to_string(num) + "\t\t";
	else
		return to_string(num) + "\t";
}

string formatta_tab(string str, int tot_tab = 2)
{
	int len = (str.size() / 8) +1;
	string to_return = str;
	
	if (len > tot_tab)
		tot_tab = len +1;
	
	for(int i = len; i <= tot_tab; i++)
		to_return += '\t';
		
	return to_return;	
}

void sleep(int secondi = 2)
{
	int then = time(NULL) + secondi;
	while(time(NULL) != then){}
}


#endif
