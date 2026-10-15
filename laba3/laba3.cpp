/**************************
 * Author: Ivanova Ksenia *
 * Variant: 7             *
 * Name: Laba 2           *
 **************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  const double g = 9.81;   // Gravity acceleration (m/s^2)
  double d;                // Pipe diameter (m)
  double v;                // Velocity (m/s)
  double Fr;               // Froude number
  double phi;              // Gas saturation coefficient

  double frThreshold = 50.0;// Froude number threshold for formula selection

  double coeffLow = 0.05;   // Coefficient for Fr < 50
  double expLow = 0.2;      // Exponent for Fr < 50
  double coeffHigh = 0.35;  // Coefficient for Fr >= 50
  double expHigh = 0.1;     // Exponent for Fr >= 50
  int precisionValue = 4;   // Number of decimal places for output
  int velocityCount = 6;    // Number of velocities to process (from task)

  cout << "Enter pipe diameter d (m): ";
  cin >> d;

  cout << "----------------------------------------\n";
  cout << "  v (m/s)         Fr            phi\n";
  cout << "----------------------------------------\n";
  cout << fixed << setprecision(precisionValue);

  for (int stepIndex = 0; stepIndex < velocityCount; ++stepIndex) {
      cout << "Enter velocity v (m/s): ";
      cin >> v;

      Fr = (v * v) / (g * d);

      if (Fr < frThreshold) {
          phi = coeffLow * pow(Fr, expLow);
      }
      else {
          phi = coeffHigh * pow(Fr, expHigh);
      }

      cout << setw(10) << v
           << setw(15) << Fr
           << setw(15) << phi << "\n";
  }
  
  cout << "----------------------------------------\n";

  return 0;
}