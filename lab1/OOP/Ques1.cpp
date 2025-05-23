#include <iostream>
#include <cmath>

class Point {
    private:
        double x, y;
    
    public:
        Point() {
            x = 0;
            y = 0;
        }
    
        Point(double x, double y) {
            this->x = x;
            this->y = y;
        }
    
        void setX(double x) {
            this->x = x;
        }
    
        void setY(double y) {
            this->y = y;
        }
    
        double getX() const {
            return this->x;
        }
    
        double getY() const {
            return this->y;
        }
    
        double distanceToPoint(const Point& pointA) {
            return sqrt((this->x - pointA.x) * (this->x - pointA.x) + (this->y - pointA.y) * (this->y - pointA.y));
        }
    };