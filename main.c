#include "decl.h"








void gm() {

        while (1) {

        curs_set(0);

        
        lvl=(lcn/10);
        lv();
                  
        for (int i = 0; i < 10; i++) {
            napms(5);





#ifdef _WIN32
            whg = wgetch(gw);
            if (whg != ERR) {

                wrefresh(gw);
                if (whg == 32) {
                    paused = !paused;
                    continue;
                }
                if (paused != 1 && !iflsh) {
                    
                    if (whg == KEY_DOWN ) pcdrp(cabinet);
                    if (whg == KEY_UP ) pcrot(cabinet);
                    if (whg == KEY_LEFT) pcmov(-1, cabinet);
                    if (whg == KEY_RIGHT) pcmov(1, cabinet);

                    if(whg == 115 || whg == 83){
                            for (int i = 0; i<20; i++){
                            if(chkloc())break;
                            pcdrp(cabinet);
                     }
                     frz=1;
                    }
                    continue;
                    
                }
            }
            




#endif
#ifndef _WIN32
            lhg= wgetch(gw);
            if (lhg != ERR) {

                if (lhg == 32) {
                    paused = !paused;
                    flushinp();
                    continue;
                }else if (lhg==113||lhg==81){

                    clear();
                    refresh();
                    return;
		            }else if (lhg==91&&paused !=1&&!iflsh){

                    lhg= wgetch(gw);
                    if (lhg == 66 ) pcdrp(cabinet);
                    if (lhg == 65 ) pcrot(cabinet);
                    if (lhg == 68) pcmov(-1, cabinet);
                    if (lhg == 67) pcmov(1, cabinet);
                    
                }
                
                if(lhg == 115 || lhg == 83){
                        for (int i = 0; i<20; i++){
                            if(chkloc())break;
                            pcdrp(cabinet);
                     }
                     frz=1;
                 }
                 continue;
              }
#endif

            struct timespec rn;
            clock_gettime(CLOCK_MONOTONIC, &rn);
            long tm = (rn.tv_sec - bef.tv_sec) * 1000 +
                      (rn.tv_nsec - bef.tv_nsec) / 1000000;
            memset(ren, 0, sizeof(ren));

            for (int r=0;r<20;r++){
                for (int c=0;c<10;c++) ren[r][c] = cabinet[r][c];}
                flstat();
                
                pcplc(cupc,ren);
                if (paused != 1) {
                    if (tm >= gtm && !iflsh) {

                        tick(ren, cabinet);
                        bef = rn;
                    }

                }

            


            
            if (iflsh) {

                wmove(gw,0,0);
                gridren(ren, flshr, flshc, 1);
                nxren();

                if (!sd) {
                    
                    switch (flshc) {
                        case 1:s+=40;o++;lcn+=1;break;
                        case 2:s+=100;d++;lcn+=2;break;
                        case 3:s+=300;t++;lcn+=3;break;
                        case 4:s+=1200;tt++;lcn+=4;break;
                    }
                    if (s > his)his=s;

                    sd=1;
                }


            }else {
                mvwprintw(sw,8,0,"            ");
                if (paused != 1&&frz != 1){

                    gridren(ren, clrr, clrd, clr );
                    mvwprintw(pw,0,0, "<!============!>");

                    mvwprintw(pw,1,0, "<!");
                    mvwprintw(pw,2,0, "<!");
                    mvwprintw(pw,3,0, "<!");
                    mvwprintw(pw,4,0, "<!");
                    mvwprintw(pw,5,0, "<!");
                    mvwprintw(pw,6,0, "<!");
                    mvwprintw(pw,1,14, "!>");
                    mvwprintw(pw,2,14, "!>");
                    mvwprintw(pw,3,14, "!>");
                    mvwprintw(pw,4,14, "!>");
                    mvwprintw(pw,5,14, "!>");
                    mvwprintw(pw,6,14, "!>");
                    mvwprintw(pw,1,3, "SESSION");
                    mvwprintw(pw,2,5, "%08d",sessions);
                    mvwprintw(pw,3,3, "SCORE");
                    mvwprintw(pw,4,5, "%08d",s);
                    mvwprintw(pw,5,3,"BEST");
                    mvwprintw(pw,6,5,"%08d",his);

                    mvwprintw(lw,0,0, "  ===============  ");
                    for (int r=0;r<16;r++) {
                        mvwprintw(lw,r,0,"<!");
                    }
                    mvwprintw(lw,1,4,"LEVEL");
                    mvwprintw(lw,2,6,"%08d",lvl);
                    mvwprintw(lw,3,4,"LINES");
                    mvwprintw(lw,4,6,"%08d",lcn);
                    mvwprintw(lw,5,2,"===============");
                    mvwprintw(lw,6,4, "ONELINER");
                    mvwprintw(lw,7,6, "%08d",o);
                    mvwprintw(lw,8,4, "DOUBLE");
                    mvwprintw(lw,9,6, "%08d",d);
                    mvwprintw(lw,10,4, "TRIPLE");
                    mvwprintw(lw,11,6, "%08d",t);
                    mvwprintw(lw,12,4, "TETTYRIS");
                    mvwprintw(lw,13,6, "%08d",tt);
                    mvwprintw(lw,14,4, "DROUGHT");
                    mvwprintw(lw,15,6, "%08d",drt);
		
                    for (int r=0;r<16;r++) {
                        mvwprintw(lw,r,17,"!>");
                    }
                    mvwprintw(lw,16,0, "<!===============!>");
                    if (nxt != lnxt) {

                        

                        werase(sw);



                        nxren();
                        lnxt = nxt;
                    }

                }

                else if (paused) {
                    mvwprintw(gw,11,8," PAUSED ");
                    for (int r=0; r<20; r++){
                        for (int c=0; c<10;c++){
                            mvwprintw(al,r,(c*2),". ");
                        }
                    
                    }
                    wnoutrefresh(al);
                    
                    
                }
		mvwprintw(ms,0,0,"LOCAL DEBUG NO REDIST");
                if (lvl > lalvl) {
                    for (int i=0;i<2;i++){
                        mvwprintw(ms,0,2,"!!!!!NEW  LVL!!!!!");
                        wrefresh(ms);
                        napms(200);
                        //wclear(ms);
                        wrefresh(ms);
                        napms(200);
                    }
                    lalvl=lvl;
                }


            }

            wrefresh(gw);
            wrefresh(sw);
            wrefresh(lw);
            wrefresh(pw);
	          wrefresh(ms);
        //  wrefresh(al);


            if (lose){rst=1;return;}

            clr=0;
            clrd =0;
            frz=0;

        }


    }



}
void gov() {
        wclear(ms);
        wrefresh(ms);
        bfi();
        flushinp();
        mvwprintw(gw,9 , 7 , " GAMEOVER ");
        mvwprintw(gw,10 , 7 , " TRYAGAIN ");
        mvwprintw(gw,11 , 7 , " COMRADE. ");
        mvwprintw(gw,0,3,"PRESS R TO RESET");
        wmove(sw,vd , pd );
        nodelay(gw,FALSE);
        int ovw =  wgetch(gw);


        while (ovw != 114 && ovw != 82) {
            ovw = wgetch(gw);
        }
         wclear(gw);
         wclear(sw);
        wclear(lw);
        wclear(pw);
        memset(cabinet, 0, sizeof(cabinet));
        rst=0;
	lose=0;
        s = 0; o = 0; d = 0; t = 0; tt = 0;
        lcn = 0; drt = 0; lose = 0;
        clr = 0; clrd = 0;
        iflsh = 0; tflsh = 0; flshc = 0;
        sd = 0; frz = 0; p = 0;
        lnxt = -1;
        sed = (time(NULL) ^ clock()) & 0xffff;
        nxt = sed % 7;
        sed = (sed * 5 + 1) & 0xffff;
        cur = sed % 7;
        cupc = tot[cur];
        lalvl=1;
        clock_gettime(CLOCK_MONOTONIC, &bef);
        nodelay(gw,TRUE);

#ifdef _WIN32
    keypad(gw, TRUE);
#else
    keypad(gw, FALSE);
#endif
        gm();
}


int main(int argc, char *argv[]) {
    rst=0;
    clock_gettime(CLOCK_MONOTONIC, &bef);

    initscr();raw();noecho();

    calc();
    gw = newwin(gTall+2, gWide+2, vd-1, pd-1);
    sw = newwin(gTall+5, 100, vd+8, pd+26);
    pw = newwin(7, 20, vd+1, pd+26);
    lw = newwin(21, 20, vd+1, pd-23);
    al = newwin(20,20, vd,pd+1);
    ms = newwin(1,21, vd-1,pd);
    nodelay(gw, TRUE);

#ifdef _WIN32
    keypad(gw, TRUE);
#else
    keypad(gw, FALSE);
#endif






    initpc();

    sed = (time(NULL) ^ clock()) & 0xffff;
    nxt = sed % 7;
    sed=(sed*5+1)&0xffff;
    cur = sed % 7;

    if (!iflsh) {
        cupc = tot[cur];
    }
    gm();
    while (lose) {
     sessions++;
	   gov();
	
    }



















    noraw();
    echo();
    flushinp();
    curs_set(1);
    endwin();
}



