//C Kouhei Ito
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
 double X, Y, Z;
 
 X=cos(theta)*cos(psi)*(*x) + cos(theta)*sin(psi)*(*y) - sin(theta)*(*z);
 Y=(sin(phi)*sin(theta)*cos(psi) - cos(phi)*sin(psi))*(*x) + (sin(phi)*sin(theta)*sin(psi)+cos(phi)*cos(psi))*(*y) + sin(phi)*cos(theta)*(*z);
 Z=(cos(phi)*sin(theta)*cos(psi) + sin(phi)*sin(psi))*(*x) + (cos(phi)*sin(theta)*sin(psi)-sin(phi)*cos(psi))*(*y) + cos(phi)*cos(theta)*(*z);
 *x=X;
 *y=Y;
 *z=Z;
}

short eulerinvTr(double* x, double* y, double* z, double phi, double theta, double psi)
{
 *x=0.0;
 *y=0.0;
 *z=0.0;
}
