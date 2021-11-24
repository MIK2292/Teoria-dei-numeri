#include <iostream>
#include <string>
#include "TOOLS.h"
#include "TEORIA_DEI_NUMERI_classi.h"
using namespace std;

void Welcome_msg()
{
	cout << "Inserisci un comando:\n\n"
		<< "\t - 'fact n'\nPer fattorizzare un numero n\n"
		<< "\n\t - 'isprime n' \nPer vedere se un numero e' primo\n"
		<< "\n\t - 'view primes to n'\nPer avere una lista di tutti i num primi \n"
		<< "fino ad n\n"
		<< "\n\t - 'view nplusi n i'\nPer vedere la scomposizione in fattori \n"
		<< "primi dei successivi i numeri a partire \nda n\n\n";
}

int main()
{
	string command[3];
	int n, i;
	Number num;
	
	Welcome_msg();
	
	do
	{
			
	cout << '\t';
	cin >> command[0];
	
	if (Title(command[0]) == "Isprime")
	{
		cin >> n;
		cout << "\n" << (isPrime(n) ? 
			"Si, e' primo" : "No, non e' primo, fallito ahahah");
		cout << endl << endl << endl;
		continue;
	}
	else if (Title(command[0]) == "Fact")
	{
		cin >> n;
		num.reset(n);
		num.print_fattori();
		cout << endl << endl << endl;
		continue;
	}
	else if (Title(command[0]) == "Help")
	{
		Welcome_msg();
		continue;
	}
	
	cin >> command[1];
	
	if (Title(command[0]) == "View" 
		and Title(command[1]) == "Nplusi")
	{
		cin >> n >> i;
		//psomma_lineare(n, i);
		
		cout << endl << endl << endl;
		continue;
	}
	
	cin >> command[2];
	
	if (Title(command[0]) == "View" 
		and Title(command[1]) == "Primes" 
		and Title(command[2]) == "To")
	{
		cin >> n;
		nprimi.fill_up_to(n);
		nprimi.print();
		cout << endl << endl << endl;
		continue;
	}
	else continue;
	
	}while(1);
	
}
