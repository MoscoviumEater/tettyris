

#ifndef TTYRS
#define TTYRS
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>


#ifdef _WIN32
#include "deps/pdcmod/curses.h"

#else
    #include <unistd.h>
    
   #include <ncurses.h>
    #include <sys/ioctl.h>
#include <stdio.h>

#endif
#include <stdlib.h>

#define gmv(r,c) wmove(gw,r,c)
 #define gmpt(s) wprintw(gw,s)
    #define gflsh() wrefresh(gw)
extern int ren[20][10];
extern struct timespec bef;
struct sqrs {int r;int c;};
struct pcs {struct sqrs lay[4];int rot;};
extern struct sqrs stt[7][4][4];
extern struct pcs T;
extern struct pcs S;
extern struct pcs Z;
extern struct pcs J;
extern struct pcs L;
extern struct pcs O;
extern struct pcs I;
extern struct pcs tot[7];
extern int pcd;
extern int rst;
extern int lalvl;
extern unsigned int lvl;
extern struct pcs cupc;
extern unsigned int gtmt[];
extern int cur;
extern int tp;
extern int nxt;
extern unsigned int drt;
extern unsigned int o;
extern unsigned int d;
extern unsigned int t;
extern unsigned int tt;
extern unsigned int lcn;
extern int vd;
extern int sessions;
extern int pd;
extern int whg;
extern int lhg;
extern int lose;
extern int cabinet[20][10];
extern int clrd;
extern int clrr[4];
extern unsigned int his;
extern int clr;
extern int cnt;
extern int paused;
extern int iflsh;
extern unsigned int gtm;
extern int tflsh;
extern int flshr[4];
extern int flshc;
extern char lnxt;
extern int p;
extern unsigned int s;
extern int sd;
extern int frz;
extern unsigned int sed;
extern const int gWide;
extern const int gTall;
extern WINDOW *gw;
extern WINDOW *sw;
extern WINDOW *pw;
extern WINDOW *lw;
extern WINDOW *al;
extern WINDOW *ms;
void gridren(int ren[20][10], int clrr[], int clrd, int clr);
void nxren();
char pcty(char ty);
void bfi();
void initpc();
void pcplc(struct pcs cupc, int ren[20][10]);
void pcmov(int di, int cabinet[20][10]);
void pcdrp(int cabinet[20][10]);
void pcrot(int cabinet[20][10]);
int chkloc();
void tick(int ren[20][10], int cabinet[20][10]);
void lincl();
int linsc(int cabinet[20][10], int op[4]);
void flstat();
void calc();
void lv();


#endif
