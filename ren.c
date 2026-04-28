#include "decl.h"

char pcty(char ty) {


    mvwprintw(sw,0,0,"<!============!>");
    mvwprintw(sw,4,0,"<!============!>");

    mvwprintw(sw,1,0,"<!");
    mvwprintw(sw,2,0,"<!");
    mvwprintw(sw,3,0,"<!");

    mvwprintw(sw,1,14,"!>");
    mvwprintw(sw,2,14,"!>");
    mvwprintw(sw,3,14,"!>");



    mvwprintw(sw,1,6, "NEXT");


    switch (ty) {



        case 'T': {
            mvwprintw(sw,2,5, "[][][]  ");
            mvwprintw(sw,3,5, "  []    ");
            break;
        }
        case 'Z': {

            mvwprintw(sw,2,5, "[][]    ");
            mvwprintw(sw,3,5, "  [][]  ");


            break;
        }
        case 'S': {

            mvwprintw(sw,2,5, "  [][] ");
            mvwprintw(sw,3,5, "[][]   ");


            break;

        }
        case 'J': {
            mvwprintw(sw,2,5, "[]     ");
            mvwprintw(sw,3,5, "[][][] ");


            break;
        }
        case 'L': {
            mvwprintw(sw,2,5, "    [] ");
            mvwprintw(sw,3,5, "[][][] ");


            break;
        }
        case 'O': {
            mvwprintw(sw,2,5, " [][]  ");
            mvwprintw(sw,3,5, " [][]  ");

            break;

        }
        case 'I': {
            mvwprintw(sw,2,4, "        ");
            mvwprintw(sw,3,4, "[][][][]");

            break;
        }

        default:{wprintw(sw,"Missing next dat.");}




    }
    return ty;
}
void bfi() {
    if (lose) {



        for (int cl = 0; cl < 5; cl++) {
            for (int ro = 0; ro < 20; ro++) {
                mvwprintw(gw,1+ro, 2 + (cl*2), "!!");
                mvwprintw(gw,1+ro, 20 - (cl*2), "!!");

                wnoutrefresh(gw);
                doupdate();

                napms(10);
            }
        }






    }
}
void gridren(int ren[20][10], int clrr[], int clrd, int clr) {

    // memset(bfr,0,sizeof(bfr));
    if (lose)return;

    // B I N G O and bingo was his name-o
    int iclr=0;
    for (int r = 0; r < 20; r++) {
        iclr=0;

        wmove(gw,(r)+1, 0);





        gmpt("<!");
        for (int e = 0; e < clrd; e++) {
            if (clrr[e] == r) {
                iclr = 1;
                break;

            }
        }
        for (int c = 0; c < 10; c++) {





            // if (iflsh && iclr) {
            //   gmpt("##");

            //}
            if (ren[r][c]==1) {
                gmpt("[]");
            }else  {
                gmpt(". ");
            }



        }

        gmpt("!>");

        //        gflsh();

        // fflush(stdout);

        //    gmpt("\n");


    }


    wmove(gw,21, 0);

    gmpt("<!");
    for (int b = 0; b < 20; b++) {
        gmpt("=");

    }
    gmpt("!>");
    gflsh();
    wmove(gw,22, 0);
    gmpt("  ");
    for (int c = 0; c < 10; c++) {

        gmpt("\\/");
    }
    gflsh(); p=0;

}

void nxren() {

    switch (nxt) {


        case 0: {
            pcty('T');
            break;
        }
        case 1: {
            pcty('S');
            break;
        }
        case 2: {
            pcty('Z');
            break;
        }
        case 3: {
            pcty('J');
            break;
        }
        case 4: {
            pcty('L');
            break;
        }
        case 5: {
            pcty('O');
            break;
        }
        case 6: {
            pcty('I');
            break;
        }
    }

}

