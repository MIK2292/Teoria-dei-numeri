#ifndef S_TEORIA_NUMERI_H
#define S_TEORIA_NUMERI_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "TOOLS.h"
using namespace std;

//class n1
class Primes{
	public:
	Primes() { vec = {2, 3}; };
	
	void fill_up_to(int);
	void print();
	vector<int> vettore() { return vec; };
	
	private:
	vector<int> vec;
	bool isprime_private(int);
};

bool Primes::isprime_private(int num)
{
	int root = sqrt(num);
	
	for(int x : vec)
	{
		if (num % x == 0)
			return 0; //not prime
		if (root < x)
			return 1;
	}
	return 1; //prime
}

void Primes::fill_up_to(int num)
{
	int num_to_check = 
		vec[vec.size() - 1] + 2;
	//2 e' l'unico primo pari
	//controlla solo i numeri dispari
	
	while (num_to_check <= num)
	{
		if (isprime_private(num_to_check))
			vec.push_back(num_to_check);
			
		num_to_check += 2;
	}
}

void Primes::print()
{
	cout << "\n\nI numeri primi sono:\n\n";
	
	for (int x : vec)
		cout << x << '\t';
}

Primes nprimi;

bool isPrime(int n)
{
	nprimi.fill_up_to(n);
	vector<int> primi = nprimi.vettore();
	return (binary_search(primi.begin(), primi.end(), n));
}


//class n2
class Fraction{
	public:
	Fraction(int num = 1, int den = 1) 
		{ set(num, den); };
	
	void set(int Num, int Den) 
		{ 
			N = Num;
			if (Den == 0)
			{
				cout << 
				"\nDenominator not valid\n";
				D = 1;
			}
			else D = Den; 
		};
		
	string get_str() 
		{ return to_string(N) 
			+ '/' + to_string(D); };
			
	void minimize();
	
	int min_ND()
		{ return ( N >= D ? D : N); };
		
	private:
	int N; //numeratore
	int D; //denominatore
};

void Fraction::minimize()
{
	if (N % D == 0)
	{
		N /= D;
		D = 1;
		return;
	}
	else if (D % N == 0)
	{
		D /= N;
		N = 1;
		return;
	}
	
	int limit = sqrt(min_ND()) +1; 
	
	nprimi.fill_up_to(limit);
	
	for (int x : nprimi.vettore())
	{
		if (x > limit)
			break;
					
		while (N % x == 0 and D % x == 0)
		{
			N /= x;
			D /= x;
		}
	}		
}




struct NumExp{
	int num;
	int exp;
};

//class n3
class Number{
	public:
	Number(int n = 0) { num = n; };
	
	void reset(int n) 
	{ 
		num = n;
		fattori.clear();
	};
	
	int get_extention() { return fattori.size(); };
	
	void print_fattori();
	
	private:
	int num;
	vector<NumExp> fattori;
	
	void evaluate_fattori();
};

void Number::evaluate_fattori()
{
	//int limit = num/2 + 1;
	int copynum = num;
	
	nprimi.fill_up_to(copynum);
	
	for(int x : nprimi.vettore())
	{
		if (copynum % x == 0)
		{
			fattori.push_back({x, 1});
			copynum /= x;
			
			while (copynum % x == 0)
			{
				fattori[fattori.size() -1].exp++;
				copynum /= x;
			}
		}
		//if (x > limit)
//			return;
	}
}

void Number::print_fattori()
{
	evaluate_fattori();
	cout << "\n\nI fattori di " << num << " sono:\n";
	
	string str = "";
	for (NumExp x : fattori)
		str += to_string(x.num) + "^" + to_string(x.exp) + "  ";
	cout << formatta_tab(str, 3) << "n. ";
	
	switch(get_extention()){
		case 1: cout << "Primo"; break;
		case 2: cout << "Secondo"; break;
		case 3: cout << "Terzo"; break;
		case 4: cout << "Quarto"; break;
		case 5: cout << "Quinto"; break;
		case 6: cout << "Sesto"; break;
		default: cout << "Troppo grande ahah"; break;
	}

	cout << endl;
}




#endif

//void print_fracts(int denominatore, float begin = 0, float end = 1)
//{
////	vector<Fraction> fracts(denominatore +1);
//	Fraction fract;
//	
//	for (int i = 0; i <= denominatore; i++)
//	{
//		fract.set(i, denominatore);
//		fract.minimize();
//		
//		cout << fract.get_str() << "\n";
//	}
//}

//int main ()
//{
//	print_fracts(1000);
//	
//	return 0;
//}
