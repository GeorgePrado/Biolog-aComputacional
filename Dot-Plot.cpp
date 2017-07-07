
#include <bits/stdc++.h>
#define N 1000

using namespace::std;

int M;
int memo[N][N];
string a, b;

int dp( int l, int r )
{
	if( memo[l][r] != -1 )
		return memo[l][r];

	if( l == a.length() || r == b.length() )
		return 0;

	if( a[l] == b[r] )
		memo[l][r] = 1 + dp(l+1,r+1);
	
	else
		memo[l][r] = max( dp(l+1,r), dp(l,r+1) );
	
	return memo[l][r];
}


int main( void )
{
	memset( memo, -1, sizeof memo );
	cout << "Ingrese primera secuencia: ";
	cin >> a;
	cout << "Ingrese segunda secuencia: ";
	cin >> b;

	cout << "Número de Coincidencias = ";
	cout << dp(0,0) << endl;
/*
	for( int i = 0; i < a.length(); i++ )
		for( int j = 0; j < b.length(); j++ )
			cout << "memo["<<i<<"]["<<j<<"] = " << memo[i][j] << endl;
*/

	return 0;
}


