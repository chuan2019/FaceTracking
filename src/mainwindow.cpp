#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QMessageBox>

//////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    capWebcam.open(0);

    qtimer = new QTimer(this);
    connect(qtimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
    qtimer->start(20);
}
//////////////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete ui;
}
//////////////////////////////////////////////////////////////
void MainWindow::processFrameAndUpdateGUI()
{
    bool frameCaptured = capWebcam.read(matOriginal);

    if (!frameCaptured || matOriginal.empty())
    {
        QMessageBox::information(this, "Error", "Unable to read from webcam \n\n \
exiting program");
        exitProgram();
        return;
    }

    if (ui->cbGrayScale->isChecked())
    {
        matPrevious = matOriginal.clone();
        cv::cvtColor(matPrevious, matPrevious, CV_BGR2GRAY);
    }

    frameCaptured = capWebcam.read(matProcessed);

    if (!frameCaptured || matOriginal.empty())
    {
        QMessageBox::information(this, "Error", "Unable to read from webcam \n\n \
exiting program");
        exitProgram();
        return;
    }

    imgOriginal = matToQImage(matOriginal);

    ui->lblOriginal->setPixmap(QPixmap::fromImage(imgOriginal.scaled(QSize(400, 400), Qt::KeepAspectRatio)));

    if (ui->cbGrayScale->isChecked())
    {
        cv::cvtColor(matProcessed, matProcessed, CV_BGR2GRAY);
        cv::Rect search_window(200, 200, 100, 100);
        trackingMeanShift(matProcessed, search_window);
    }
    if (ui->cvFlip->isChecked())
    {
        cv::flip(matProcessed, matProcessed, 1);
    }

    imgProcessed = matToQImage(matProcessed);
    ui->lblProcessed->setPixmap(QPixmap::fromImage(imgProcessed.scaled(QSize(400, 400), Qt::KeepAspectRatio)));
}
//////////////////////////////////////////////////////////////
void MainWindow::on_btnPauseOrResume_clicked()
{
    if (qtimer->isActive())
    {
        ui->btnPauseOrResume->setText(" resume ");
        qtimer->stop();
    }
    else
    {
        ui->btnPauseOrResume->setText(" pause ");
        qtimer->start(20);
    }
}
//////////////////////////////////////////////////////////////
void MainWindow::exitProgram()
{
    if (qtimer->isActive()) qtimer->stop();
    QApplication::quit();
}
//////////////////////////////////////////////////////////////
QImage MainWindow::matToQImage(cv::Mat mat)
{
    if (mat.channels() == 1) // grayscale image or black and white image
    {
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
    }
    else if (mat.channels() == 3) // RGB color image
    {
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    }
    else
    {
        qDebug() << "in openCVMatToQImage, image was not 1 channel or 3 channel, should never get here";
    }
    return QImage();
}
//////////////////////////////////////////////////////////////
void MainWindow::trackingMeanShift(cv::Mat &img, cv::Rect search_window)
{
    // 1-Criteria to MeanShift function
    cv::TermCriteria criteria(cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 10, 1);

    // 2-Tracking using MeanShift
    cv::meanShift(img, search_window, criteria);

    // 3-Show the result
    cv::rectangle(img, search_window, cv::Scalar(0, 255, 0), 3);
}
