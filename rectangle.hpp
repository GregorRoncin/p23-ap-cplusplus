#include "shape_prof.hpp"
#include <iostream>
#pragma once

// Déclaration de la classe Rectangle dérivée de la classe Shape
class Rectangle : public Shape
{
private:
    int longueur;
    int hauteur;

public:
    // Constructeur de la classe Rectangle
    Rectangle(int x, int y, int longueur, int hauteur, int color = 230)
        : Shape(x, y, color), 
        longueur(longueur), hauteur(hauteur)
    {
    }

    // Implémentation de area() pour le Rectangle
    float area() const 
    {
        return longueur * hauteur;
    }
};

