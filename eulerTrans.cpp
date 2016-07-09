#include <stdio.h>
#include <math.h>

short eulerTr(double* x, double* y, double* z, double phi, double theta, double psi);
short eulerinvTr(double* x, double* y, double* z, double phi, double theta, double psi);


int main()
{
 double x,y,x;
 double phi, theta, psi;
 
 x=1.0;
 y=2.0;
 z=3.0;
 
 eulerTr(x, y, z, phi, theta, psi);
 printf("%f,%f,%f",x,y,z);
 
 eulerinvTr(x, y, z,phi, theta, psi);
 printf("%f,%f,%f",x,y,z);
 
}

short eulerTr(double* x, double* y, double* z, double phi, double theta, double psi)
{
  
}

short eulerinvTr(double* x, double* y, double* z, double phi, double theta, double psi)
{

}
