#include<iostream>

// ======================== CLASSE TROU ===================================================
class Trou
{
private:
    double x_trou, y_trou, r;

public:
    double get_x_trou() { return x_trou; };
    double get_y_trou() { return y_trou; };
    double get_r() { return r; };

    Trou(double, double, double);
};