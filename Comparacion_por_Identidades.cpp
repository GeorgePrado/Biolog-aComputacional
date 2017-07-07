
#include <bits/stdc++.h>

using namespace::std;

string s1, s2;
vector <char> a, b, A, B;

void imprime( int x )
{
	if( x <= s1.length() )
	{
		cout << s1;
		for( int i = 0; i < s1.length(); i++ )
			a.push_back(s1[i]);

		for( int i = x; i < s2.length(); i++ )
		{
			cout << "-";
			a.push_back('-');
		}
		cout << endl;
	}

	else
	{
		for( int i = 0; i < x-s1.length(); i++ )
		{
			cout << "-";
			a.push_back('-');
		}
	
		cout << s1;
		for( int i = 0; i < s1.length(); i++ )
			a.push_back(s1[i]);

		for( int i = x; i < s2.length(); i++ )
		{
			cout << "-";
			a.push_back('-');
		}
		cout << endl;
	}

	if( x <= s1.length() )
	{
		for( int i = x; i < s1.length(); i++ )
		{
			cout << "-";
			b.push_back('-');
		}
		cout << s2;
		for( int i = 0; i < s2.length(); i++ )
			b.push_back(s2[i]);

		for( int i = s2.length()-x; i < 0; i++ )
		{	
			cout << "-";
			b.push_back('-');
		}
		cout << endl;
	}

	else
	{
		cout << s2;
		for( int i = 0; i < s2.length(); i++ )
			b.push_back(s2[i]);

		for( int i = s2.length(); i < x; i++ )
		{
			cout << "-";
			b.push_back('-');
		}
		cout << endl;
	}
}


int compara( int x )
{
	int c = 0;
	imprime( x );
	for( int i = 0; i < a.size(); i++ )
		if( a[i] == b[i] )
			c++;
	cout << "Número de Identidades = " << c << endl << endl;
	return c;
}


int main( void )
{
	int mayor = 0;
	cout << "Ingrese primera secuencia: ";
	cin >> s1;
	cout << "Ingrese segunda secuencia: ";
	cin >> s2;
	cout << endl;

	for( int i = 1; i <= s1.length()+s2.length()-1; i++ )
	{
		int r = compara( i );
		if( mayor <= r )
		{
			mayor = r;
			A = a;
			B = b;
		}
		a.clear();
		b.clear();
	}
	cout << "Mayor = " << mayor << endl;
	for( int i = 0; i < A.size(); i++ )
		cout << A[i];
	cout << endl;
	for( int i = 0; i < B.size(); i++ )
		cout << B[i];
	cout << endl;

	return 0;
}




