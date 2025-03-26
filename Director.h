//
// Created by Vova on 10.03.2025.
//

#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <iostream>
#include <vector>
#include "Film.h"

class Director {
private:
    std::string name;
    std::string birthdate;
    std::vector<Film*> films;

public:
    Director();
    Director(std::string n, std::string b);
    Director(const Director& other);
    Director(Director&& other) noexcept;
    ~Director();


    void addFilm(Film* f);
    void display() const;
};

#endif // DIRECTOR_H