#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


inline float f(float x) {
  return sin(x) - 1.0 / x;
}

int main() {
  float a = 2, b = 1, e = 0.000001, steps = 0;

  cout << "Enter two inital guesses." << endl;
  cin >> a >> b;

  cout << "Enter tolerable error." << endl;
  cin >> e;
  
  if (f(a) * f(b) > 0) {
    cout << "Your two inital guesses has same sign of their corresponding function. " << endl;
    exit(1);
  }

  if(f(a) > f(b)) {
    float temp;
    temp = a;
    a = b;
    b = temp;
  }

  float c;

  cout << "\t\t" << "steps" << "\t" << "a" << "\t" << "b" << "\t" << "c" << "\t" << "f(c)" << endl;
  do { 
    c = (b * f(a) - a * f(b)) / (f(a) - f(b));
    steps++;
    cout << "\t\t" << steps << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << endl;
    if( f(c) > 0) {
      b = c;
    } else if ( f(c) < 0) {
      a = c;
    }
  } while(fabs(f(c)) > e); // here fabs is the absolute value function

  cout << "Result = " << c << endl;
  return 0;
}