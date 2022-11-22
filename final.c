#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

struct snake{
    int xloc;
    int yloc;
    int head;
};

int main(){
    int up = 1;
    int down = 2;
    int left = 3;
    int right = 4;
    int dir = 4;
    int x, y, xMax, yMax, ch;
    initscr();
        clear();
        x = y = 1;
        xMax = COLS-1;
        yMax = LINES-1;

        //Creates the window
        WINDOW *win = newwin(LINES-1, COLS-1, 1,1);
        // grabs key inputs
        keypad(win,true);
        //turns of blocking
        nodelay(win, TRUE);
        //creates the pit
        box(win,'|','-');

        //creates the snake
        struct snake snakearr[(xMax*yMax)/2];
        for(int i=0;i<5;i++){
            snakearr[i].xloc=i+1;
            snakearr[i].yloc=1;
            if (i == 4)
                snakearr[i].head = 1;
        }
        for(int i=0; i <5; i++){
            mvwaddch(win,snakearr[i].yloc,snakearr[i].xloc,'o');
        }

        wrefresh(win);
        //moves the snake by coping the snakes position from the snake struct in front of it unless it is the head of snake then that will move depending on the key that is pressed
        while(1){
            ch = wgetch(win);
            if(ch == KEY_UP) dir = up;
            else if(ch == KEY_DOWN) dir = down;
            else if(ch == KEY_LEFT) dir = left;
            else if(ch == KEY_RIGHT) dir = right;
            for(int i=0; i <5; i++){
                    mvwaddch(win,snakearr[i].yloc,snakearr[i].xloc,' ');
                }
            if (dir == up){
                for(int i = 0;i<5;i++){
                    if(snakearr[i].head){
                        snakearr[i].yloc--;
                    }
                    else{
                        snakearr[i].xloc = snakearr[i+1].xloc;
                        snakearr[i].yloc = snakearr[i+1].yloc;
                    }
                }
            }
            if (dir == down){
                for(int i = 0;i<5;i++){
                    if(snakearr[i].head){
                        snakearr[i].yloc++;
                    }
                    else{
                        snakearr[i].xloc = snakearr[i+1].xloc;
                        snakearr[i].yloc = snakearr[i+1].yloc;
                    }
                }
            }
            if (dir==left){
                for(int i = 0;i<5;i++){
                    if(snakearr[i].head){
                        snakearr[i].xloc--;
                    }
                    else{
                        snakearr[i].xloc = snakearr[i+1].xloc;
                        snakearr[i].yloc = snakearr[i+1].yloc;
                    }
                }
            }
            if (dir==right){
                for(int i = 0;i<5;i++){
                    if(snakearr[i].head){
                        snakearr[i].xloc++;
                    }
                    else{
                        snakearr[i].xloc = snakearr[i+1].xloc;
                        snakearr[i].yloc = snakearr[i+1].yloc;
                    }
                }
            }
            //prints the snake
            for(int i=0; i <5; i++){
                mvwaddch(win,snakearr[i].yloc,snakearr[i].xloc,'o');
            }
        }
    wrefresh(win);  
    usleep(250000);      
    wrefresh(win);
    endwin();
return 0;
}