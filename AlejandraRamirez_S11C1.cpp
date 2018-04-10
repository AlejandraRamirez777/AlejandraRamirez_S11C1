#include <iostream>

using namespace std;

double func_primeS(double I, double S, double B);
double func_primeI(double I, double S, double B, double g);

int main () {
   //Variables del problema
   int Nt = 771;
   int I0 = 1;
   int s0 = 770;
   //caso 1
   double B1 = 0.0022;
   double g1 = 0.45;
   //caso 2
   double B2 = 0.001;
   double g2 = 0.2;

   //Variables leap-frog
   double h = 0.01;
   double min_x = 0.0;
   double max_x = 4.0;
   int N = int((max_x-min_x)/h);

   //Arrays de ceros
   double ss[N];
   double II[N];
   
   for (int i = 0; i < N; i++) {
       ss[i] = 0;
       II[i] = 0;
   }

   II[0] = I0;
   ss[0] = s0;

   II[1] = II[0] + h*func_primeI(II[0],ss[0],B1,g1);
   ss[1] = ss[0] + h*func_primeS(II[0],ss[0],B1);

   for (int i = 2; i < N; i++) {
       II[i] = II[i-2] + 2*h*func_primeI(II[i-1],ss[i-1],B1,g1);
       ss[i] = ss[i-2] + 2*h*func_primeS(II[i-1],ss[i-1],B1);
       cout << II[i] << "," << i << endl;
    
   }



   return 0;
}

double func_primeS(double I, double S, double B){
   double sol = -B*I*S;
   return sol;
}

double func_primeI(double I, double S, double B, double g){
   double sol = B*I*S - g*I;
   return sol;
}
