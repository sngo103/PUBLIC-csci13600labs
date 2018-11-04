/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Extra Lab 0
Task: Use rotational cipher and letter frequencies to decode encrypted text.
*/

#include <iostream>
#include <string>
#include "caesar.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
  readFrequencies();
  cout << "TESTING ENGLISH =============================================================================================================" << endl;
  string source = "Attack each day with an enthusiasm unknown to mankind and the world and the universe and everything around it.";
  string encoded = encode(source,5);
  string decoded = decode(encoded,freqs);
  cout << source << "\n";
  cout << encoded << "\n";
  cout << decoded << "\n";
  cout << "TESTING ENGLISH =============================================================================================================" << endl;
  source = "this is a test of";
  encoded = encode(source,5);
  decoded = decode(encoded,freqs);
  cout << source << "\n";
  cout << encoded << "\n";
  cout << decoded << "\n";

  readFrequenciesSpanish();
  cout << "TESTING SPANISH =============================================================================================================" << endl;
  source = "La Corte se expedirá antes de fin de año sobre ajuste de jubilaciones y pago de Ganancias de jueces";
  encoded = encode(source,5);
  decoded = decode(encoded,freqs);
  cout << source << "\n";
  cout << encoded << "\n";
  cout << decoded << "\n";
  cout << "TESTING SPANISH =============================================================================================================" << endl;
  source = "Hola, como estas. Yo come tamales y arroz. Es muy deliciouso.";
  encoded = encode(source,5);
  decoded = decode(encoded,freqs);
  cout << source << "\n";
  cout << encoded << "\n";
  cout << decoded << "\n";

  return 0;
}
