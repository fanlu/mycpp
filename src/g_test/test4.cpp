#include <iostream>
#include <stdio.h>
using namespace std;
double re(double &i)
 {
i++;
return i;
 }
int main(){
double side=3.0;
 double *pd=&side;
 double &rd=side;
 long edge=5L;
 double lens[4]={2.0,5.0,10.0,12.0};
 double c1=re(side);
 double c2=re(lens[2]);
 double c3=re(rd);
 double c4=re(*pd);
 ///double c5=re(edge);// 将会产生临时变量,函数结束释放
 //double c6=re(lens);//将会产生临时变量,函数结束释放
 //double c7=re(side+7.0);//将会产生临时变量,函数结束释放
 cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
}
