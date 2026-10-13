/*****************************
 * Lab 3: Loops and Branches *
 * Author: Ivanova           *
 * Group: PI-261	     *
 * Variant: 7		     *
 *****************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  // Input data
  double gravity = 9.81;
  double pipeDiameter = 0.191;
  double froudeThreshold = 50.0;
  double coefficientLow = 0.05;
  double exponentLow = 0.2;
  double coefficientHigh = 0.35;
  double exponentHigh = 0.1;

  double velocityValues[] = { 1.0, 2.0, 5.0, 10.0, 20.0, 50.0 };
  int velocityCount = sizeof(velocityValues) / sizeof(velocityValues[0]);

  // Variables for calculation
  double velocity;
  double froudeNumber;
  double phiValue;

  // Output header
  cout << "----------------------------------------\n";
  cout << "  v (m/s)         Fr            phi\n";
  cout << "----------------------------------------\n";

  // Processing loop
  cout << fixed << setprecision(4);
  for (int velocityIndex = 0; velocityIndex < velocityCount; ++velocityIndex) {
      velocity = velocityValues[velocityIndex];

      // Calculate Froude number
      froudeNumber = (velocity * velocity) / (gravity * pipeDiameter);

      // Select formula based on Froude number
      if (froudeNumber < froudeThreshold) {
          phiValue = coefficientLow * pow(froudeNumber, exponentLow);
      }
      else {
          phiValue = coefficientHigh * pow(froudeNumber, exponentHigh);
      }

      // Output results
      cout << setw(10) << velocity
          << setw(15) << froudeNumber
          << setw(15) << phiValue << "\n";
  }

  cout << "----------------------------------------\n";

  return 0;
}