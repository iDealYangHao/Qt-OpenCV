#include "widget.h"
#include "ui_widget.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/features2d.hpp>
#include <QLabel>

QImage Mat2QImage(cv::Mat& image)
{
    QImage img;

    if (image.channels() == 3) {
        cv::cvtColor(image,image,cv::COLOR_BGR2RGB);
        img = QImage((const unsigned char*)(image.data), image.cols, image.rows,
            image.cols * image.channels(), QImage::Format_RGB888);
    }
    else if (image.channels() == 1) {
        img = QImage((const unsigned char*)(image.data), image.cols, image.rows,
            image.cols * image.channels(), QImage::Format_ARGB32);
    }
    else {
        img = QImage((const unsigned char*)(image.data), image.cols, image.rows,
            image.cols * image.channels(), QImage::Format_RGB888);
    }

    return img;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    cv::Mat image = cv::imread("/Users/yanghao/Desktop/IMG_0731.jpeg");
//    cv::imshow("ss",image);
    QLabel *label = new QLabel(this);
    QPixmap img = QPixmap::fromImage(Mat2QImage(image));
    img = img.scaled(800, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    label->setPixmap(img);
    setFixedSize(1000,800);
}

Widget::~Widget()
{
    delete ui;
}

