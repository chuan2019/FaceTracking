/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnPauseOrResume;
    QCheckBox *cbGrayScale;
    QCheckBox *cvFlip;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *lblOriginal;
    QLabel *lblProcessed;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(619, 350);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnPauseOrResume = new QPushButton(centralWidget);
        btnPauseOrResume->setObjectName(QStringLiteral("btnPauseOrResume"));

        horizontalLayout_2->addWidget(btnPauseOrResume);

        cbGrayScale = new QCheckBox(centralWidget);
        cbGrayScale->setObjectName(QStringLiteral("cbGrayScale"));

        horizontalLayout_2->addWidget(cbGrayScale);

        cvFlip = new QCheckBox(centralWidget);
        cvFlip->setObjectName(QStringLiteral("cvFlip"));

        horizontalLayout_2->addWidget(cvFlip);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblOriginal = new QLabel(centralWidget);
        lblOriginal->setObjectName(QStringLiteral("lblOriginal"));
        lblOriginal->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(lblOriginal);

        lblProcessed = new QLabel(centralWidget);
        lblProcessed->setObjectName(QStringLiteral("lblProcessed"));
        lblProcessed->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(lblProcessed);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        gridLayout->setRowStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnPauseOrResume->setText(QApplication::translate("MainWindow", " pause ", 0));
        cbGrayScale->setText(QApplication::translate("MainWindow", "GrayScale", 0));
        cvFlip->setText(QApplication::translate("MainWindow", "    Flip", 0));
        lblOriginal->setText(QString());
        lblProcessed->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
