#include <iostream>
#include <vector>
using namespace std;


void afficheDes ( vector<int> des ) {
int i;

//for(auto it = des.begin(); it!= des.end(); ++it) {
//  cout << *it << ' ';	
//}

for(i = 0; i< 5; i++) {
  cout << des[i] << ' ';	
}

cout << endl;
}

void afficheFaces ( vector<int> faces ) {
int i;

for(i = 0; i < 6; i++) {
  cout << faces[i] << ' ';	
}

cout << endl;
}


int pointsFigureYamsTest ( vector<int> des) {
	int res;
	
	// tous les des sont egaux
	if ((des[0] == des[1]) && (des[0] == des[2]) && (des[0] == des[3])&& (des[0] == des[4])) {
		res = des[0]*5+60;
	}
	else {
		res = 0;
	}
	
	return res;
}

vector <int> nombreFace ( vector <int> tirage ) {
	//initialisation du nombre de face a zero
	vector < int > faceDes = { 0 , 0 , 0 , 0 , 0 , 0 };

	// Pour chaque des du tirage
	for ( int i =0 ; i < tirage.size() ; i++ ) {
		// calculer sa face
		int face = tirage[i] - 1;
		// incrementer la face dans le tableau
		faceDes [face] = faceDes [face] + 1;
	}

return faceDes ;

}


int pointsFigureYamsCarre ( vector<int> des) {
	int res;
	vector<int> faceDes;
	
	faceDes = nombreFace(des);

	if (faceDes[0] == 4) {
		res = 34;
	}
	else if (faceDes[1] == 4) {
		res = 38;
	}
	else if (faceDes[2] == 4) {
		res = 42;
	}
	else if (faceDes[3] == 4) {
		res = 46;
	}
	else if (faceDes[4] == 4) {
		res = 50;
	}
	else if (faceDes[5] == 4) {
		res = 54;
	}
	else {
		res = 0;
	}
	return res;

//	for(i = 0; i < 6; i++) {
//		if (faceDes[i] == 4) {
//			return (i+1)*4 + 30;
//		}
//	}
//		
//	return 0;
}

int pointsFigureYamsBrelan ( vector<int> des) {
	int i;
	int res;
	vector<int> faceDes;
	
	faceDes = nombreFace(des);
	//Regardez si une face apparait 3 fois
	for(i = 0; i < 6; i++) {
		if (faceDes[i] == 3) {
			return (i+1)*3 + 10;
		}
	}
		
	return 0;
}

int pointsFigure2 ( vector<int> faceDes) {
	int i;
	int res;

	for(i = 0; i < 6; i++) {
		if (faceDes[i] == 2) {
			return (i+1)*2;
		}
	}
		
	return 0;
}

int pointsFigureYamsFull ( vector<int> des) {
	int i;
	int res;
	int fig2;
	vector<int> faceDes;
	
	faceDes = nombreFace(des);
	for(i = 0; i < 6; i++) {
		if (faceDes[i] == 3) {
			fig2 = pointsFigure2(faceDes);
			if(fig2 != 0) {
				return (i+1)*3 + fig2 + 20;
			}
		}
	}
		
	return 0;
}


int aleaint(int a, int b) 
{
	return (rand()%(b-a+1) + a); 
}


vector<int> lanceDes()
{
int i;
vector<int> des = {0,0,0,0,0};

for (i = 0; i < 5; i++) {
	des[i] = aleaint(1,6);
}

return des;
}


int pointsFigure(vector<int> des, string figure)
{
	int res;
	
	if (figure == "yams") {
		res = pointsFigureYamsTest(des);
	}
	else if (figure == "brelan") {
		res = pointsFigureYamsBrelan(des);
	}
	else if (figure == "full") {
		res = pointsFigureYamsFull(des);
	}
	else if (figure == "carre") {
		res = pointsFigureYamsCarre(des);
	}
	else {
			res = 0;
	}
	
	return res;			
}


int main () {
//	vector<int> des1{2, 2, 3, 2, 3};
//	vector<int> yams{4, 4, 4, 4, 4};
//	vector<int> full{5, 1, 1, 5, 5};
//	vector<int> brelan{3, 4, 3, 3, 2};
//	vector<int> carre{5, 4, 4, 4, 4};
	
//	afficheDes(des1);
//	cout << "Points: " << pointsFigureYamsTest(des1) << endl;
//	afficheFaces(nombreFace(des1));
//	cout << endl;
	
//	afficheDes(yams);
//	cout << "Points: " << pointsFigureYamsTest(yams) << endl;
//	afficheFaces(nombreFace(yams));
//	cout << endl;
	
//	afficheDes(full);
//	afficheFaces(nombreFace(full));
//	cout << "Full : " << pointsFigureYamsFull(full) << endl;
//	cout << endl;
	
//	afficheDes(brelan);
//	afficheFaces(nombreFace(brelan));
//	cout << "Brelan : " << pointsFigureYamsBrelan(brelan) << endl;
//	cout << endl;

//	afficheDes(carre);
//	afficheFaces(nombreFace(carre));
//	cout << "Carre : " << pointsFigureYamsCarre(carre) << endl;
//	cout << endl;

//	afficheDes(brelan);
//	cout << "Full : " << pointsFigureYamsFull(brelan) << endl;
//	cout << endl;

srand(time(0));
string figure;
vector <int> des;

des = lanceDes();

cout << " Voici vos dés " << endl;
afficheDes(des);

do {
	cout << "Quelle figure choisissez−vous ? " ;
	cin >> figure;
} 
while ( figure != "brelan" and figure != "carre" and
figure != "full" and figure != "yams" ) ;

cout << "Vous avez marqué " << pointsFigure(des , figure ) << " points" << endl;

return 0 ;
}
