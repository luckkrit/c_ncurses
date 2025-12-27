#include <ncurses.h>
using namespace std;

int main(int argc, char ** argv) {
    
    // initialize the screen
    // sets up memory and clears the screen
    initscr();

    int x, y;
    x = y = 10;
    // moves the cursor to the specified location
    move(y, x);

    // prints a string(const char *) to a window
    printw("Hello World!");

    

    // whats for user input, returns int value of that key
    int c = getch();
    clear();
    
    mvprintw(0,0,"%d",c);
    refresh();
    
    getch();

    // deallocates memory and ends ncurses
    endwin();
    return 0;
}