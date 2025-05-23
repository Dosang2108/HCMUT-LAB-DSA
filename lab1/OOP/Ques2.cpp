#include <iostream>
#include <cmath>

using namespace std;

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
    
    class Circle
    {
    private:
        Point center;
        double radius;
    
    public:
        Circle()
        {
            /*  
             * STUDENT ANSWER   
             * TODO: set zero center's x-y and radius
             */
             this->center.setX(0);
             this->center.setY(0);
             this->radius=0;
        }
    
        Circle(Point center, double radius)
        {
            /*  
             * STUDENT ANSWER
             */
             this->center=center;
             this->radius=radius;
        }
    
        Circle(const Circle &circle)
        {
            /*  
             * STUDENT ANSWER
             */
             this->center = circle.center;
            this->radius = circle.radius;
        }
        
        void setCenter(Point point)
        {
            /*  
             * STUDENT ANSWER
             */
             this->center=point;
        }
    
        void setRadius(double radius)
        {
            /*  
             * STUDENT ANSWER
             */
             this->radius=radius;
        }
    
        Point getCenter() const
        {
            /*  
             * STUDENT ANSWER
             */
             return this->center;
        }
    
        double getRadius() const
        {
            /*  
             * STUDENT ANSWER
             */
             return this->radius;
        }
        
        void printCircle()
        {
            printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
        }
    };