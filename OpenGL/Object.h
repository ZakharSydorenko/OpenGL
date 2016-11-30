//
//  Object.h
//  OpenGL
//
//  Created by Zakhar Sydorenko on 30.11.16.
//  Copyright © 2016 Zakhar Sydorenko. All rights reserved.
//

#ifndef OPENGLAPPLICATION_OBJECT_H
#define OPENGLAPPLICATION_OBJECT_H

#include <GLUT/glut.h>
#include "Point.h"

class Object {
public:
    Object() {}
    
    void createTriangleObject(Point *class1, Point *class2, Point *class3) {
        glBegin(GL_TRIANGLES);
        glVertex2d(class1->x, class1->y);
        glVertex2d(class2->x, class2->y);
        glVertex2d(class3->x, class3->y);
        glEnd();
    }
    
    void createQuadObject(Point *class1, Point *class2, Point *class3, Point *class4) {
        glBegin(GL_QUAD_STRIP);
        glVertex2d(class1->x, class1->y);
        glVertex2d(class2->x, class2->y);
        glVertex2d(class3->x, class3->y);
        glVertex2d(class4->x, class4->y);
        glEnd();
    }
};

#endif //OPENGLAPPLICATION_OBJECT_H
