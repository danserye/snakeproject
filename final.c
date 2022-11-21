#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

struct snake{
    int xloc;
    int yloc;
    int head;
};

int main(){
    int x, y, xMax, yMax;
    initscr();
        echo();
        x = y = 1;
        xMax = COLS-1;
        yMax = LINES-1;

        //Creates the Snake Pit
        WINDOW *win = newwin(LINES-1, COLS-1, 1,1);
        keypad(win,true);
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
            int ch = wgetch(win);
            switch(ch){
                case KEY_UP:
                    for(int i=0; i <5; i++){
                        mvwaddch(win,snakearr[i].yloc,snakearr[i].xloc,' ');
                    }
                    for(int i = 0;i<5;i++){
                        if(snakearr[i].head){
                            snakearr[i].yloc--;
                        }
                        else{
                            snakearr[i].xloc = snakearr[i+1].xloc;
                            snakearr[i].yloc = snakearr[i+1].yloc;
                        }
                    }
                    break;
                case KEY_DOWN:
                    for(int i=0; i <5; i++){
                        mvwaddch(win,snakearr[i].yloc,snakearr[i].xloc,' ');
                    }
                    for(int i = 0;i<5;i++){
                        if(snakearr[i].head){
                            snakearr[i].yloc++;
                        }
                        else{
                            snakearr[i].xloc = snakearr[i+1].xloc;
                            snakearr[i].yloc = snakearr[i+1].yloc;
                        }
                    }
                    
                    break;
                case KEY_LEFT:
                    for(int i=0; i <5; i++){
                        mvwaddch(win,snakearr[i].yloc,snakearr[i].xloc,' ');
                    }
                    for(int i = 0;i<5;i++){
                        if(snakearr[i].head){
                            snakearr[i].xloc--;
                        }
                        else{
                            snakearr[i].xloc = snakearr[i+1].xloc;
                            snakearr[i].yloc = snakearr[i+1].yloc;
                        }
                    }
                    
                    break;
                case KEY_RIGHT:
                    for(int i=0; i <5; i++){
                        mvwaddch(win,snakearr[i].yloc,snakearr[i].xloc,' ');
                    }
                    for(int i = 0;i<5;i++){
                        if(snakearr[i].head){
                            snakearr[i].xloc++;
                        }
                        else{
                            snakearr[i].xloc = snakearr[i+1].xloc;
                            snakearr[i].yloc = snakearr[i+1].yloc;
                        }
                    }
                    
                    break;
                default:
                    break;
            }
            for(int i=0; i <5; i++){
                mvwaddch(win,snakearr[i].yloc,snakearr[i].xloc,'o');
            }
            wrefresh(win);
        }
        getchar();
    endwin();
return 0;
}


