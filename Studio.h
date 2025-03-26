//
// Created by Vova on 10.03.2025.
//

#ifndef STUDIO_H
#define STUDIO_H

#include <iostream>
#include <vector>
#include "Film.h"

class Studio {
private:
    std::string name;
    int yearFounded;
    std::vector<Film*> films;

public:
    Studio();
    Studio(std::string n, int y);
    Studio(const Studio& other);
    Studio(Studio&& other) noexcept;
    ~Studio();

    void addFilm(Film* f);
    void display() const;
};

#endif // STUDIO_H