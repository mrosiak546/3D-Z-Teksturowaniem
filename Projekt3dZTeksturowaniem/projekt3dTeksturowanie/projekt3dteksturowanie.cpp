
#include "projekt3dteksturowanie.h"
#include <QPainter>

projekt3dteksturowanie::projekt3dteksturowanie(QWidget *parent)
    : QWidget{parent}
{
    im = QImage(im_width, im_height, QImage::Format_RGB32);
    im.fill(Qt::white);
    im_source.load("C:/Users/rosia/OneDrive/Pulpit/Studia/Grafika Komputerowa/Projekt3dZTeksturowaniem/projekt3dTeksturowanie/czerwony.png");
    operacje();
    update();
}

void projekt3dteksturowanie::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(0, 0, width(), height(), Qt::white);
    p.drawImage(0, 0, im);
}

void projekt3dteksturowanie::drawPixel(int x,int y,int r,int g,int b)
{
    if(x<im.width() && x>=0 && y<im.height() && y>=0)
    {
        uchar *pix = im.scanLine(y) + 4 * x;
        pix[0] = r;
        pix[1] = g;
        pix[2] = b;
    }
}

void projekt3dteksturowanie::drawLine(int x1,int y1,int x2,int y2)
{
    //Uwzglednic ze oba punkty są zerami !! bo moze byc problem
    int x, y;
    //    if(x1>im.width()) x1 = im.width();
    //    if(x2>im.width()) x2 = im.width();
    //    if(x1<0) x1 = 0;
    //    if(x2<0) x2 = 0;
    //    if(y1>im.height()) y1 = im.height();
    //    if(y2>im.height()) y2 = im.height();
    //    if(y1<0) y1 = 0;
    //    if(y2<0) y2 = 0;
    if((x1 == x2) && (y1==y2))
    {
        drawPixel(x1,y1,0,0,0);
        return;
    }
    if(abs(y2-y1) <= abs(x2-x1))
    {
        /*
         Pojawienie sie problemu z rysowaniem linii w z prawej do lewej czyli zmniejszanie wartości
         aby to zrobić należało zmienić kolejność aby uzyskiwac poprawne wartości co gwarantuje nam podany warunek
        */
        if (x1 > x2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        for(x=x1; x<=x2; x++)
        {
            y=y1+(x-x1)*(y2-y1)/(x2-x1);
            drawPixel(x, y, 0, 0, 0);
        }
    }
    else
    {
        /*
         Pojawienie sie problemu z rysowaniem linii w z góry na dół czyli zmniejszanie wartości
         aby to zrobić należało zmienić kolejność aby uzyskiwac poprawne wartości co gwarantuje nam podany warunek
        */
        if (y1 > y2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        for(y=y1; y<=y2; y++)
        {
            x=x1+(y-y1)*(x2-x1)/(y2-y1);
            drawPixel(x, y, 0, 0, 0);
        }
    }
}

void projekt3dteksturowanie::mnozenieMacierzy(double macierz1[4][4], double macierz2[4][4])
{
    double wynik[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            wynik[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                wynik[i][j] += macierz1[i][k] * macierz2[k][j];
            }
        }
    }
    // Przypisanie wyniku do macierz1
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            macierz1[i][j] = wynik[i][j];
        }
    }
}


void projekt3dteksturowanie::kolory(double macierz[4][4])
{
    for (int i = 0; i < 8; i++)
    {
        double x = macierz[0][0] * kostka[i][0] + macierz[0][1] * kostka[i][1] + macierz[0][2] * kostka[i][2] + macierz[0][3];
        double y = macierz[1][0] * kostka[i][0] + macierz[1][1] * kostka[i][1] + macierz[1][2] * kostka[i][2] + macierz[1][3];
        double z = macierz[2][0] * kostka[i][0] + macierz[2][1] * kostka[i][1] + macierz[2][2] * kostka[i][2] + macierz[2][3];

        //Perspektywa
        kostka2D[i][0] = (int)(x * f / (z + f)) + im_width/2;
        kostka2D[i][1] = (int)(y * f / (z + f)) + im_height/2;

        kostka3D[i][0] = (int)(x);
        kostka3D[i][1] = (int)(y);
        kostka3D[i][2] = (int)(z);
    }
}

void projekt3dteksturowanie::operacje()
{
    // Macierz łącząca wszystkie operacje
    double matrix[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    // Wykonanie operacji przesunięcia, obrotu, skalowania i pochylenia
    mnozenieMacierzy(matrix, Przesuwanie);

    mnozenieMacierzy(matrix, ObracanieX);
    mnozenieMacierzy(matrix, ObracanieY);
    mnozenieMacierzy(matrix, ObracanieZ);

    mnozenieMacierzy(matrix, Skalowanie);

    mnozenieMacierzy(matrix, Pochylanie);

    kolory(matrix);
    im.fill(Qt::white);
    rysKostki();
    update();
}

//Potrzebne do wyświetlania ścian
void projekt3dteksturowanie::normalVector(double sciana[4][3], double normal[3]){
    double v1[3] = { sciana[1][0] - sciana[0][0], sciana[1][1] - sciana[0][1], sciana[1][2] - sciana[0][2] };
    double v2[3] = { sciana[2][0] - sciana[0][0], sciana[2][1] - sciana[0][1], sciana[2][2] - sciana[0][2] };

    normal[0] = v1[1] * v2[2] - v1[2] * v2[1];
    normal[1] = v1[2] * v2[0] - v1[0] * v2[2];
    normal[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void projekt3dteksturowanie::rysKostki()
{
    int sciany[6][4] = {
        {0, 1, 5, 4},
        {7, 6, 2, 3},
        {6, 5, 1, 2},
        {7, 3, 0, 4},
        {7, 4, 5, 6},
        {3, 2, 1, 0}
    };

    for (int i = 0; i < 6; i++) {
        double sciana[4][3];
        for (int n = 0; n < 4; n++) {
            //przypisanie do obliczania normal i view
            sciana[n][0] = kostka3D[sciany[i][n]][0];
            sciana[n][1] = kostka3D[sciany[i][n]][1];
            sciana[n][2] = kostka3D[sciany[i][n]][2];
        }


        double normal[3];
        normalVector(sciana, normal);

        double viewVector[3] = { pozycjaKamery[0] - sciana[0][0], pozycjaKamery[1] - sciana[0][1], pozycjaKamery[2] - sciana[0][2] };

        double dotProduct = normal[0] * viewVector[0] + normal[1] * viewVector[1] + normal[2] * viewVector[2];
        if (dotProduct > 0) {

            for (int n = 0; n < 4; n++) {
                int trojkat[3][2];
                trojkat[0][0] = kostka2D[sciany[i][0]][0];
                trojkat[0][1] = kostka2D[sciany[i][0]][1];
                trojkat[1][0] = kostka2D[sciany[i][1]][0];
                trojkat[1][1] = kostka2D[sciany[i][1]][1];
                trojkat[2][0] = kostka2D[sciany[i][2]][0];
                trojkat[2][1] = kostka2D[sciany[i][2]][1];
                wypelnianie(trojkat);
                trojkat[0][0] = kostka2D[sciany[i][0]][0];
                trojkat[0][1] = kostka2D[sciany[i][0]][1];
                trojkat[1][0] = kostka2D[sciany[i][3]][0];
                trojkat[1][1] = kostka2D[sciany[i][3]][1];
                trojkat[2][0] = kostka2D[sciany[i][2]][0];
                trojkat[2][1] = kostka2D[sciany[i][2]][1];
                wypelnianie(trojkat);
            }

            for (int n = 0; n < 4; n++) {
                drawLine(kostka2D[sciany[i][n]][0], kostka2D[sciany[i][n]][1], kostka2D[sciany[i][(n + 1) % 4]][0], kostka2D[sciany[i][(n + 1) % 4]][1]);

            }
        }
    }
}

void projekt3dteksturowanie::wypelnianie(int trojkat[3][2]){
    int yMax=trojkat[0][1];
    int yMin=trojkat[0][1];
    QVector<int> X;

    for(int i=0; i<3; i++){
        if(trojkat[i][1]>yMax) yMax=trojkat[i][1];
        if(trojkat[i][1]<yMin) yMin=trojkat[i][1];
    }

    for(int y=yMin; y<=yMax; y++){
        if (y<0 || y>=im_height) continue;
        for(int i=0; i<3; i++){
            int p1=i, p2=(i+1)%3;

            if(trojkat[p1][1]>trojkat[p2][1]) std::swap(p1, p2);

            if (y >= trojkat[p1][1] && y < trojkat[p2][1] && trojkat[p1][1] != trojkat[p2][1]){
                X.push_back(trojkat[p1][0]+(y-trojkat[p1][1])*(trojkat[p2][0]-trojkat[p1][0])/(trojkat[p2][1]-trojkat[p1][1]));
            }
        }
        std::sort(X.begin(), X.end());
        if(X.size()>1){
            for(int x=X[0]; x<X[1]; x++){
                if (x<0 || x>=im_width)  continue;
                double W, Wv, Ww, u, v, w;
                double xt, yt;
                QPoint a={(int)trojkat[0][0], (int)trojkat[0][1]}, b={(int)trojkat[1][0], (int)trojkat[1][1]}, c={(int)trojkat[2][0], (int)trojkat[2][1]};
                QPoint at={0, 0}, bt={0, 500}, ct={500, 500};

                W = (b.x() - a.x())*(c.y() - a.y()) - (b.y() - a.y())*(c.x() - a.x());
                Wv = ((double)x - a.x())*(c.y() - a.y()) - ((double)y - a.y())*(c.x() - a.x());
                Ww = (b.x() - a.x())*((double)y - a.y()) - (b.y() - a.y())*((double)x - a.x());
                v=Wv/W;
                w=Ww/W;

                u=1-v-w;
                xt=u*at.x() + v*bt.x() + w*ct.x();
                yt=u*at.y() + v*bt.y() + w*ct.y();
                if (xt<0 || xt>=im_width)  continue;
                if (yt<0 || yt>=im_height) continue;

                im.setPixel(x, y, im_source.pixel(xt, yt));
            }
        }
        X.clear();
    }
}


void projekt3dteksturowanie::przesuwanieDX(int dx)
{
    this->dx = dx;
    Przesuwanie[0][3] = dx;
    operacje();
}

void projekt3dteksturowanie::przesuwanieDY(int dy)
{
    dy *= -1;
    this->dy = dy;
    Przesuwanie[1][3] = dy;
    operacje();
}

void projekt3dteksturowanie::przesuwanieDZ(int dz)
{
    this->dz = dz;
    Przesuwanie[2][3] = dz + f;
    operacje();
}

void projekt3dteksturowanie::skalowanieSX(int sx_int)
{
    if (!sx_int)
        return;
    sx = (double)sx_int / 100;
    Skalowanie[0][0] = sx;
    operacje();
}

void projekt3dteksturowanie::skalowanieSY(int sy_int)
{
    if (!sy_int)
        return;
    sy = (double)sy_int / 100;
    Skalowanie[1][1] = sy;
    operacje();
}

void projekt3dteksturowanie::skalowanieSZ(int sz_int)
{
    if (!sz_int)
        return;
    sz = (double)sz_int / 100;
    Skalowanie[2][2] = sz;
    operacje();
}

void projekt3dteksturowanie::obracanieX(int katX)
{
    this->katX = katX;
    double radians = qDegreesToRadians(katX);
    double cosVal = qCos(radians);
    double sinVal = qSin(radians);
    ObracanieX[1][1] = cosVal;
    ObracanieX[1][2] = -sinVal;
    ObracanieX[2][1] = sinVal;
    ObracanieX[2][2] = cosVal;
    operacje();
}

void projekt3dteksturowanie::obracanieY(int katY)
{
    this->katY = katY;
    double radians = qDegreesToRadians(katY);
    double cosVal = qCos(radians);
    double sinVal = qSin(radians);
    ObracanieY[0][0] = cosVal;
    ObracanieY[0][2] = sinVal;
    ObracanieY[2][0] = -sinVal;
    ObracanieY[2][2] = cosVal;
    operacje();
}

void projekt3dteksturowanie::obracanieZ(int katZ)
{
    this->katZ = katZ;
    double radians = qDegreesToRadians(katZ);
    double cosVal = qCos(radians);
    double sinVal = qSin(radians);
    ObracanieZ[0][0] = cosVal;
    ObracanieZ[0][1] = -sinVal;
    ObracanieZ[1][0] = sinVal;
    ObracanieZ[1][1] = cosVal;
    operacje();
}

void projekt3dteksturowanie::pochylanieSHX(int shx_int)
{
    shx = (double)shx_int / 100;
    Pochylanie[0][2] = shx;
    operacje();
}

void projekt3dteksturowanie::pochylanieSHY(int shy_int)
{
    shy = (double)shy_int / 100;
    Pochylanie[1][2] = shy;
    operacje();
}

