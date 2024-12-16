#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <chrono>

void printGreen(const std::string &text) {
    std::cout << "\033[1;32m" << text << "\033[0m";
}

void printYellow(const std::string &text) {
    std::cout << "\033[1;33m" << text << "\033[0m";
}

void printRed(const std::string &text) {
    std::cout << "\033[1;31m" << text << "\033[0m";
}

void printBlue(const std::string &text) {
    std::cout << "\033[1;34m" << text << "\033[0m";
}


void printBanner() {
    printBlue("=====================================\n");
    printGreen("          BOHR MODEL CALCULATOR      \n");
    printBlue("=====================================\n\n");
}

void printMenu() {
    printYellow("\n=====================================\n");
    printBlue("              MAIN MENU              \n");
    printYellow("=====================================\n");
    std::cout << "1 - Calculate Ionization Energy (In)\n";
    std::cout << "2 - Calculate Energy of Electron (En)\n";
    std::cout << "3 - Calculate Energy Difference (DE)\n";
    std::cout << "4 - Calculate Wavelength (Lambda)\n";
    std::cout << "5 - Calculate Orbital Radius (Rn)\n";
    std::cout << "6 - Calculate Number of Waves (v)\n";
    std::cout << "=====================================\n";
    printGreen("Your choice: ");
}

void printResultHeader(const std::string &title) {
    printYellow("\n=====================================\n");
    printBlue("            " + title + "            \n");
    printYellow("=====================================\n");
}

int main() {
    bool running = true;
    while (running) {
        printBanner();
        int choice, n1, n2, z;
        const double h = 6.626e-34;   
        const double c = 3.00e8;       
        const double eV_to_J = 1.602e-19; 
        const double a = 0.53;      
        
        do {
            std::cout << "Enter the principal quantum number n1 (positive integer): ";
            std::cin >> n1;
        } while (n1 <= 0);

        do {
            std::cout << "Enter the principal quantum number n2 (positive integer): ";
            std::cin >> n2;
        } while (n2 <= 0);

        do {
            std::cout << "Enter the atomic number Z (positive integer): ";
            std::cin >> z;
        } while (z <= 0);

        printMenu();
        std::cin >> choice;
        
        double In, En, DE, L, Rn, v;
        
        switch (choice) {
            case 1:
                printResultHeader("IONIZATION ENERGY (In)");
                In = 13.6 * ((z * z) / (n1 * n1));
                std::cout << "Ionization Energy (In): " << std::fixed << std::setprecision(4) << In << " eV\n";
                break;

            case 2:
                printResultHeader("ENERGY OF ELECTRON (En)");
                En = -13.6 * ((z * z) / (n1 * n1));
                std::cout << "Energy of Electron (En): " << std::fixed << std::setprecision(4) << En << " eV\n";
                break;

            case 3:
                printResultHeader("ENERGY DIFFERENCE (DE)");
                if (n1 > n2) {
                    DE = 13.6 * (z * z) * ((1.0 / (n2 * n2)) - (1.0 / (n1 * n1)));
                    std::cout << "Energy Difference (DE): " << std::fixed << std::setprecision(4) << DE << " eV\n";
                } else {
                    printRed("Error: n1 must be greater than n2.\n");
                }
                break;

            case 4:
                printResultHeader("WAVELENGTH (LAMBDA)");
                if (n1 > n2) {
                    DE = 13.6 * (z * z) * ((1.0 / (n2 * n2)) - (1.0 / (n1 * n1)));
                    L = (h * c) / (DE * eV_to_J);
                    std::cout << "Wavelength (Lambda): " << std::fixed << std::setprecision(2) << L * 1e9 << " nm\n";
                } else {
                    printRed("Error: n1 must be greater than n2.\n");
                }
                break;

            case 5:
                printResultHeader("ORBITAL RADIUS (Rn)");
                Rn = a * (n1 * n1) / z;
                std::cout << "Orbital Radius (Rn): " << std::fixed << std::setprecision(4) << Rn << " Å\n";
                break;

            case 6:
                printResultHeader("NUMBER OF WAVES (v)");
                if (n1 > n2) {
                    DE = 13.6 * (z * z) * ((1.0 / (n2 * n2)) - (1.0 / (n1 * n1)));
                    v = DE / h;
                    std::cout << "Number of Waves (v): " << std::fixed << std::setprecision(4) << v << " Hz\n";
                } else {
                    printRed("Error: n1 must be greater than n2.\n");
                }
                break;

            default:
                printRed("Invalid choice. Please select a valid option.\n");
                break;
        }

        printYellow("=====================================\n");
        printGreen("Do you want to perform another calculation? (1 = Yes, 0 = No): ");
        int repeat;
        std::cin >> repeat;
        running = repeat == 1;
        if (running)
       {
         std::cout << "Restarting...\n";
         system("timeout /t 1 >nul");
         std::cout << "\n\n";
        }
    }

    printGreen("\nThank you for using the Bohr Model Calculator! Goodbye!\n");
    return 0;
}
