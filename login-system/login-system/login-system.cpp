#include <iostream>
#include <fstream>
#include <string>

bool isLogged() {
    std::string login, password, storedlogin, storedpassword;

    std::cout << "\n\n";
    std::cout << "IEEJA" << std::endl << "------------------------------" << std::endl;
    std::cout << "Uzraksti loginu: ";
    std::cin >> login;
    std::cout << "Uzraksti paroļu: ";
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
    std::cout << "Ko jus grībetu izdarīt?" << std::endl;
    std::cout << "\nIzvelejaties vienu opciju:\n1. Autorizācija\n2. Registrācija\nLai iziet, uzraksti \"exit\"\n";
    std::cin >> choice;

    if (choice == 1) {
        bool status = isLogged();

        if (status) {
            std::cout << "Jūs ieejāt sistēmā." << std::endl;
            return 1;
        }
        else {
            std::cout << "Nepareizs parolis vai logins. Lūdzu pamēģinajiet vēlreiz." << std::endl;
            main();
        }
    }
    else if (choice == 2) {
        std::string login, password;
        std::cout << "\n\n";
        std::cout << "REGISTRĀCIJA" << std::endl << "------------------------------" << std::endl;
        std::cout << "Uzraksti loginu: ";
        std::cin >> login;
        std::cout << "Uzraksti paroļu: ";
        std::cin >> password;

        std::ofstream read(login + ".txt");
        read << login << std::endl << password;
        read.close();

        std::cout << "\n\n";
        std::cout << "Registrācija ir izpildīta. Jus varētu jāiet ar savu loginu un paroli" << std::endl;

        main();
    }

    return 0;
}