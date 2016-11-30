//
//  main.cpp
//  OpenGL
//
//  Created by Zakhar Sydorenko on 30.11.16.
//  Copyright © 2016 Zakhar Sydorenko. All rights reserved.
//

#include <GLUT/glut.h>
#include "Point.h"
#include "Object.h"
#include <vector>

using namespace std;

#define windowWidth 200
#define windowHeight 350
#define size 16

Object *object = new Object();



vector<Point*> kangaroo(size); // вектор для кенгуру
vector<Point*> last(size); // для ноги

Point *horizontalVector = new Point(2, 0);
Point *verticalVector = new Point(0, 2);



void initialize() { // наши точки
    for (int i=0; i<size; i++) {
        kangaroo[i] = new Point();
        last[i] = new Point();
    }
    
    kangaroo[0]->setPoint(90, 310);
    kangaroo[1]->setPoint(130, 310);
    kangaroo[2]->setPoint(110, 340);
    kangaroo[3]->setPoint(110, 310);
    kangaroo[4]->setPoint(110, 290);
    kangaroo[5]->setPoint(130, 290);
    kangaroo[6]->setPoint(130, 270);
    kangaroo[7]->setPoint(90, 270);
    kangaroo[8]->setPoint(110, 250);
    kangaroo[9]->setPoint(150, 290);
    kangaroo[10]->setPoint(190, 250);
    kangaroo[11]->setPoint(170, 250);
    kangaroo[12]->setPoint(170, 170);
    kangaroo[13]->setPoint(160, 200);
    kangaroo[14]->setPoint(190, 150);
    kangaroo[15]->setPoint(160, 120);
    last[0]->setPoint(170, 130);
    last[1]->setPoint(170, 100);
    last[2]->setPoint(140, 100);
    
    
}



void createKangaroo()// метод для открисовки зверя
{
    glColor3f(1.0, 1.0, 0.0);
    
    object->createTriangleObject(kangaroo[0], kangaroo[1], kangaroo[2]);
    object->createQuadObject(kangaroo[3], kangaroo[1], kangaroo[4], kangaroo[5]);
    object->createTriangleObject(kangaroo[4], kangaroo[5], kangaroo[6]);
    object->createQuadObject(kangaroo[4], kangaroo[6], kangaroo[7], kangaroo[8]);
    object->createTriangleObject(kangaroo[8], kangaroo[9], kangaroo[10]);
    object->createTriangleObject(kangaroo[8], kangaroo[11], kangaroo[12]);
    object->createTriangleObject(kangaroo[13], kangaroo[14], kangaroo[15]);
    object->createTriangleObject(last[0], last[1], last[2]);
    
    
}

void transport(double vectX, double vectY) // метод для перемещения
{
    Point *transportVector = new Point(vectX, vectY);
    for (int i=0; i<16; i++) {
        kangaroo[i] = kangaroo[i]->sum(transportVector);
        last[i] = last[i]->sum(transportVector);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // чистим экран
    createKangaroo(); // создаем зверя
    glutSwapBuffers(); // меняем буферы
}

void reshape(int w, int h) // метод для того, что бы изображение оставалось стабильным, если изменять размер экрана
{
    glViewport(0, 0, w, h); // перестройка окна с другими размерами
    glMatrixMode(GL_PROJECTION); // сообщает что команды относятся к проэкту
    glLoadIdentity(); // считывает текущую матрицу
    gluOrtho2D(0, w, 0, h); // определение проекции
    
}

void move(int Key, int x, int y) // метод для перемещения объекта
{
    switch (Key)
    {
        case GLUT_KEY_RIGHT:
            transport(horizontalVector->x, horizontalVector->y);
            break;
        case GLUT_KEY_LEFT:
            transport(-horizontalVector->x, -horizontalVector->y);
            break;
        case GLUT_KEY_UP:
            transport(verticalVector->x, verticalVector->y);
            break;
        case GLUT_KEY_DOWN:
            transport(-verticalVector->x, -verticalVector->y);
            break;
        default:
            break;
    }
    glutPostRedisplay();
    
}

void erase() { // очистка массивов
    for (int i=0; i<size; i++) {
        delete[] kangaroo[i];
        delete[] last[i];
    }
}

int main(int argc, char **argv)
{
    initialize();
    
    glutInit(&argc, argv);// инизиализация glut
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // создаем 2 окна и цветовую гамму
    glutInitWindowSize(windowWidth, windowHeight); // размер окна
    glutCreateWindow("Sydorenko"); // title
    glClearColor(0.4, 0.1, 0.4, 1.0); // фон
    
    glutReshapeFunc(reshape);
    
    glutSpecialFunc(move);
    glutDisplayFunc(display);
    glutMainLoop(); // бесконечный цыкл, который ждет команд
    
    erase();
}
