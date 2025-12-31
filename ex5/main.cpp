#include <ncurses.h>
using namespace std;

int main(int argc, char ** argv) {
    
    
    initscr();
    attron(A_STANDOUT);
    printw("This is some text");
    attroff(A_REVERSE);
    
    getch();
    endwin();
    return 0;
}