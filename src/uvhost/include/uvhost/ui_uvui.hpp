/********************************************************************************
** Form generated from reading UI file 'uvui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UVUI_H
#define UI_UVUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UVUI
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBoxUvList;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxSelect;
    QCheckBox *checkBoxRemote;
    QListWidget *listWidgetUvList;
    QPushButton *pushButtonRefresh;
    QGroupBox *groupBoxStatus;
    QGridLayout *gridLayout_2;
    QTableView *tableViewStatus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UVUI)
    {
        if (UVUI->objectName().isEmpty())
            UVUI->setObjectName("UVUI");
        UVUI->resize(800, 600);
        centralwidget = new QWidget(UVUI);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        groupBoxUvList = new QGroupBox(centralwidget);
        groupBoxUvList->setObjectName("groupBoxUvList");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBoxUvList->sizePolicy().hasHeightForWidth());
        groupBoxUvList->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBoxUvList);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        comboBoxSelect = new QComboBox(groupBoxUvList);
        comboBoxSelect->setObjectName("comboBoxSelect");

        horizontalLayout->addWidget(comboBoxSelect);

        checkBoxRemote = new QCheckBox(groupBoxUvList);
        checkBoxRemote->setObjectName("checkBoxRemote");

        horizontalLayout->addWidget(checkBoxRemote);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        listWidgetUvList = new QListWidget(groupBoxUvList);
        listWidgetUvList->setObjectName("listWidgetUvList");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidgetUvList->sizePolicy().hasHeightForWidth());
        listWidgetUvList->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(listWidgetUvList, 1, 0, 1, 1);

        pushButtonRefresh = new QPushButton(groupBoxUvList);
        pushButtonRefresh->setObjectName("pushButtonRefresh");

        gridLayout->addWidget(pushButtonRefresh, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxUvList, 0, 0, 1, 1);

        groupBoxStatus = new QGroupBox(centralwidget);
        groupBoxStatus->setObjectName("groupBoxStatus");
        gridLayout_2 = new QGridLayout(groupBoxStatus);
        gridLayout_2->setObjectName("gridLayout_2");
        tableViewStatus = new QTableView(groupBoxStatus);
        tableViewStatus->setObjectName("tableViewStatus");

        gridLayout_2->addWidget(tableViewStatus, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxStatus, 0, 1, 1, 1);

        UVUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UVUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        UVUI->setMenuBar(menubar);
        statusbar = new QStatusBar(UVUI);
        statusbar->setObjectName("statusbar");
        UVUI->setStatusBar(statusbar);

        retranslateUi(UVUI);

        QMetaObject::connectSlotsByName(UVUI);
    } // setupUi

    void retranslateUi(QMainWindow *UVUI)
    {
        UVUI->setWindowTitle(QCoreApplication::translate("UVUI", "MainWindow", nullptr));
        groupBoxUvList->setTitle(QCoreApplication::translate("UVUI", "uvList", nullptr));
        checkBoxRemote->setText(QCoreApplication::translate("UVUI", "RemoteControl", nullptr));
        pushButtonRefresh->setText(QCoreApplication::translate("UVUI", "refresh", nullptr));
        groupBoxStatus->setTitle(QCoreApplication::translate("UVUI", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UVUI: public Ui_UVUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UVUI_H
