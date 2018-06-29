//
// Created by simonppg on 21/03/18.
//

#ifndef BREAK_IT_ALL_SQUARE_H
#define BREAK_IT_ALL_SQUARE_H

#include <GLES3/gl3.h>

typedef struct _Square Square;
Square* Square_new(char* vertex_file_path, char* fragment_file_path, GLfloat *color);
void Square_draw(Square *t);
void Square_update(Square *t);

#endif //BREAK_IT_ALL_SQUARE_H
