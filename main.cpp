#include <iostream>
#include <cstdlib>

using namespace std;

struct Pole
{
  int mina;
  int odkryte;
};

class Plansza
{
    int miny;
public:
    Pole polegry[10][10];
    Plansza();

    void wyswietl_test();
    void wyswietl();
    void przydziel();
    void odkryj(int x, int y);
    int czy_jest_mina(int x, int y);
    void licz_miny(int x, int y);
};
    Plansza::Plansza()
    {
    int i;
    int j;
    miny=0;
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
            polegry[i][j].mina=0;
            polegry[i][j].odkryte=0;
            }
        }
    }

void Plansza::wyswietl_test()
{
    int i,j;
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
            cout<<polegry[i][j].mina;
            cout<<polegry[i][j].odkryte<<" ";
            }
        cout<<endl;
        }
}

void Plansza::wyswietl()
{
     int i,j;
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(polegry[i][j].odkryte==1)
                {
                    cout<<miny<<" ";
                }

                else
                cout<<". ";
            }
            cout<<endl;
        }
        cout<<endl;
}

int Plansza::czy_jest_mina(int x, int y)
{
    if((x<0 || x>10) || (y<0 || y>10))
        return 0;
    else if(polegry[x][y].mina==1)
        return 1;
    else
        return 0;
}

void Plansza::licz_miny(int x, int y)
{
    miny=czy_jest_mina(x,y-1)+ czy_jest_mina(x+1,y)+ czy_jest_mina(x,y+1)+ czy_jest_mina(x-1,y-1)+ czy_jest_mina(x-1,y)+ czy_jest_mina(x-1,y+1)+ czy_jest_mina(x+1,y-1)+ czy_jest_mina(x+1,y+1);
}

void Plansza::odkryj(int x, int y)
{
    polegry[x][y].odkryte=1;
    licz_miny(x,y);
}

void Plansza::przydziel()
{
/*int i,j;
    int pom;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            pom=rand() % 100;
                cout<<pom<<" ";
                if(pom<50){
                polegry[i][j].mina=1;
                }
                else
                polegry[i][j].mina=1;
        }
    }
}


*/


    polegry[1][1].mina=1;
    polegry[2][2].mina=1;
    polegry[3][3].mina=1;
    polegry[4][4].mina=1;
    polegry[5][5].mina=1;
    polegry[6][6].mina=1;
    polegry[6][4].mina=1;
    polegry[7][7].mina=1;
    polegry[8][8].mina=1;
    polegry[9][9].mina=1;

}
int main()
{
    Plansza p1;
    //p1.wyswietl();
    p1.przydziel();
    p1.wyswietl();

    p1.odkryj(6,5);
    p1.wyswietl();
}
/*
    void przydziel()
{

}
*/
