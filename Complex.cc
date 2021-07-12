#include "Complex.h"  //Including our class declaration
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>      //for pow method

using namespace std;

//Create an object from Complex class
Complex::Complex (double r=0.0, double i=0.0)
{
  real = r;        //real part
  imag= i;         //imaginary part    
}

//Get value of real 
double Complex::get_real() const
{
  return real;
}

//Get value of imag
double Complex::get_imag() const
{
  return imag;
}

//Defining operator+ and overloading to add two objects
const Complex Complex::operator + (const Complex &right) const
{
  Complex temp;

  temp.real = real + right.real;
  temp.imag= imag + right.imag;

  return temp;
}

//Defining operator- and overloading for object subtraction
const Complex Complex::operator - (const Complex &right) const
{
  Complex temp;
  
  temp.real = real - right.real;
  temp.imag = imag - right.imag;

  return temp;
}

//Defining operator* and overloading for object multiplication 
const Complex Complex::operator * (const Complex &right) const
{
  Complex temp;

  temp.real = (real * right.real) - (imag * right.imag) ;
  temp.imag = (real * right.imag) + (imag * right.real); 

  return temp;
}

//Defining operator/ and overloading for object division
const Complex Complex::operator / (Complex const &right) const
{
  Complex temp;

  if((right.real==0) && (right.imag==0)){
    cerr<<"Result is undefined."<<endl;
    exit(-1);
  }
  else{
    temp.real = ((real * right.real) + (imag * right.imag)) / (pow(right.real,2) + pow(right.imag,2));
    temp.imag = ((imag * right.real) - (real * right.imag)) / (pow(right.real,2) + pow(right.imag,2));
  }


  return temp;
}

//Operator overloading for raising power
const Complex Complex::operator ^ (int const &power) const
{
  Complex temp;
  temp.real = real;
  temp.imag = imag;

  double d = temp.real;
  int pow= power;

  if(pow<=0){
    cerr<<"Enter power greater than 0"<<endl;
    exit(-1);
  }

  //multiplying one time on each iteration until pow=1
  while(pow>1) {
    temp.real = (real*temp.real) - (imag*temp.imag);
    temp.imag = (real*temp.imag) + (imag * d);
    pow--;
    d=temp.real;
  }
  
  return temp;
}

//Returning string representation of object
string Complex::to_string()
{
  string s;

  if (imag>=0){
    s= std::to_string(real) + "+" + std::to_string(imag) + "i";
  }
  else{
    s= std::to_string(real) + std::to_string(imag) + "i";
  }
  return s;
}




  

  



  
