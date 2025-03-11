//
// Created by Vova on 10.03.2025.
//

#include "Director.h"

Director::Director() : name("Unknown"), birthdate("01.01.1970") {}

Director::Director(std::string n, std::string b) : name(n), birthdate(b) {}

Director::~Director() {
    std::cout << "Director " << name << " has been deleted.\n";
}

void Director::addFilm(Film* f) {  // Зберігаємо вказівник
    films.push_back(f);
}

void Director::display() const {
    std::cout << "Director: " << name << ", Birthdate: " << birthdate << "\nFilms:\n";
    for (const auto& film : films) {
        film->display();  // Викликаємо через вказівник
    }
}
