/*@author Deepson Shrestha*/
//Submitted to Professor Matthews

// Complex Class

# include <string>

using namespace std;

class Complex
{ 
 private:
  double real, imag;


 public:

  //Constructor
  Complex (double, double);

  //Accessor functions
  double get_real() const;
  double get_imag() const;
 
  //Overloaded operators
  const Complex operator + (const Complex &) const;
  const Complex operator - (const Complex &) const;
  const Complex operator / (const Complex &) const;
  const Complex operator * (const Complex &) const;
  const Complex operator ^ (const int &) const;

  //method to return string representation of invoking object
  string to_string();
};




  
  
  
