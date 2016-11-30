//
//  Point.h
//  OpenGL
//
//  Created by Zakhar Sydorenko on 30.11.16.
//  Copyright © 2016 Zakhar Sydorenko. All rights reserved.
//

#ifndef OPENGLAPPLICATION_KANGAROO_H
#define OPENGLAPPLICATION_KANGAROO_H


class Point {
    
public:
    double x, y;
    
    Point() {
        x = 0;
        y = 0;
    }
    
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    
    void setPoint(double x, double y) {
        Point::x = x;
        Point::y = y;
    }
    
    Point *sum(Point *P)
    {
        return new Point(P->x + this->x, P->y + this->y);
        
    }
    
};


#endif //OPENGLAPPLICATION_KANGAROO_H
