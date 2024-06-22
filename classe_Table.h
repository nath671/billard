#include<iostream>

// ======================== CLASSE TABLE ===================================================
class Table
{
private:
    double xmin, xmax;
    double ymin, ymax;

public:
    // constructeur
    Table(double, double, double, double);

    // geteur
    double get_xmin() { return xmin; };
    double get_xmax() { return xmax; };
    double get_ymin() { return ymin; };
    double get_ymax() { return ymax; };
};