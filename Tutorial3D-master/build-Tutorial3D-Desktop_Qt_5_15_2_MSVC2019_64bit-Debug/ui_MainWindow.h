/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *showModelButton;
    QPushButton *materialButtton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ambientButton;
    QPushButton *diffuseButton;
    QPushButton *specularButton;
    QLabel *label;
    QLineEdit *shininessEdit;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        showModelButton = new QPushButton(centralwidget);
        showModelButton->setObjectName(QString::fromUtf8("showModelButton"));

        horizontalLayout->addWidget(showModelButton);

        materialButtton = new QPushButton(centralwidget);
        materialButtton->setObjectName(QString::fromUtf8("materialButtton"));
        materialButtton->setCheckable(true);

        horizontalLayout->addWidget(materialButtton);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ambientButton = new QPushButton(groupBox);
        ambientButton->setObjectName(QString::fromUtf8("ambientButton"));

        horizontalLayout_2->addWidget(ambientButton);

        diffuseButton = new QPushButton(groupBox);
        diffuseButton->setObjectName(QString::fromUtf8("diffuseButton"));

        horizontalLayout_2->addWidget(diffuseButton);

        specularButton = new QPushButton(groupBox);
        specularButton->setObjectName(QString::fromUtf8("specularButton"));

        horizontalLayout_2->addWidget(specularButton);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        shininessEdit = new QLineEdit(groupBox);
        shininessEdit->setObjectName(QString::fromUtf8("shininessEdit"));

        horizontalLayout_2->addWidget(shininessEdit);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(materialButtton, SIGNAL(toggled(bool)), groupBox, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qt3D\346\225\231\347\250\213", nullptr));
        showModelButton->setText(QCoreApplication::translate("MainWindow", "\351\232\220\350\227\217\346\250\241\345\236\213", nullptr));
        materialButtton->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\235\220\350\264\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\235\220\350\264\250\344\277\241\346\201\257", nullptr));
        ambientButton->setText(QCoreApplication::translate("MainWindow", "\347\216\257\345\242\203\345\205\211", nullptr));
        diffuseButton->setText(QCoreApplication::translate("MainWindow", "\346\274\253\345\217\215\345\260\204", nullptr));
        specularButton->setText(QCoreApplication::translate("MainWindow", "\351\225\234\351\235\242\345\217\215\345\260\204", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\225\234\351\235\242\347\263\273\346\225\260", nullptr));
        shininessEdit->setText(QCoreApplication::translate("MainWindow", "0.6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
