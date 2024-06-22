#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "classe_Table.h"
#include "classe_Trou.h"
#include "classe_Boule.h"

using namespace std;

// ======================== FONCTION PRINCIPALE ===================================================
int main()
{
    ofstream fichier("positions.txt");

    double h = 0.001 / 2;
    int n = 16.0;

    Boule *tableau_boules = new Boule[n];
    Table table(0, 10, 0, 10);
    Trou t1(0, 0, 0.3);
    Trou t2(10, 0, 0.3);
    Trou t3(0, 5, 0.3);
    Trou t4(10, 5, 0.3);
    Trou t5(0, 10, 0.3);
    Trou t6(10, 10, 0.3);

    tableau_boules[0] = Boule(5, 1, -20, 350 * 2, 0.2, 1); // boule blanche

    // initialisation des différentes boules

    double j = 0;
    double k = 0;
    double l = 0;
    double m = 0;

    for (int i = 1; i < tableau_boules->get_nb_boules(); i++) // ca c'est une boucle pour placer les boules (j'avoue je me suis un peu compliqué la vie...)
    {
        tableau_boules[i].set_rayon(0.2);
        tableau_boules[i].set_vx(0);
        tableau_boules[i].set_vy(0);
        tableau_boules[i].set_numero(i + 1);

        if (i <= 5)
        {
            tableau_boules[i].set_x(4 + j);
            tableau_boules[i].set_y(8);
            j += 0.45;
        }
        if (i > 5 and i <= 9)
        {
            tableau_boules[i].set_x(4.2 + k);
            tableau_boules[i].set_y(7.5);
            k += 0.45;
        }
        if (i > 9 and i <= 12)
        {
            tableau_boules[i].set_x(4.4 + l);
            tableau_boules[i].set_y(7);
            l += 0.45;
        }
        if (i > 12 and i <= 14)
        {
            tableau_boules[i].set_x(4.6 + m);
            tableau_boules[i].set_y(6.5);
            m += 0.45;
        }
        if (i == 15)
        {
            tableau_boules[i].set_x(4.8);
            tableau_boules[i].set_y(6);
        }
    }

    for (int m = 0; m < 1000; m++)
    {
        for (int i = 0; i < tableau_boules->get_nb_boules(); i++)
        {
            fichier << tableau_boules[i].get_x() << "   " << tableau_boules[i].get_y() << "   ";
            tableau_boules[i].maj_positions(h);
            tableau_boules[i].maj_vitesses_choc_mur(table, h);

            tableau_boules[i].est_rentrer_dans(t1);
            tableau_boules[i].est_rentrer_dans(t2);
            tableau_boules[i].est_rentrer_dans(t3);
            tableau_boules[i].est_rentrer_dans(t4);
            tableau_boules[i].est_rentrer_dans(t5);
            tableau_boules[i].est_rentrer_dans(t6);
        }
        for (int k = 0; k < tableau_boules->get_nb_boules(); k++)
        {
            for (int j = k + 1; j < tableau_boules->get_nb_boules(); j++)
            {
                tableau_boules[k].maj_vitesses_apres_choc(tableau_boules[j]);
                // cout << k << "  " << j << endl;
            }
        }

        fichier << endl
                << endl
                << endl;
    }

    //system("gnuplot billard.gnu");

    fichier.close();
    delete[] tableau_boules;
    return 0;
}