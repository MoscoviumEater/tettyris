#include "decl.h"











void initpc() {
    tot[0] = T;
    tot[1] = S;
    tot[2] = Z;
    tot[3] = J;
    tot[4] = L;
    tot[5] = O;
    tot[6] = I;
};

int padx(int p) {

    for (int pdi = 0; pdi < pd; pdi++) gmpt(" ");
    return p;
}


void pcplc(struct pcs cupc, int ren[20][10]) {





    for (int r = 0; r < 4; r++) {
        int pr = cupc.lay[r].r;
        int pc = cupc.lay[r].c;
        ren[pr][pc] = 1;
    }
}

void pcmov(int di,int cabinet[20][10]) {
    int prohmov = 0;

    for (int i = 0; i < 4; i++) {
//        cupc.lay[i];
        /*if (cupc.lay[i].c - 1 < 0 || cabinet[cupc.lay[i].r][cupc.lay[i].c + di] == 1) {
            prohibit = 1;
        } else {
            cupc.lay[i].c--;
        }*/
        if (cupc.lay[i].c + di < 0 || cupc.lay[i].c + di >= 10 || cabinet[cupc.lay[i].r][cupc.lay[i].c + di] == 1) {
            prohmov = 1;
        }
    }
    if (!prohmov) {
        for (int i = 0; i < 4; i++) {
            cupc.lay[i].c += di;
        }
        cupc.pvtc += di;
    }
}
void pcdrp(int cabinet[20][10]) {
    int locked=chkloc();

    if (locked==0) {
        for (int i = 0; i < 4; i++) {
            cupc.lay[i].r+=1;

        }
        cupc.pvtr += 1;
    }
}

void pcrot(int cabinet[20][10]) {
    int kk[5];
    int nk;
    switch (cur) {
        case 0: kk[0]=0;kk[1]=1;kk[2]=-1;nk=3;break;
        case 1: kk[0]=0;kk[1]=1;kk[2]=-1;nk=3;break;
        case 2: kk[0]=0;kk[1]=1;kk[2]=-1;nk=3;break;
        case 3: kk[0]=0;kk[1]=1;kk[2]=-1;nk=3;break;
        case 4: kk[0]=0;kk[1]=1;kk[2]=-1;nk=3;break;
        case 5: kk[0]=0;nk=1;break;
        case 6: kk[0]=0;kk[1]=1;kk[2]=-1;kk[3]=2;kk[4]=-2;nk=5;break;
        default: kk[0]=0;nk=1;break;
    }
    for (int k = 0; k < nk; k++) {
        int dc = kk[k];
        int dr = 0;
        int prohrot = 0;
        for (int i = 0; i < 4; i++) {
            float pvtr = cupc.pvtr;
            float pvtc = cupc.pvtc + (cur==6 ? 0.5f : 0.0f);
            float nr = pvtr + (cupc.lay[i].c - pvtc);
            float nc = pvtc - (cupc.lay[i].r - pvtr);
           if ((int)roundf(nr)+dr < 0 || (int)roundf(nr)+dr >= 20 || (int)roundf(nc)+dc < 0 || (int)roundf(nc)+dc >= 10 || cabinet[(int)roundf(nr)+dr][(int)roundf(nc)+dc] == 1) {
                prohrot = 1;
            }
        }
        if (!prohrot) {
            int nR[4], nC[4];
            for (int i = 0; i < 4; i++) {
                float pvtr = cupc.pvtr;
                float pvtc = cupc.pvtc;
                float nr = pvtr + (cupc.lay[i].c - pvtc);
                float nc = pvtc - (cupc.lay[i].r - pvtr);
                nR[i] = (int)roundf(nr);
                nC[i] = (int)roundf(nc);
                nR[i] = (int)roundf(nr) + dr;
                nC[i] = (int)roundf(nc) + dc;
            }
            for (int i = 0; i < 4; i++) {
                cupc.lay[i].r = nR[i];
                cupc.lay[i].c = nC[i];
            }
            cupc.pvtr += dr;
            cupc.pvtc += dc;
            if (cur==6) cupc.pvtc = roundf(cupc.pvtc);

            return;
        }

    }
}
