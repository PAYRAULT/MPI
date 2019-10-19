#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


void affiche_personnage(vector<int> pers) {
	cout << "Le nombre de points de vie est " << pers[0] << endl;
	cout << "L'attaque est de " << pers[1] <<endl;
	cout << "La defense est de " << pers[2] <<endl;
	cout << "L'initiative est de " << pers[3] <<endl;
}


bool est_mort(vector<int> pers) {
	return pers[0] <= 0;
}


vector<int> attaque(vector<int> persA, vector<int> persB) {
	int pointsAttaque;
	
	// calcul des points d'attaque
	pointsAttaque = persA[1] - persB[2];
	// Si l'attaque est suffisante modifier la vie du personnage attaque
	if(pointsAttaque > 0) {
		persB[0] =persB[0] - pointsAttaque;
	}
	
	return persB;
}



int combat_simple(vector<int> persA, vector<int> persB) {
	while(true) {
		//personnage A attaque
		persB = attaque(persA, persB);
		//si personnage B est mort, c'est fini
		if(est_mort(persB)) {
			//personnage A a gagne`
			return 1;
		}

		//personnage B attaque
		persA = attaque(persB, persA);
		//si personnage A est mort, c'est fini
		if(est_mort(persA)) {
			//personnage B a gagne
			return 2;
		}
		
		//continuer le combat
	}
}


//int mystere(vector<int> blabla, vector<int> bloblo){
//int schtroumpf = 3;
//if (blabla[schtroumpf] > bloblo[schtroumpf]){
//int miaou = blabla[schtroumpf] - bloblo[schtroumpf];
//for(int hiphop = 0; hiphop < miaou; hiphop++){
//blabla = attaque(bloblo, blabla);
//}
//} else {
//int glouglou = bloblo[schtroumpf] - blabla[schtroumpf];
//for(int hophip = 0; hophip < glouglou; hophip++){
//bloblo = attaque(blabla, bloblo);
//}
//}
//return combat_simple(blabla, bloblo);
//}

int combat(vector<int> persA, vector<int> persB){
int initiative = 3;
//SI l'initiative du [ersonnage A est superieur a celle du B
if (persA[initiative] > persB[initiative]){
	// Calculer la difference d'initiative
	int diffInitiative = persA[initiative] - persB[initiative];
	// Le personnage B attaque autant de fois que la difference
	for(int i = 0; i < diffInitiative; i++){
		persA = attaque(persB, persA);
	}
} 
else {
	// Calculer la difference d'initiative
	int diffInitiative = persB[initiative] - persA[initiative];
	// Le personnage A attaque autant de fois que la difference
	for(int i = 0; i < diffInitiative; i++){
		persB = attaque(persA, persB);
	}
}

// Commencer le combat simple
return combat_simple(persA, persB);
}


int combat_initiative(vector<int> persA, vector<int> persB){
	// Au debut du combat les secondes sont a zero
	int sec = 0;
	bool tourA, tourB;
	
	// jusqu'a la mort d'un personnage
	while(true) {
		// tour du personnage A?
		tourA = (sec%persA[3] == 0);
		// tour du personnage B?
		tourB = (sec%persB[3] == 0);
		
		// C'est le tour de A d'attaquer
		if(tourA && !tourB)
			persB = attaque(persA, persB);
		
		// C'est le tour de B d'attaquer
		if(tourB && !tourA)
			persA = attaque(persB, persA);

		// C'est le tour de a et B d'attaquer
		if(tourA && tourB)
			// on choist de faire attaquer B
			persA = attaque(persB, persA);

		// Le personnage A est mort, B a gagne
		if(est_mort(persA))
			return 2;
		// Le personnage B est mort, A a gagne
		if(est_mort(persB))
			return 1;
		
		//passer au tour suivant
		sec++;
	}
}

int main(){

affiche_personnage({100,20,7,4});
assert( est_mort({100,20,7,4}) == false);
assert( est_mort({0,20,7,4}) == true);
assert( est_mort({-10,20,7,4}) == true);

affiche_personnage( attaque({100,20,7,4}, {100,13,10,4}));
affiche_personnage( attaque({100,10,7,4}, {100,13,10,4}));

cout << combat_simple({310,34,12,4}, {100,9,5,4}) << endl;
cout << combat_simple({310,34,12,4}, {100,19,45,4}) << endl;

cout << combat({310,34,8,308}, {100,9,5,1}) << endl;
cout << combat({310,34,12,7}, {100,19,45,4}) << endl;

cout << combat_initiative({310,34,12,7}, {100,19,45,4}) << endl;

}