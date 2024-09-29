/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *clock;
    QLabel *counter;
    QProgressBar *progressBar;
    QPushButton *showHistory;
    QPushButton *exitButton;
    QWebEngineView *field;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1010, 661);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(800, 554));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        clock = new QLabel(centralwidget);
        clock->setObjectName("clock");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(clock->sizePolicy().hasHeightForWidth());
        clock->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier Prime")});
        font.setPointSize(12);
        font.setBold(false);
        clock->setFont(font);
        clock->setTextFormat(Qt::TextFormat::AutoText);
        clock->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);

        verticalLayout->addWidget(clock);

        counter = new QLabel(centralwidget);
        counter->setObjectName("counter");
        sizePolicy1.setHeightForWidth(counter->sizePolicy().hasHeightForWidth());
        counter->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Courier Prime")});
        font1.setPointSize(12);
        font1.setBold(true);
        counter->setFont(font1);
        counter->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);

        verticalLayout->addWidget(counter);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy2);
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        showHistory = new QPushButton(centralwidget);
        showHistory->setObjectName("showHistory");
        sizePolicy1.setHeightForWidth(showHistory->sizePolicy().hasHeightForWidth());
        showHistory->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(showHistory);

        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(exitButton);


        horizontalLayout->addLayout(verticalLayout);

        field = new QWebEngineView(centralwidget);
        field->setObjectName("field");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(field->sizePolicy().hasHeightForWidth());
        field->setSizePolicy(sizePolicy3);
        field->setUrl(QUrl(QString::fromUtf8("https://www.wikipedia.org/")));

        horizontalLayout->addWidget(field);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1010, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "wikiLYNX", nullptr));
#if QT_CONFIG(whatsthis)
        clock->setWhatsThis(QCoreApplication::translate("MainWindow", "Current System Time", nullptr));
#endif // QT_CONFIG(whatsthis)
        clock->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        counter->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        showHistory->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
