#include <ncurses.h>
using namespace std;

int main(int argc, char ** argv) {
    
    // initialize the screen
    // sets up memory and clears the screen
    initscr();
    // allow ^C
    cbreak();
    // make ^C appears on scren instead
    // raw();
    // ignore print to screen
    noecho();

    int height, width, start_x, start_y;
    height = 10;
    width = 20;
    start_y = start_x = 10;

    WINDOW * win = newwin(height, width, start_y, start_x);
    // refresh screen after create window
    refresh();
    // create box on window first 0 is char 0 of left/right 
    // and second 0 is char 0 for top/bottom
    // box(win, 0, 0);
    char c = 'g';
    // box(win, (int)c, 104);
    int left,right, top, bottom, tlc, trc, blc, brc;
    left = right = (int)'g';
    top = bottom = (int)'h';
    bottom = (int)' ';
    tlc = trc = blc = brc = (int)'+';
    blc = brc = bottom;
    wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
    // print string on window at (1,1)
    mvwprintw(win,1,1, "this is my box");
    
    // refresh specific window
    wrefresh(win);


    
    // whats for user input, returns int value of that key
    // two times call getch() to ignore CTRL + [CHARACTER] 
    // except CTRL + C
    getch();
    getch();
    
    // deallocates memory and ends ncurses
    endwin();
    return 0;
}