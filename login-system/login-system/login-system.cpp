#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

bool isLogged() {
    std::string login, password, storedlogin, storedpassword;

    std::cout << "\n\n";
    std::cout << "IEEJA" << std::endl << "------------------------------" << std::endl;
    std::cout << "Uzraksti loginu: ";
    std::cin >> login;
    std::cout << "Uzraksti parolu: ";
    std::cin >> password;

    std::ifstream read(login + ".txt");
    getline(read, storedlogin);
    getline(read, storedpassword);

    if (login == storedlogin && password == storedpassword) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int choice;
    std::cout << "\n*************MENU**********:" << std::endl;
    std::cout << "Ko jus gribetu izdarit?" << std::endl;
    std::cout << "\nIzvelejaties vienu opciju:\n1. Autorizacija\n2. Registracija\nLai iziet, uzspiez jebkuru taustinu\n";
    std::cin >> choice;

    if (choice == 1) {
        system("cls");
        bool status = isLogged();

        if (status) {
            std::cout << " ----------------------------------------------------------------------" << std::endl;
            std::cout << "|                      Jus ieejat sistema.                             |" << std::endl;
            std::cout << " ----------------------------------------------------------------------" << std::endl;
            Sleep(2000);
            return 1;
        }
        else {
            std:: cout << std::endl;
            std::cout << "Nepareizs parolis vai logins. Ludzu pameginajiet velreiz." << std::endl;
            Sleep(2000);
            main();
        }
    }
    else if (choice == 2) {
        system("cls");
        std::string login, password;
        std::cout << "\n\n";
        std::cout << "REGISTRACIJA" << std::endl << "------------------------------" << std::endl;
        std::cout << "Uzraksti loginu: ";
        std::cin >> login;
        std::cout << "Uzraksti paroļu: ";
        std::cin >> password;

        std::ofstream read(login + ".txt");
        read << login << std::endl << password;
        read.close();

        system("cls");
        std::cout << "\n\n";
        std::cout << " --------------------------------------------------------------------" << std::endl;
        std::cout << "|Registracija ir izpildita. Jus varetu jaiet ar savu loginu un paroli|"<< std::endl;
        std::cout << " --------------------------------------------------------------------" << std::endl;
        Sleep(2000);
        system("cls");

        main();
    }

    return 0;
}