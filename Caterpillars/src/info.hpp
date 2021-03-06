#ifndef INFO
#define INFO

#include "font.hpp"
#include "vector"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string.h>
#include <glm/glm.hpp>
#include "errorGL.hpp"
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.hpp"

class Info {
public:
   Info();
   ~Info();
   Font *font;
   struct sysinfo meminfo;
   std::map<char,Text*> texty;
   bool showFps = true;
   void fps();
   void initFps();
   unsigned int addText(std::string newText,float newX,float newY,float newSkala,char index);
   int nbFrames = 0;
   double lastTime;
   void draw();
   void usage();
   void virtualMemory();
   void physicalMemory();
   void cpu();
   int extractNumber(char *line);
   int getValue(const char* fileDir,const char* text);
};
#endif
