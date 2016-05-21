#ifndef mapCl
#define mapCl

/**
 * Ustawienia mapy i genearatora
*/
const int vertX=1000;
const int vertY=1000;
const int baseHeight=30;
const int minMapHeight=50;
const int maxMapHeight=250;
const int maxHillRadius=400;
const int minHillRadius=50;
const int minHillNum=25;
const int maxHillNum=40;
const int murHeight=600;

#include "../../../object.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "math.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../../inputActions.hpp"

using namespace std;

//MAPA MOŻE BYĆ TYLKO JEDNA :)
class Map : public Object{
private:
   float windForce; //predkosc wiatru [m/s]
   float gravity;   //grawitacja [m/s^2]
   float fogSpeed;  //Prędkość podnoszenia się mgły [m/s] (zamiast wody :) )
   float fogHeight; //Wysokość na jakiej jest mgła
   float air;       //Współczynnik Oporu powietrza Od 0 do 1
   int minHeight;   //wysokość do jakiej można rozwalić teren
   void generateRandomMap();
   void recalculateTriangleMap();
public:
   float **mapVert; //Jedna jednostka - 0,5 metra (1000m x 1000m) wartość w tablicy - wysokość
   float **mapVertFirst;
   Map();
   ~Map();
   void bindBuffers(bool newBuffer);
   Map(const Map &);
   static Map& getInstance();
   void draw(glm::mat4 projection, glm::mat4 modelView);
   void rand();     //Losuje wiatr itp
   void kaboom(float x, float y, float z, float radius);    //Robi kaboom na mapie
   void genTriangleTab();
};

#endif
