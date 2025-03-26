//
// Created by Vova on 10.03.2025.
//

#include "Studio.h"

Studio::Studio() : name("Unknown Studio"), yearFounded(1900) {}

Studio::Studio(std::string n, int y) : name(n), yearFounded(y) {}

Studio::Studio(const Studio& other) : name(other.name), yearFounded(other.yearFounded) {
    for (const auto& film : other.films) {
        films.push_back(new Film(*film));
    }
}


Studio::Studio(Studio&& other) noexcept
    : name(std::move(other.name)), yearFounded(other.yearFounded), films(std::move(other.films)) {
    other.films.clear();
}


Studio::~Studio() {
    for (auto film : films) {
        delete film;
    }
    std::cout << "Studio " << name << " has been deleted.\n";
}


void Studio::addFilm(Film* f) {
    films.push_back(f);
}


void Studio::display() const {
    std::cout << "Studio: " << name << ", Founded in " << yearFounded << "\nFilms:\n";
    for (const auto& film : films) {
        film->display();
    }
}