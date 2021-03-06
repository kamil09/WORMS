#ifndef FONT
#define FONT

#include "object.hpp"
#include <freetype2/ft2build.h>
#include FT_FREETYPE_H
// #include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string.h>
#include <glm/glm.hpp>
#include "errorGL.hpp"
#include <map>

class Character {
public:
    Character(GLuint text,glm::ivec2 roz, glm::ivec2 bear, GLuint adv);
    ~Character();
    GLuint textureID;   // ID handle of the glyph texture
    glm::ivec2 size;    // Size of glyph
    glm::ivec2 bearing;  // Offset from baseline to left/top of glyph
    GLuint advance;    // Horizontal offset to advance to next glyph
};

class Font : public Object{
public:
    Font(){};
    Font(const char *ttf, int size);
    Font(const char *ttf, int size, glm::mat4 projection);
    int rozmiar;
    const char* file;
    glm::vec3 kolor;
    FT_Library ft;
    FT_Face face;
    glm::mat4 projection = glm::mat4(1);
    glm::mat4 view= glm::mat4(1);
    std::map<GLchar, Character*> mapCharacters;
    void initChar(const char *ttf, int size);
    void initChar3D(const char *ttf, int size, glm::mat4 projection);
    void setRozmiar(int roz);
    void paramText2D() override;
    void bindBuffers();
    float skalax;
    float skalay;
    void print(std::string text, float x, float y,GLfloat scale,glm::vec3 color);
    void print3d(std::string text, float x, float y,GLfloat scale,glm::vec3 color);
    void print(std::string text, float x, float y,GLfloat scale);
    float length(std::string text,GLfloat scale);
    float height(GLfloat scale);
    void start(int size);
};


#endif
