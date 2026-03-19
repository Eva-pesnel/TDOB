#include <iostream> 
using namespace std;
class A {
public:
	A() { x = 0;    cout << "1"; } //c'est le constructeur par défaut
	A(int px) { x = px;   cout << "2"; } //c'est le constructeur avec paramètres
	A(const A& pa) { x = pa.x;  cout << "3"; } //c'est le constructeur de copie
protected:
	int x;
};

class B {
public:
	B(const A& pa = A()) : a(pa) { cout << "4"; } //initialisation directe
	B(const A& pa, int py) { a = pa; y = py;  cout << "5"; } //affectation
protected:
	A a;
	int y;
};

class C : public B {
public:
	C(int pz = 1) { z = pz;    cout << "6"; }
	C(A pa) : B(pa) { z = 0;    cout << "7"; }
	C(const B& pb) : B(pb), a(1) { z = 0;  cout << "8"; }
protected:
	A a;
	int z;
};

int main() {
	cout << "-- A --\n";
	A a0;   cout << endl; //affiche 1
	A a1(3);   cout << endl; //affiche 2
	A a2(a1);   cout << endl; //affiche 3
	A a3 = a2;   cout << endl; //affiche 3 aussi de manière différente
	a3 = a1;   cout << endl;
	cout << "-- B --\n";
	B b0(a0, 3);  cout << endl; //copie 3 puis affiche 5
	B b1(a1);   cout << endl; //copie 3 et affiche 4
	B b2;   cout << endl; //affiche 1 3 4
	cout << "-- C --\n";
	C c0;   cout << endl; //affiche 1 3 4 6
	C c1(a1);   cout << endl; //affiche 3 3 4 7
	C c2(b2);   cout << endl; //affiche 3 2 8
}