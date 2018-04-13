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
   double max_x = 40.0;
   int N = int((max_x-min_x)/h);

   //Arrays de ceros
   double ss1[N];
   double II1[N];
   
   for (int i = 0; i < N; i++) {
       ss1[i] = 0;
       II1[i] = 0;
   }

   double IM1 = 0;
    double T1 = 0; 

   II1[0] = I0;
   ss1[0] = s0;

   II1[1] = II1[0] + h*func_primeI(II1[0],ss1[0],B1,g1);
   ss1[1] = ss1[0] + h*func_primeS(II1[0],ss1[0],B1);

   for (int i = 2; i < N; i++) {
       II1[i] = II1[i-2] + 2*h*func_primeI(II1[i-1],ss1[i-1],B1,g1);
       ss1[i] = ss1[i-2] + 2*h*func_primeS(II1[i-1],ss1[i-1],B1);
       cout << II1[i] << "," << i*0.01 << endl;

     if(IM1 < II1[i]) {
     IM1 = II1[i];
     T1 = i*0.01;
     }
    
    
   }

   //Arrays de ceros
   double ss2[N];
   double II2[N];
   
   for (int i = 0; i < N; i++) {
       ss2[i] = 0;
       II2[i] = 0;
   }

   II2[0] = I0;
   ss1[0] = s0;

   II2[1] = II2[0] + h*func_primeI(II1[0],ss2[0],B2,g2);
   ss2[1] = ss2[0] + h*func_primeS(II1[0],ss2[0],B2);
    double IM2 = 0;
    double T2 = 0;
   for (int i = 2; i < N; i++) {
       II2[i] = II2[i-2] + 2*h*func_primeI(II2[i-1],ss2[i-1],B2,g2);
       ss2[i] = ss2[i-2] + 2*h*func_primeS(II2[i-1],ss2[i-1],B2);
       cout << II2[i] << "," << i*0.01 << endl;
     if(IM2 < II2[i]) {
     IM2 = II2[i];
     T2 = i*0.01;
     }
    
   }

cout << "Caso 1, " << T1<< " Imax " << IM1 << endl;
cout << "Caso 2, " << T2<< " Imax " << IM2 << endl;

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
