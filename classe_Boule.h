#ifndef classe_Trou_h
#define classe_Trou_h
#include<iostream>


// ======================== CLASSE BOULE ===================================================
class Boule
{
private:
    double x, y;
    double vx, vy;
    double rayon;
    static int nb_boules;
    int numero;

public:
    // constructeurs et destructeur
    Boule(double, double, double, double, double, double);
    Boule();
    ~Boule();
    Boule(Boule &); // opérateur de copie

    // geteur et seteur
    double get_x() const { return x; };
    double get_y() const { return y; };
    double get_vx() const { return vx; };
    double get_vy() const { return vy; };
    double get_rayon() const { return rayon; };
    double get_numero() const { return numero; };
    void set_x(double a) { x = a; };
    void set_y(double a) { y = a; };
    void set_vx(double a) { vx = a; };
    void set_vy(double a) { vy = a; };
    void set_rayon(double a) { rayon = a; };
    void set_numero(int a) { numero = a; };
    double get_nb_boules() { return nb_boules; };

    // autres def
    void maj_positions(double);
    void maj_vitesses_choc_mur(Table, double);
    void maj_vitesses_apres_choc(Boule &);
    double distance_avec(Boule);
    double distance_avec(Trou);
    void est_rentrer_dans(Trou);
};

#endif