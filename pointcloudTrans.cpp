//(C) Kouhei Ito, Kanazawa Tecnical College JAPAN
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//以下で宣言される関数は変換したい座標をポインタ（変数のアドレス）で渡します。
//変換した結果は渡した変数を上書きした形で返されます。
short eulerTr(double* x, double* y, double* z, double phi, double theta, double psi);//回転の座標変換関数の宣言
short eulerinvTr(double* x, double* y, double* z, double phi, double theta, double psi);//逆回転の座標変換関数の宣言

int main()
{
  short i;
  double x,y,z,k;
  double phi, theta, psi;
 
  x=1.0;
  y=2.0;
  z=3.0;
 
  phi   = 60.0 * M_PI/180.0;             //sin()等は扱う単位がラジアンなので、解りやすい度からラジアンに変換
  theta = 20.0 * M_PI/180.0;
  psi   = 15.0 * M_PI/180.0;
  
  k=1.0;

  for (i=0;i<10000;i++)
  {
    x = 2.0*k*(rand()/(RAND_MAX+1.0)-0.5);
    y = 2.0*k*(rand()/(RAND_MAX+1.0)-0.5);
    z = 2.0*k*(rand()/(RAND_MAX+1.0)-0.5);
    printf("%f %f %f ",x,y,z);
    eulerTr(&x, &y, &z, phi, theta, psi);
    printf("%f %f %f\n",x,y,z);
  }

}

//ここから関数の定義
short eulerTr(double* x, double* y, double* z, double phi, double theta, double psi)
{
  double X, Y, Z;
 
  X = cos(theta)*cos(psi)*(*x)                                + cos(theta)*sin(psi)*(*y)                              - sin(theta)*(*z);
  Y = (sin(phi)*sin(theta)*cos(psi) - cos(phi)*sin(psi))*(*x) + (sin(phi)*sin(theta)*sin(psi)+cos(phi)*cos(psi))*(*y) + sin(phi)*cos(theta)*(*z);
  Z = (cos(phi)*sin(theta)*cos(psi) + sin(phi)*sin(psi))*(*x) + (cos(phi)*sin(theta)*sin(psi)-sin(phi)*cos(psi))*(*y) + cos(phi)*cos(theta)*(*z);
  *x = X;
  *y = Y;
  *z = Z;
  return 0;
}

short eulerinvTr(double* x, double* y, double* z, double phi, double theta, double psi)
{
  double X, Y, Z;
 
  X = cos(theta)*cos(psi)*(*x) + (sin(phi)*sin(theta)*cos(psi) - cos(phi)*sin(psi))*(*y) + (cos(phi)*sin(theta)*cos(psi) + sin(phi)*sin(psi))*(*z);
  Y = cos(theta)*sin(psi)*(*x) + (sin(phi)*sin(theta)*sin(psi) + cos(phi)*cos(psi))*(*y) + (cos(phi)*sin(theta)*sin(psi) - sin(phi)*cos(psi))*(*z);
  Z =-sin(theta)*(*x)          + sin(phi)*cos(theta)*(*y)                                + cos(phi)*cos(theta)*(*z);
  *x = X;
  *y = Y;
  *z = Z;
  return 0;
}
