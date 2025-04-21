#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Shape {
protected:
    double x, y;
    string color;
    double borderThickness;

public:
    Shape(double x = 0, double y = 0, string color = "black", double borderThickness = 1.0)
        : x(x), y(y), color(color), borderThickness(borderThickness) {}

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;

    void getPosition() {
        cout << "Position: (" << x << ", " << y << ")\n";
    }

    void getColor() {
        cout << "Color: " << color << endl;
    }

    void getBorderThickness() {
        cout << "Border Thickness: " << borderThickness << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double x, double y, string color, double radius, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), radius(radius) {}

    void draw() override {
        cout << "Drawing a circle at position (" << x << ", " << y << ") with radius " << radius << "\n";
    }

    double calculateArea() override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double x, double y, string color, double width, double height, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), width(width), height(height) {}

    void draw() override {
        cout << "Drawing a rectangle at position (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double base, height, side1, side2, side3;

public:
    Triangle(double x, double y, string color, double base, double height, double side1, double side2, double side3, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), base(base), height(height), side1(side1), side2(side2), side3(side3) {}

    void draw() override {
        cout << "Drawing a triangle at position (" << x << ", " << y << ") with base " << base << " and height " << height << "\n";
    }

    double calculateArea() override {
        return 0.5 * base * height;
    }

    double calculatePerimeter() override {
        return side1 + side2 + side3;
    }
};

class Polygon : public Shape {
private:
    vector<pair<double, double>> vertices;

public:
    Polygon(double x, double y, string color, vector<pair<double, double>> vertices, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), vertices(vertices) {}

    void draw() override {
        cout << "Drawing a polygon at position (" << x << ", " << y << ") with vertices: ";
        for (auto& vertex : vertices) {
            cout << "(" << vertex.first << ", " << vertex.second << ") ";
        }
        cout << "\n";
    }

    double calculateArea() override {
        double area = 0.0;
        int n = vertices.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            area += vertices[i].first * vertices[j].second;
            area -= vertices[i].second * vertices[j].first;
        }
        area = fabs(area) / 2.0;
        return area;
    }

    double calculatePerimeter() override {
        double perimeter = 0.0;
        int n = vertices.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            perimeter += sqrt(pow(vertices[j].first - vertices[i].first, 2) + pow(vertices[j].second - vertices[i].second, 2));
        }
        return perimeter;
    }
};

int main() {
    Circle circle(4, 2, "orange", 7);
    Rectangle rectangle(0, -3, "teal", 10, 2);
    Triangle triangle(1.5, 1.5, "yellow", 6, 4, 5, 5, 6);
    vector<pair<double, double>> polygonVertices = {{2, 3}, {6, 2}, {7, 6}, {3, 7}};
    Polygon polygon(5, 5, "cyan", polygonVertices);

    circle.draw();
    cout << "Area: " << circle.calculateArea() << ", Perimeter: " << circle.calculatePerimeter() << "\n";

    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << ", Perimeter: " << rectangle.calculatePerimeter() << "\n";

    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << ", Perimeter: " << triangle.calculatePerimeter() << "\n";

    polygon.draw();
    cout << "Area: " << polygon.calculateArea() << ", Perimeter: " << polygon.calculatePerimeter() << "\n";

    return 0;
}

