#include <iostream>
using namespace std;


double racine_carree_approx ( double a, int n ) {
double u_n = 0;
int i;

for(i = 1; i<= n; i++) {
  u_n = (u_n + a) / (u_n + 1);	
}

return u_n;
}


int main () {
	double nombre;
	int iter;
	
	cout << "Entrer un nombre: ";
    cin >> nombre;
	cout << "Nombre d'iterations : ";
    cin >> iter;
	
	cout << "La racine carre approximee est : " << racine_carree_approx( nombre , iter ) << endl ;
}
