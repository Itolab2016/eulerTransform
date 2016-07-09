//C Kouhei Ito
#include <stdio.h>
#include <math.h>

//以下の関数は変換したい座標をポインタ（変数のアドレス）で渡します。
//変換した結果は渡した変数を上書きした形で返されます。
short eulerTr(double* x, double* y, double* z, double phi, double theta, double psi);//回転の座標変換関数の宣言
short eulerinvTr(double* x, double* y, double* z, double phi, double theta, double psi);//逆回転の座標変換関数の宣言

int main()
{
 double x,y,z;
 double phi, theta, psi;
 
 x=1.0;
 y=2.0;
 z=3.0;
 
 phi   = 60.0 * M_PI/180.0;//sin()等は扱う単位がラジアンなので、解りやすい度からラジアンに変換
 theta = 20.0 * M_PI/180.0;
 psi   = 15.0 * M_PI/180.0;
 
 eulerTr(&x, &y, &z, phi, theta, psi);//&を変数の前につけると変数のアドレスを渡すことができる
 printf("(%f,%f,%f)\n",x,y,z);//変換結果表示
 
 eulerinvTr(&x, &y, &z,phi, theta, psi);
 printf("(%f,%f,%f)\n",x,y,z);
 
}

short eulerTr(double* x, double* y, double* z, double phi, double theta, double psi)
{
 double X, Y, Z;
 
 X=cos(theta)*cos(psi)*(*x)                                + cos(theta)*sin(psi)*(*y)                              - sin(theta)*(*z);
 Y=(sin(phi)*sin(theta)*cos(psi) - cos(phi)*sin(psi))*(*x) + (sin(phi)*sin(theta)*sin(psi)+cos(phi)*cos(psi))*(*y) + sin(phi)*cos(theta)*(*z);
 Z=(cos(phi)*sin(theta)*cos(psi) + sin(phi)*sin(psi))*(*x) + (cos(phi)*sin(theta)*sin(psi)-sin(phi)*cos(psi))*(*y) + cos(phi)*cos(theta)*(*z);
 *x=X;
 *y=Y;
 *z=Z;
 return 0;
}

short eulerinvTr(double* x, double* y, double* z, double phi, double theta, double psi)
{

 double X, Y, Z;
 
 X=cos(theta)*cos(psi)*(*x)                   + (sin(phi)*sin(theta)*cos(psi) - cos(phi)*sin(psi))*(*y) - (cos(phi)*sin(theta)*cos(psi) + sin(phi)*sin(psi))*(*z);


 Y=cos(theta)*sin(psi)*(*x)                  + (sin(phi)*sin(theta)*sin(psi) + cos(phi)*cos(psi))*(*y) + (cos(phi)*sin(theta)*sin(psi)-sin(phi)*cos(psi))*(*z);
 Z=sin(theta)*(*x)                            + sin(phi)*cos(theta)*(*y)                                + cos(phi)*cos(theta)*(*z);
 *x=X;
 *y=Y;
 *z=Z;
 return 0;
}
