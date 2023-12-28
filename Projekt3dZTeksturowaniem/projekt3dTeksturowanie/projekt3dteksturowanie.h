
#ifndef PROJEKT3DTEKSTUROWANIE_H
#define PROJEKT3DTEKSTUROWANIE_H


#include <QWidget>


class projekt3dteksturowanie : public QWidget
{
    Q_OBJECT
public:
    explicit projekt3dteksturowanie(QWidget *parent = nullptr);
private:
    QImage im,im_source;
    const int im_width = 500;
    const int im_height = 500;
    const int im_depth = 500;

    double f = 500;
    double r = 200;

    int dx = 0;
    int dy = 0;
    int dz = 0;
    double sx = 1;
    double sy = 1;
    double sz = 1;
    int katX = 0;
    int katY = 0;
    int katZ = 0;
    double shx = 0;
    double shy = 0;

    int kostka3D[8][3];
    int kostka2D[8][2];


    double pozycjaKamery[3] = { 0,0, -f };

    double kostka[8][3] = {
        {-r, -r, -r},
        { r, -r, -r},
        { r,  r, -r},
        {-r,  r, -r},
        {-r, -r,  r},
        { r, -r,  r},
        { r,  r,  r},
        {-r,  r,  r}
    };

    double Przesuwanie[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, f},
        {0, 0, 0, 1}
    };
    double Skalowanie[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    double ObracanieX[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    double ObracanieY[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    double ObracanieZ[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    double Pochylanie[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    void paintEvent(QPaintEvent *);
    void drawPixel(int x,int y,int r,int g,int b);
    void drawLine(int x1,int y1,int x2,int y2);
    void mnozenieMacierzy(double macierz1[4][4], double macierz2[4][4]);
    void kolory(double macierz[4][4]);
    void operacje();
    void normalVector(double wall[4][3], double normal[3]);
    void rysKostki();
    void wypelnianie(int trojkat[3][2]);
public slots:
    void przesuwanieDX(int dx);
    void przesuwanieDY(int dy);
    void przesuwanieDZ(int dz);
    void skalowanieSX(int sx_int);
    void skalowanieSY(int sy_int);
    void skalowanieSZ(int sz_int);
    void obracanieX(int katX);
    void obracanieY(int katY);
    void obracanieZ(int katZ);
    void pochylanieSHX(int shx_int);
    void pochylanieSHY(int shy_int);

signals:

};

#endif // PROJEKT3DTEKSTUROWANIE_H
