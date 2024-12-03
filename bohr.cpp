#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int n, n2, choice;

    std::cout << "*****************************************\n";
    std::cout << "*       BOHR MODEL CALCULATOR           *\n";
    std::cout << "*****************************************\n";
    std::cout << "Choose the operation: \n";
    std::cout << "1 - Calculate Energy Level (En) \n";
    std::cout << "2 - Calculate Radius (Rn) \n";
    std::cout << "3 - Calculate Energy Difference (De), Wavelength, and Inverse Wavelength \n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cout << "\nEnter the value of n: ";
    std::cin >> n;

    switch (choice) {
        case 1: {
            double En = -13.6 / (n * n);
            std::cout << "\n____________________________________\n";
            std::cout << "           ENERGY LEVEL (En)         \n";
            std::cout << "_______________________________________\n";
            std::cout << "For n = " << n << ", the energy level is: " 
                      << std::fixed << std::setprecision(4) << En << " eV\n";
            std::cout << "____________________________________\n\n";
            break;
        }
        
        case 2: {
            double Rn = 0.538 * (n * n);
            std::cout << "\n____________________________________\n";
            std::cout << "           RADIUS (Rn)               \n";
            std::cout << "_______________________________________\n";
            std::cout << "For n = " << n << ", the radius is: " 
                      << std::fixed << std::setprecision(4) << Rn << " A\n";
            std::cout << "____________________________________\n\n";
            break;
        }
        case 3: {
            std::cout << "Enter the value of n2: ";
            std::cin >> n2;
            double De = 13.6 * ((1.0 / (n * n)) - (1.0 / (n2 * n2)));
            const double h = 6.626e-34;
            const double c = 3.00e8;
            double lambda = (h * c) / (De * 1.602e-19);
            double inverse_lambda = 1.0 / lambda;

            std::cout << "\n____________________________________\n";
            std::cout << "           ENERGY DIFFERENCE (De)    \n";
            std::cout << "=____________________________________\n";
            std::cout << "For n1 = " << n << " and n2 = " << n2 << ", the energy difference is: " 
                      << std::fixed << std::setprecision(4) << De << " eV\n\n";

            std::cout << "____________________________________\n";
            std::cout << "           WAVELENGTH (λ)            \n";
            std::cout << "____________________________________\n";
            std::cout << "The wavelength is: " 
                      << std::fixed << std::setprecision(2) << lambda * 1e9 << " nm\n\n";

            std::cout << "____________________________________\n";
            std::cout << "           INVERSE WAVELENGTH (1/λ)  \n";
            std::cout << "____________________________________\n";
            std::cout << "The inverse wavelength is: " 
                      << std::fixed << std::setprecision(4) << inverse_lambda * 1e9 
                      << " nm^-1\n";
            std::cout << "____________________________________\n\n";
            break;
        }

        default:
            std::cout << "\nInvalid choice. Please restart the program and enter 1, 2, or 3.\n";
            break;
    }

    std::cout << "Press Enter to exit...";
    std::cin.ignore(); 
    std::cin.get();
    std::cout << "\nThank you for using the Bohr Model Calculator!\n";
    return 0;
}

