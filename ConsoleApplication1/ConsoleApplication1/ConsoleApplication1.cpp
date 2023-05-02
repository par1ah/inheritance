#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual double getPerimeter() = 0;
    virtual double getArea() = 0;
    virtual string getType() = 0;
};

class Triangle : public Shape {
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    double getPerimeter() {
        return a + b + c;
    }
    double getArea() {
        double p = getPerimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    string getType() {
        return "triangle";
    }
private:
    double a, b, c;
};

class Circle : public Shape {
public:
    Circle(double r) : r(r) {}
    double getPerimeter() {
        return 2 * M_PI * r;
    }
    double getArea() {
        return M_PI * r * r;
    }
    string getType() {
        return "circle";
    }
private:
    double r;
};

class Rectangle : public Shape {
public:
    Rectangle(double a, double b) : a(a), b(b) {}
    double getPerimeter() {
        return 2 * (a + b);
    }
    double getArea() {
        return a * b;
    }
    string getType() {
        return "rectangle";
    }
private:
    double a, b;
};

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string type;
        cin >> type;

        if (type == "triangle") {
            double a, b, c;
            cin >> a >> b >> c;
            Triangle t(a, b, c);
            cout << t.getType() << " " << fixed << setprecision(2) << t.getPerimeter() << " " << t.getArea() << endl;
        }
        else if (type == "circle") {
            double r;
            cin >> r;
            Circle c(r);
            cout << c.getType() << " " << fixed << setprecision(2) << c.getPerimeter() << " " << c.getArea() << endl;
        }
        else if (type == "rectangle") {
            double a, b;
            cin >> a >> b;
            Rectangle r(a, b);
            cout << r.getType() << " " << fixed << setprecision(2) << r.getPerimeter() << " " << r.getArea() << endl;
        }
    }

    return 0;
}