//
// Created by Vova on 10.03.2025.
//

#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>

class Film {
private:
    std::string title;
    std::string genre;
    int year;
    double rating;

public:
    Film();
    Film(std::string t, std::string g, int y, double r);
    Film(std::string t, std::string g);
    ~Film();

    void display() const;
};

#endif // FILM_H

