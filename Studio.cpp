//
// Created by Vova on 10.03.2025.
//

#include "Studio.h"

Studio::Studio() : name("Unknown Studio"), yearFounded(1900) {}

Studio::Studio(std::string n, int y) : name(n), yearFounded(y) {}

Studio::~Studio() {
    std::cout << "Studio " << name << " has been deleted.\n";
}

void Studio::addFilm(Film* f) {  // Зберігаємо вказівник
    films.push_back(f);
}

void Studio::display() const {
    std::cout << "Studio: " << name << ", Founded in " << yearFounded << "\nFilms:\n";
    for (const auto& film : films) {
        film->display();  // Викликаємо через вказівник
    }
}