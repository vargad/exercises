#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <complex>

QRgb mapping[16] = {
    qRgb(12, 44, 138),
    qRgb(24, 82, 177),
    qRgb(57, 125, 209),
    qRgb(134, 181, 229),
    qRgb(211, 236, 248),
    qRgb(241, 233, 191),
    qRgb(248, 201, 95),
    qRgb(255, 170, 0),
    qRgb(204, 128, 0),
    qRgb(153, 87, 0),
    qRgb(106, 52, 3)
};

int mandel(std::complex<double> const &c) {
    std::complex<double> z = 0;
    for (int i=0; i<60; ++i) {
        z = z*z+c;
        if (std::abs(z) > 2) return i;
    }
    return -1;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QImage img(800, 800, QImage::Format_RGB32);
    for (int i=0; i<img.width(); ++i) {
        for (int j=0; j<img.height(); ++j)
        {
            std::complex<double> c(double(i)/img.width()*3-2.25, double(j)/img.height()*3-1.5);
            auto k = mandel(c);
            if (k<0)
                img.setPixel(i, j, qRgb(0, 0, 0));
            else
                img.setPixel(i, j, mapping[k%16]);
        }
    }
    ui->image->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
