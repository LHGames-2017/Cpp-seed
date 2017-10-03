#pragma once

#include <math.h>
#include <cstdint>
#include <string>

class Tile {

public:
    Tile(int x_, int y_, uint8_t content_) : X(x_), Y(y_), Content(content_) {}
    uint8_t Content;
    int X;
    int Y;


};

class Point
{
    int _x;
    int _y;

public:
    int getX() const
    {
        return _x;
    }

    int getY() const
    {
        return _y;
    }

    Point(int x = 0, int y = 0)
    {
        _x = x;
        _y = y;
    }


    Point operator- (const Point& rhs)
    {
        return Point(this->getX() - rhs.getX(), this->getY() - rhs.getY());
    }

    Point operator+ (const Point& rhs)
    {
        return Point(this->getX() + rhs.getX(), this->getY() + rhs.getY());
    }

    static double distance(Point p1, Point p2)
    {
        return sqrt((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
    }

    std::string toString()
    {
        return "{{" + std::to_string(getX()) + ", " + std::to_string(getY()) + "}}";
    }

};

struct PlayerInfo;

