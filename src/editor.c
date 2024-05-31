#include "editor.h"

WINDOW* window;

int editorRow;
int editorCol;

void init(int width, int height)
{
    // init variables
    editorRow = 0;
    editorCol = 0;


    initscr();

    cbreak();
    noecho();
    keypad(window, true);

    window = newwin(height, width, 0, 0);
    box(window, 0, 0);
    wmove(window, 1, 1);
    wrefresh(window);
}

bool write()
{
    int c = wgetch(window);

    switch (c)
    {
    case KEY_ESCAPE:
        return false;
        break;

    case KEY_BACKSPACE:
        if (editorRow != 0)
        {
            editorRow--;
            mvwprintw(window, editorCol + 1, editorRow + 1, "%c", ' ');
            wrefresh(window);
        }
        else if (editorCol != 0)
        {
            editorCol--;
            editorRow = 18;
            wmove(window, editorCol + 1, editorRow + 1);
            wrefresh(window);
        }
        break;

    case '\n':
        editorCol++;
        editorRow = 0;
        break;

    default:
        wprintw(window, "%c", c);
        move(editorCol + 1, editorRow + 1);
        wrefresh(window);
        editorRow++;
        break;
    }

    mvwprintw(window, 8, 1, "%d %d", editorRow, editorCol);
    wmove(window, editorCol + 1, editorRow + 1);
    wrefresh(window);

    return true;
}