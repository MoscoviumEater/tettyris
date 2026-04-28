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




    if (!iflsh){
        for (int r = 0; r < 4; r++) {
            int pr = cupc.lay[r].r;
            int pc = cupc.lay[r].c;
            ren[pr][pc] = 1;
        }
    }
}

void pcmov(int di,int cabinet[20][10]) {
    int prohmov = 0;

    for (int i = 0; i < 4; i++) {
        if (cupc.lay[i].c + di < 0 || cupc.lay[i].c + di >= 10 || cabinet[cupc.lay[i].r][cupc.lay[i].c + di] == 1) {
            prohmov = 1;
        }
    }
    if (!prohmov) {
        for (int i = 0; i < 4; i++) {
            cupc.lay[i].c += di;
        }
    }
}
void pcdrp(int cabinet[20][10]) {
    int locked=chkloc();

    if (locked==0) {
        for (int i = 0; i < 4; i++) {
            cupc.lay[i].r+=1;

        }
    
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
        int nrot = (cupc.rot+1)%4;
        int kc = kk[k];
        int dr = cupc.lay[0].r-stt[cur][cupc.rot][0].r;
        int dc = cupc.lay[0].c -stt[cur][cupc.rot][0].c;
        int prohrot = 0;
        for (int i = 0; i < 4; i++) {
            int nr=stt[cur][nrot][i].r + dr;
            int nc=stt[cur][nrot][i].c + dc +kc ;
            if (nr < 0 || nr >= 20 || nc < 0 || nc >= 10 || cabinet[nr][nc] == 1)prohrot=1;
        }
        if (!prohrot) {
            int nR[4], nC[4];
            for (int i = 0; i < 4; i++) {
                nR[i]=stt[cur][nrot][i].r + dr;
                nC[i]=stt[cur][nrot][i].c + dc + kc;
            }
            for (int i = 0; i < 4; i++) {
                cupc.lay[i].r = nR[i];
                cupc.lay[i].c = nC[i];
            }
            cupc.rot=nrot;
            return;
        }

    }
}
