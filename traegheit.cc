#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include "Koerper.hh"
#include <iostream>
#include <memory>


double traegheit ( Koerper * k , Vektor a , Vektor u) {
std :: cout << " berechne fuer " << k -> name () << '\n';
  const int N = 10000; // Anzahl Integrationspunkte
  const double M = 2;      // Masse
  double J = 0;   
  double m = M / N; 
  for (int i = 0; i < N; ++i) {
    Vektor x = k->punkt();
    double r = ((x-a).kreuz(u).betrag())/((u).betrag()); 
    J += m * r * r;

}  std::cout << J << std::endl;
  }


int main() {
  const double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  std :: unique_ptr < Koerper > b( new Zylindermantel ( ZM_R , ZM_L ));
traegheit (b.get() ,a , u );

std :: unique_ptr < Koerper > k( new Vollzylinder ( ZM_R , ZM_L ));
traegheit (k.get() ,a , u );  


return 0;
}
