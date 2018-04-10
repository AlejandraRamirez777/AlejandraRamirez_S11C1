#include <iostream>

using namespace std;

double func_prime(double x, double y);

int main () {
   //Variables del problema
   int Nt = 771;
   int I0 = 1;
   int s0 = 770;
   double B1 = 0.0022;
   double g1 = 0.45;
   double B2 = 0.001;
   double g2 = 0.2;

   //Variables leap-frog
   double h = 0.01;
   double min_x = 0.0;
   double max_x = 4.0;
   int N = int((max_x-min_x)/h);

   return 0;
}

double func_prime(double x, double y){
   double sol = -y;
   return sol;
}
