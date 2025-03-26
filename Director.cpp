//
// Created by Vova on 10.03.2025.
//

#include "Director.h"


Director::Director() : name("Unknown"), birthdate("01.01.1970") {}

Director::Director(std::string n, std::string b) : name(n), birthdate(b) {}


Director::Director(const Director& other) : name(other.name), birthdate(other.birthdate) {
    for (const auto& film : other.films) {
        films.push_back(new Film(*film));
    }
}

Director::Director(Director&& other) noexcept
    : name(std::move(other.name)), birthdate(std::move(other.birthdate)), films(std::move(other.films)) {
    other.films.clear();
}


Director::~Director() {
    for (auto film : films) {
        delete film;
    }
    std::cout << "Director " << name << " has been deleted.\n";
}


void Director::addFilm(Film* f) {
    films.push_back(f);
}


void Director::display() const {
    std::cout << "Director: " << name << ", Birthdate: " << birthdate << "\nFilms:\n";
    for (const auto& film : films) {
        film->display();
    }
}