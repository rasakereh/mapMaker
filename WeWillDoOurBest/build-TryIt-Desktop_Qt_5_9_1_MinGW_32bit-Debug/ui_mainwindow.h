/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "headers/MapDraft.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectionTool_button;
    QPushButton *ordinaryCell_button;
    QPushButton *treasureCell_button;
    QPushButton *initialCell_button;
    QPushButton *decisionCell_button;
    QPushButton *transportCell_button;
    QPushButton *delete_button;
    MapDraft *mapDraft_frm;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *save_button;
    QPushButton *load_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(858, 550);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(100, 0, 642, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 5);
        selectionTool_button = new QPushButton(horizontalLayoutWidget);
        selectionTool_button->setObjectName(QStringLiteral("selectionTool_button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectionTool_button->sizePolicy().hasHeightForWidth());
        selectionTool_button->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/SelectionTool.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectionTool_button->setIcon(icon);

        horizontalLayout->addWidget(selectionTool_button);

        ordinaryCell_button = new QPushButton(horizontalLayoutWidget);
        ordinaryCell_button->setObjectName(QStringLiteral("ordinaryCell_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ordinaryCell_button->sizePolicy().hasHeightForWidth());
        ordinaryCell_button->setSizePolicy(sizePolicy1);
        ordinaryCell_button->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/OrdinaryCell.png"), QSize(), QIcon::Normal, QIcon::Off);
        ordinaryCell_button->setIcon(icon1);

        horizontalLayout->addWidget(ordinaryCell_button);

        treasureCell_button = new QPushButton(horizontalLayoutWidget);
        treasureCell_button->setObjectName(QStringLiteral("treasureCell_button"));
        sizePolicy1.setHeightForWidth(treasureCell_button->sizePolicy().hasHeightForWidth());
        treasureCell_button->setSizePolicy(sizePolicy1);
        treasureCell_button->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/TreasureCell.png"), QSize(), QIcon::Normal, QIcon::Off);
        treasureCell_button->setIcon(icon2);

        horizontalLayout->addWidget(treasureCell_button);

        initialCell_button = new QPushButton(horizontalLayoutWidget);
        initialCell_button->setObjectName(QStringLiteral("initialCell_button"));
        sizePolicy.setHeightForWidth(initialCell_button->sizePolicy().hasHeightForWidth());
        initialCell_button->setSizePolicy(sizePolicy);
        initialCell_button->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/InitialCell.png"), QSize(), QIcon::Normal, QIcon::Off);
        initialCell_button->setIcon(icon3);

        horizontalLayout->addWidget(initialCell_button);

        decisionCell_button = new QPushButton(horizontalLayoutWidget);
        decisionCell_button->setObjectName(QStringLiteral("decisionCell_button"));
        sizePolicy.setHeightForWidth(decisionCell_button->sizePolicy().hasHeightForWidth());
        decisionCell_button->setSizePolicy(sizePolicy);
        decisionCell_button->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/DecisionCell.png"), QSize(), QIcon::Normal, QIcon::Off);
        decisionCell_button->setIcon(icon4);

        horizontalLayout->addWidget(decisionCell_button);

        transportCell_button = new QPushButton(horizontalLayoutWidget);
        transportCell_button->setObjectName(QStringLiteral("transportCell_button"));
        sizePolicy.setHeightForWidth(transportCell_button->sizePolicy().hasHeightForWidth());
        transportCell_button->setSizePolicy(sizePolicy);
        transportCell_button->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/TransportCell.png"), QSize(), QIcon::Normal, QIcon::Off);
        transportCell_button->setIcon(icon5);

        horizontalLayout->addWidget(transportCell_button);

        delete_button = new QPushButton(horizontalLayoutWidget);
        delete_button->setObjectName(QStringLiteral("delete_button"));
        sizePolicy.setHeightForWidth(delete_button->sizePolicy().hasHeightForWidth());
        delete_button->setSizePolicy(sizePolicy);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        delete_button->setIcon(icon6);

        horizontalLayout->addWidget(delete_button);

        mapDraft_frm = new MapDraft(centralWidget);
        mapDraft_frm->setObjectName(QStringLiteral("mapDraft_frm"));
        mapDraft_frm->setGeometry(QRect(70, 50, 711, 331));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mapDraft_frm->sizePolicy().hasHeightForWidth());
        mapDraft_frm->setSizePolicy(sizePolicy2);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(207, 255, 199, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(231, 255, 227, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(103, 127, 99, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(138, 170, 133, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        mapDraft_frm->setPalette(palette);
        mapDraft_frm->setCursor(QCursor(Qt::ArrowCursor));
        mapDraft_frm->setAutoFillBackground(true);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(350, 410, 141, 71));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        save_button = new QPushButton(verticalLayoutWidget);
        save_button->setObjectName(QStringLiteral("save_button"));
        sizePolicy.setHeightForWidth(save_button->sizePolicy().hasHeightForWidth());
        save_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(save_button);

        load_button = new QPushButton(verticalLayoutWidget);
        load_button->setObjectName(QStringLiteral("load_button"));
        sizePolicy.setHeightForWidth(load_button->sizePolicy().hasHeightForWidth());
        load_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(load_button);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 858, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        selectionTool_button->setText(QApplication::translate("MainWindow", "SelectionTool", Q_NULLPTR));
        ordinaryCell_button->setText(QApplication::translate("MainWindow", "Ordinary Cell", Q_NULLPTR));
        treasureCell_button->setText(QApplication::translate("MainWindow", "Treasure Cell", Q_NULLPTR));
        initialCell_button->setText(QApplication::translate("MainWindow", "Initial Cell", Q_NULLPTR));
        decisionCell_button->setText(QApplication::translate("MainWindow", "Decision Cell", Q_NULLPTR));
        transportCell_button->setText(QApplication::translate("MainWindow", "Transport Cell", Q_NULLPTR));
        delete_button->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        save_button->setText(QApplication::translate("MainWindow", "&Save...", Q_NULLPTR));
        load_button->setText(QApplication::translate("MainWindow", "&Load...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
