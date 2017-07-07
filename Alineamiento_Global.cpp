
#include <bits/stdc++.h>
#define N 1000

using namespace::std;

string s1, s2;
int match, mis, gap;

int A[N][N];
pair <int, int> P[N];
int len = 0;

void mostrar( )
{
	cout << "\nMATRIZ: " << endl;
	for( int i = 0; i <= s2.length(); i++ )
	{
		for( int j = 0; j <= s1.length(); j++ )
			cout << A[i][j] << " ";
		cout << endl;
	}
}


int verifica( int x, int y )
{
	if( s1[y-1] == s2[x-1] ) return match;
	else return mis;
}


int main( void )
{
	memset( A, 0, sizeof A );
	cout << "Ingrese match = ";
	cin >> match;
	cout << "Ingrese el mismatch = ";
	cin >> mis;
	cout << "Ingrese el gap = ";
	cin  >> gap;
	cout << "Ingrese primera secuencia = ";
	cin >> s1;
	cout << "Ingrese segunda secuencia = ";
	cin >> s2;

	A[0][0] = 0;
	for( int i = 1; i <= s1.length(); i++ )
		A[0][i] = A[0][i-1] + gap;

	for( int i = 1; i <= s2.length(); i++ )
		A[i][0] = A[i-1][0] + gap;

	for( int i = 1; i <= s2.length(); i++ )
	{
		for( int j = 1; j <= s1.length(); j++ )
		{
			A[i][j] = max( A[i][j-1]+gap, A[i-1][j]+gap );
			A[i][j] = max( A[i][j], A[i-1][j-1]+verifica(i,j) );
		}
	}

	mostrar();
	cout << "\nScore óptimo global = " << A[s2.length()][s1.length()] << endl;
	
	int a = s2.length();
	int b = s1.length();
	P[len++] = make_pair( a, b );

	do
	{
		if( a != 0 && b != 0 ) 
		{
			if( A[a][b] == A[a-1][b]+gap ) 
			{	
				P[len++] = make_pair( a-1, b );
				a--;
			}
				
			else if( A[a][b] == A[a][b-1]+gap ) 
			{	
				P[len++] = make_pair( a, b-1 );
				b--;
			}	

			else
			{	
				P[len++] = make_pair( a-1, b-1 );
				a--;
				b--;
			}
		}

		else if( a == 0 )
		{
			while( b != 0 )
			{
				P[len++] = make_pair( a, b-1 );
				b--;
			}
		}

		else if( b == 0 )
		{
			while( a != 0 )
			{
				P[len++] = make_pair( a-1, b );
				a--;
			}
		}

	} while( a != 0 || b != 0 );

	cout << "\nAlineamiento óptimo: " << endl;

	for( int i = len-2; i >= 0; i-- )
	{
		if( P[i].second != P[i+1].second )
			cout << s1[P[i].second-1];
		else
			cout << "-";
	}
	cout << endl;

	for( int i = len-2; i >= 0; i-- )
	{
		if( P[i].first != P[i+1].first )
			cout << s2[P[i].first-1];
		else
			cout << "-";
	}
	cout << endl << endl;

	return 0;
}












