//
// Created by Vova on 10.03.2025.
//

#include "Film.h"

Film::Film() : title("Unknown"), genre("Unknown"), year(0), rating(0.0) {}

Film::Film(std::string t, std::string g, int y, double r) : title(t), genre(g), year(y), rating(r) {}

Film::Film(std::string t, std::string g) : Film(t, g, 2000, 5.0) {}

Film::~Film() {
    std::cout << "Film \"" << title << "\" has been deleted.\n";
}

void Film::display() const {
    std::cout << "Title: " << title << ", Genre: " << genre << ", Year: " << year << ", Rating: " << rating << std::endl;
}