//
// Created by Vova on 10.03.2025.
//

#include "Film.h"

int Film::filmCount = 0;


Film::Film() : title("Unknown"), genre("Unknown"), year(0), rating(0.0) {
    filmCount++;
}

Film::Film(std::string t, std::string g, int y, double r)
    : title(t), genre(g), year(y), rating(r) {
    filmCount++;
}

Film::Film(std::string t, std::string g) : Film(t, g, 2000, 5.0) {}

Film::Film(const Film& other)
    : title(other.title), genre(other.genre), year(other.year), rating(other.rating) {
    filmCount++;
}

Film::Film(Film&& other) noexcept
    : title(std::move(other.title)), genre(std::move(other.genre)),
      year(other.year), rating(other.rating) {
    other.year = 0;
    other.rating = 0.0;
}

Film::~Film() {
    filmCount--;
    std::cout << "Film \"" << title << "\" has been deleted.\n";
}


Film Film::operator+(const Film& other) const {
    return Film(title + " & " + other.title, genre, (year + other.year) / 2, (rating + other.rating) / 2);
}


Film& Film::operator=(const Film& other) {
    if (this != &other) {
        title = other.title;
        genre = other.genre;
        year = other.year;
        rating = other.rating;
    }
    return *this;
}

bool Film::operator!() const {
    return rating < 5.0;
}

void Film::display() const {
    std::cout << "Title: " << this->title << ", Genre: " << this->genre
              << ", Year: " << this->year << ", Rating: " << this->rating << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Film& f) {
    os << f.title << " (" << f.year << ") - " << f.genre << ", Rating: " << f.rating;
    return os;
}

std::istream& operator>>(std::istream& is, Film& f) {
    std::cout << "Enter title: ";
    is >> f.title;
    std::cout << "Enter genre: ";
    is >> f.genre;
    std::cout << "Enter year: ";
    is >> f.year;
    std::cout << "Enter rating: ";
    is >> f.rating;
    return is;
}


int Film::getFilmCount() {
    return filmCount;
}