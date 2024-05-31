#pragma once

#include "curses.h"

extern WINDOW* window;

extern int editorRow;
extern int editorCol;

void init(int width, int height);
bool write();