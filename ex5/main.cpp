#include <ncurses.h>
using namespace std;

int main(int argc, char ** argv) {

    initscr();
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_WHITE);
    /*
 * A_NORMAL
 * A_STANDOUT
 * A_REVERSE
 * A_BLINK
 * A_DIM
 * A_BOLD
 * A_PROTECT
 * A_INVIS
 * A_ALTCHARSET
 * A_CHARTEXT
 */

attron(COLOR_PAIR(1) | A_BLINK);
printw("This is some text");
attroff(COLOR_PAIR(1) | A_BLINK);
/*
 * COLOR_PAIR(n)
 * COLOR_BLACK   0
 * COLOR_RED     1
 * COLOR_GREEN   2
 * COLOR_YELLOW  3
 * COLOR_BLUE    4
 * COLOR_MAGENTA 5
 * COLOR_CYAN    6
 * COLOR_WHITE   7
 */
    getch();
    endwin();
    return 0;
}