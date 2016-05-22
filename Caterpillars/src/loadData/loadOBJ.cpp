#include "loadOBJ.hpp"

/*
 * Blender:
 * OBJ + triangulate faces + not write materials + include UVs + inpude Nurmals
 * 
 */
bool loadObj::load(char * path,std::vector<GLfloat> vertices, std::vector<GLuint> indices){
   FILE * file = fopen(path, "r");
   if( file == NULL ){
      printf("Impossible to open the file !\n");
      return false;
   }
   std::vector<GLfloat> tex;
   std::vector<GLfloat> ver;
   std::vector<GLfloat> nor;
   int verNum=0;
   int texNum=0;
   int norNum=0;
   while( 1 ){
      char lineHeader[128];
      int res = fscanf(file, "%s", lineHeader);
      if (res == EOF) break;

      if ( strcmp( lineHeader, "v" ) == 0 ){
         float tmp [3];
         fscanf(file, "%f %f %f\n", &tmp[0], &tmp[1], &tmp[2] );
         ver.push_back(tmp[0]);
         ver.push_back(tmp[1]);
         ver.push_back(tmp[2]);
         verNum++;
      }
      else if ( strcmp( lineHeader, "vt" ) == 0 ){
         float tmp [2];
         fscanf(file, "%f %f\n", &tmp[0], &tmp[1] );
         tex.push_back(tmp[0]);
         tex.push_back(tmp[1]);
         texNum++;
      }
      else if ( strcmp( lineHeader, "vn" ) == 0 ){
         float tmp [3];
         fscanf(file, "%f %f %f\n", &tmp[0], &tmp[1], &tmp[2] );
         nor.push_back(tmp[0]);
         nor.push_back(tmp[1]);
         nor.push_back(tmp[2]);
         norNum++;
      }
      else if ( strcmp( lineHeader, "f" ) == 0 ){
         std::string vertex1, vertex2, vertex3;
         unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
         int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
         if (matches != 9){
              printf("File can't be read by our simple parser : ( Try exporting with other options\n");
              return false;
         }
         indices.push_back(vertexIndex[0]);
         indices.push_back(vertexIndex[1]);
         indices.push_back(vertexIndex[2]);
         // uvIndices    .push_back(uvIndex[0]);
         // uvIndices    .push_back(uvIndex[1]);
         // uvIndices    .push_back(uvIndex[2]);
         // normalIndices.push_back(normalIndex[0]);
         // normalIndices.push_back(normalIndex[1]);
         // normalIndices.push_back(normalIndex[2]);
      }
   }
   for(int i=0;i<verNum;i++){
      vertices.push_back(ver[i*3]);
      vertices.push_back(ver[i*3+1]);
      vertices.push_back(ver[i*3+2]);
      if(i<texNum){
         vertices.push_back(tex[i*2]);
         vertices.push_back(tex[i*2+1]);
      }
      else{
         vertices.push_back(0.0f);
         vertices.push_back(0.0f);
      }
   }




   return true;
}
