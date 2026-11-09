#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  cout << "PACKAGE WEIGHT TRACKER\n";
  cout << "---------------------\n";

  int numPackages = 0;

  while (cout << "How many packages? " && !(cin >> numPackages) || numPackages <= 0) {
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Invalid input. Please enter a positive integer greater than 0.\n";
  }

  double* weights = new double[numPackages];

  for (int i = 0; i < numPackages; ++i) {
    while (true) {
      cout << "Enter weight for package " << (i + 1) << ": ";
      
      if (cin >> weights[i] && weights[i] > 0) {
        cin.ignore(10000, '\n'); 
        break; 
      } else {
        cout << "Invalid weight. Must be a number greater than 0.\n";
        cin.clear();              
        cin.ignore(10000, '\n');  
      }
    }
  }

  double totalWeight = 0.0;
  double heaviestPackage = weights[0];

  for (int i = 0; i < numPackages; ++i) {
    totalWeight += weights[i];
    if (weights[i] > heaviestPackage) {
      heaviestPackage = weights[i];
    }
  }

  double averageWeight = totalWeight / numPackages;

  cout << fixed << setprecision(2);
  cout << "\nPACKAGE SUMMARY\n";
  for (int i = 0; i < numPackages; ++i) {
    cout << "Package " << (i + 1) << ": " << weights[i] << " lbs\n";
  }

  cout << "\nTotal Weight: " << totalWeight << " lbs\n";
  cout << "Average Weight: " << averageWeight << " lbs\n";
  cout << "Heaviest Package: " << heaviestPackage << " lbs\n";

  weights = nullptr;

  return 0;

}
