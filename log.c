#include "decl.h"

int chkloc() {
    int locked=0;
    for (int r = 0; r < 4; r++) {
        if (cupc.lay[r].r+1>=20 || cabinet[cupc.lay[r].r + 1][cupc.lay[r].c] == 1 ) {
            locked = 1;
        }
    }
    return locked;
}

void calc() {
    int gW, gH;
    getmaxyx(stdscr, gH, gW);

    pd = (gW - gWide) / 2;

    vd = (gH - gTall) / 2;
    if (vd < 0) vd = 0;
    if (vd + 22 > gH) vd = gH - 22;



}

void lincl() {


    for (int i = 0; i < clrd; i++) {
        int r=clrr[i]
     /*       cnt=0;

        for (int c = 0; c < 10; c++) {

            cnt += cabinet[r][c];

        }
        if (cnt==10) {
            clr = 1;
            clrr[clrd] = r;
            clrd++;*/


            for (int sr = r; sr > 0; sr--) {
                for (int sc = 0; sc < 10; sc++) {
                    cabinet[sr][sc] = cabinet[sr-1][sc];


                }
            }
            for (int sc = 0; sc < 10; sc++) cabinet[0][sc] = 0;
           /* r--;
       }

    }


}
int linsc(int cabinet[20][10], int op[4]) {

    int fnd = 0;

    for (int r = 0; r < 20; r++) {
        int cnt = 0;
        for (int c = 0; c < 10; c++) {
            cnt += cabinet[r][c];
        }

        if (cnt == 10) {
            op[fnd++] = r;
        }
    }

    return fnd;

}


void tick(int ren[20][10], int cabinet[20][10]) {

    int locked = chkloc();


    if (locked==0) {
        for (int i = 0; i < 4; i++) {
            cupc.lay[i].r+=1;

        }
        cupc.pvtr += 1;
    } else {
        for (int i = 0; i < 4; i++) {
            cabinet[cupc.lay[i].r][cupc.lay[i].c] = 1;


        }




        cur = nxt;
        if (!iflsh){
            cupc = tot[cur];
            sed ^= (sed << 3);
            sed += 1;
            sed &= 0xffff;
            tp = sed % 7;
             while (tp == nxt) {
                 sed ^= (sed << 3);
                 sed += 1;
                 sed &= 0xffff;
                 tp = sed % 7;
             }
        }
        if (cur==6) {
            drt=0;
        }else {
            drt++;
        }
        nxt = tp;
        for (int i = 0; i < 4; i++) {
            if (cabinet[cupc.lay[i].r][cupc.lay[i].c] == 1) lose = 1;
        }


    }


}
void flstat() {
    int fr = 0;
    if (!iflsh) {
        flshc=linsc(cabinet,flshr);
        if (flshc>0) {
            iflsh = 1; tflsh=20;
            sd=0;
            fr=0;
            for (int i=0; i < 3; i++) {
                for (int cl = 0; cl < 6; cl++) {
                    for (int e = 0; e < flshc; e++) {

                        wmove(gw,flshr[e]+1, 10 + (cl*2)); wprintw(gw,"!!");
                        wmove(gw,flshr[e]+1, 10 - (cl*2)+2); gmpt("!!");


                    }
                    
                    wnoutrefresh(gw);
                    napms(60);
                    


                    doupdate();


                }
                
               
                wrefresh(gw);
            }


        }
        return;
    }

            lincl();
            iflsh = 0;
            flshc = 0;




    }
void lv(){
 unsigned int eff = (lvl==0xff)?1:lvl;
    switch(eff){
        case 0xff: gtm=gtmt[0];break;
        default:
         if (lvl>=29) gtm=gtmt[14];
         else if (lvl>=19)gtm=gtmt[13];
         else if (lvl>=16)gtm=gtmt[12];
         else if (lvl>=13)gtm=gtmt[11];
         else if (lvl>=10)gtm=gtmt[10];
         else gtm=gtmt[lvl-1];
    }
}
