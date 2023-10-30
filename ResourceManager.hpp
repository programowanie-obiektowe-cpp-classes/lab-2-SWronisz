#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
};

#include <iostream>
using namespace std;

class Informer {
public:
    Informer() {
        //std::cout << "Konstruktor" << '\n';
    }
    ~Informer() {
        //std::cout << "Destruktor" << '\n';
    }
};

class Wektor2D {
public:
    static int num_wek;
    Informer inf;
    Wektor2D() {};
    Wektor2D(double wspx, double wspy) {
        x = wspx;
        y = wspy;
        num_wek++;
    }
    ~Wektor2D() { num_wek--; }
    void setX(double X) { x = X; }
    void setY(double Y) { y = Y; }
    int getX() { return x; }
    int getY() { return y; }
    void norm() {
        double  n = sqrt(x * x + y * y);
        cout << n << '\n';
    }
    void print() {
        cout << "x = " << x << '\n';
        cout << "y = " << y << '\n';
    }
    Wektor2D operator+(const Wektor2D& other) {
        return Wektor2D(x + other.x, y + other.y);
    }
    Wektor2D operator*(const Wektor2D& other) {
        return Wektor2D(x * other.x, y * other.y);
    }
    friend ostream& operator<<(ostream& os, const Wektor2D& other);
    static int populacja() {
        return num_wek;
    }

private:
    
    double x;
    double y;
};

int Wektor2D::num_wek = 0;

ostream& operator<<(ostream& os, const Wektor2D& other)
{
    os << other.x << ", " << other.y;
    return os;
}

class Wektor {
public:
    Wektor(int n) : dlugosc{ n } {
        pojemnosc = 20;
        tablica = new double[pojemnosc];
        for (int i = 0; i < n; i++) {
            tablica[i] = 0;
        }
    }
    ~Wektor() {
        delete[] tablica;
    }
    int getdlugosc() {
        return dlugosc;
    };
    int getpojemnosc() {
        return pojemnosc;
    }
    void print() {
        //printf("%d", dlugosc);
        for (int i = 0; i < dlugosc; i++)
        {
            printf("%f \t", tablica[i]);
        }
    }
    void zmienDlugosc(int n) {
        if (n <= pojemnosc && n <= dlugosc) {
            dlugosc = n;
        }
        else if (n <= pojemnosc && n > dlugosc) {
            dlugosc = n;
            for (int i = 0; i < dlugosc; i++)
            {
                tablica[i] = 1;
            }
        }
        else if (n > pojemnosc) {
            double* nowatablica = new double[n];
            for (int i = 0; i < dlugosc; i++)
            {
                nowatablica[i] = tablica[i];
            }
            for (int i = dlugosc; i < n; i++)
            {
                nowatablica[i] = 2.;
            }
            delete[] tablica;
            tablica = nowatablica;
            dlugosc = n;
            pojemnosc = 50;
        }
    }
    double& operator[](int indeks) {
        if (indeks < dlugosc) {
            return tablica[indeks];
        }
        else {
            zmienDlugosc(indeks);
        }
    };
private:
    double* tablica;
    int dlugosc;
    int pojemnosc;
};
