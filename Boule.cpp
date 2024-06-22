#include <iostream>
#include <fstream>
#include <cmath>
#include "classe_Table.h"
#include "classe_Trou.h"
#include "classe_Boule.h"

using namespace std;

int Boule::nb_boules = 0;

double Boule::distance_avec(Trou t)
{
    return sqrt((x - t.get_x_trou()) * (x - t.get_x_trou()) + (y - t.get_y_trou()) * (y - t.get_y_trou()));
}
void Boule::est_rentrer_dans(Trou t)
{
    if (distance_avec(t) <= t.get_r() + rayon - 0.1)
    {
        x = 12; // c'est des coordonnées au pif,
                // c'est juste pour que les boules disparaissent de l'écran quand elles rentrent dans un trou
        y = 5;
    }
}
Boule::Boule(Boule &b) // constructeur de copie
{
    x = b.x;
    y = b.y;
    vx = b.vx;
    vy = b.vy;
    rayon = b.rayon;
    numero = b.numero;
    nb_boules++;
}
Boule::Boule()
{
    x = 0;
    y = 0;
    vx = 0;
    vy = 0;
    rayon = 0;
    numero = 0;
    nb_boules++;
}
Boule::Boule(double a, double b, double c, double d, double e, double f)
{
    x = a;
    y = b;
    vx = c;
    vy = d;
    rayon = e;
    numero = f;
    nb_boules++;
}
Boule::~Boule()
{
    nb_boules--;
}
double Boule::distance_avec(Boule b)
{
    return sqrt((x - b.get_x()) * (x - b.get_x()) + (y - b.get_y()) * (y - b.get_y()));
}
void Boule::maj_positions(double h)
{
    double K = 12; // constante d'amortissement

    vx *= exp(-K * h);
    vy *= exp(-K * h);
    x += vx * h;
    y += vy * h;
}
void Boule::maj_vitesses_choc_mur(Table boite, double h)
{
    if (x + rayon >= boite.get_xmax() or x - rayon <= boite.get_xmin())
    {
        vx = -vx;
    }
    if (y + rayon >= boite.get_ymax() or y - rayon <= boite.get_ymin())
    {
        vy = -vy;
    }
}
void Boule::maj_vitesses_apres_choc(Boule &b)
{
    if (distance_avec(b) <= rayon + b.rayon + 0.001)
    {
        double v1x = vx;
        double v1y = vy;
        double v2x = b.vx;

        vx -= ((((vx - b.vx) * (x - b.x)) + ((vy - b.vy) * (y - b.y))) /
               ((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y))) *
              (x - b.x);
        vy -= ((((v1x - b.vx) * (x - b.x)) + ((vy - b.vy) * (y - b.y))) /
               ((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y))) *
              (y - b.y);

        b.vx -= ((((b.vx - v1x) * (b.x - x)) + ((b.vy - v1y) * (b.y - y))) /
                 ((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y))) *
                (b.x - x);
        b.vy -= ((((v2x - v1x) * (b.x - x)) + ((b.vy - v1y) * (b.y - y))) /
                 ((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y))) *
                (b.y - y);

        if (numero == 0 and b.numero == 2)
        {
            cout << "il y a eu collision entre la boule " << numero << " et " << b.numero << endl;
        }
    }
}