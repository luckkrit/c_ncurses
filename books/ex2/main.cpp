#include <ncurses.h>
#include <string.h>

int main() {
    char *choices[] = {
        "Choice 1: Start Game",
        "Choice 2: Settings",
        "Choice 3: Credits",
        "Choice 4: Exit",
    };
    int n_choices = 4;
    int highlight = 0;
    int choice = -1;
    int c;

    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE); // Enables arrow keys

    while(1) {
        // Draw the menu
        for(int i = 0; i < n_choices; i++) {
            if(i == highlight) 
                attron(A_REVERSE); // Highlight current selection
            
            mvprintw(i + 1, 2, "%s", choices[i]);
            attroff(A_REVERSE);
        }
        refresh();

        c = getch();
        switch(c) {
            case KEY_UP:
                highlight = (highlight == 0) ? n_choices - 1 : highlight - 1;
                break;
            case KEY_DOWN:
                highlight = (highlight == n_choices - 1) ? 0 : highlight + 1;
                break;
            case 10: // Enter key
                choice = highlight;
                break;
            default:
                break;
        }
        if(choice != -1) // User made a selection
            break;
    }

    mvprintw(n_choices + 2, 2, "You chose: %s", choices[choice]);
    refresh();
    getch();
    endwin();

    return 0;
}