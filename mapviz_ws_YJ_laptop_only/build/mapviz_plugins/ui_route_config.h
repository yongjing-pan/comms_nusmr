/********************************************************************************
** Form generated from reading UI file 'route_config.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTE_CONFIG_H
#define UI_ROUTE_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <mapviz/color_button.h>

QT_BEGIN_NAMESPACE

class Ui_route_config
{
public:
    QGridLayout *gridLayout;
    mapviz::ColorButton *positioncolor;
    QComboBox *drawstyle;
    QLabel *status;
    QLabel *label_3;
    QLabel *label;
    QPushButton *selecttopic;
    QLabel *label_7;
    mapviz::ColorButton *color;
    QLineEdit *positiontopic;
    QLineEdit *topic;
    QLabel *label_4;
    QPushButton *selectpositiontopic;
    QLabel *label_5;
    QLabel *label_2;
    QSlider *iconsize;
    QLabel *label_6;

    void setupUi(QWidget *route_config)
    {
        if (route_config->objectName().isEmpty())
            route_config->setObjectName(QString::fromUtf8("route_config"));
        route_config->resize(400, 300);
        route_config->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(route_config);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(4);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        positioncolor = new mapviz::ColorButton(route_config);
        positioncolor->setObjectName(QString::fromUtf8("positioncolor"));
        positioncolor->setMaximumSize(QSize(24, 24));

        gridLayout->addWidget(positioncolor, 8, 2, 1, 1);

        drawstyle = new QComboBox(route_config);
        drawstyle->addItem(QString());
        drawstyle->addItem(QString());
        drawstyle->setObjectName(QString::fromUtf8("drawstyle"));
        drawstyle->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(9);
        drawstyle->setFont(font);
        drawstyle->setMaxVisibleItems(2);
        drawstyle->setMinimumContentsLength(0);

        gridLayout->addWidget(drawstyle, 6, 2, 1, 1);

        status = new QLabel(route_config);
        status->setObjectName(QString::fromUtf8("status"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setPointSize(8);
        status->setFont(font1);
        status->setStyleSheet(QString::fromUtf8(""));
        status->setWordWrap(true);

        gridLayout->addWidget(status, 10, 2, 1, 2);

        label_3 = new QLabel(route_config);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(route_config);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        selecttopic = new QPushButton(route_config);
        selecttopic->setObjectName(QString::fromUtf8("selecttopic"));
        selecttopic->setMaximumSize(QSize(55, 16777215));
        selecttopic->setFont(font1);
        selecttopic->setCursor(QCursor(Qt::CrossCursor));
        selecttopic->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(selecttopic, 2, 3, 1, 1);

        label_7 = new QLabel(route_config);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        color = new mapviz::ColorButton(route_config);
        color->setObjectName(QString::fromUtf8("color"));
        color->setMaximumSize(QSize(24, 24));
        color->setAutoFillBackground(false);
        color->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(color, 3, 2, 1, 1);

        positiontopic = new QLineEdit(route_config);
        positiontopic->setObjectName(QString::fromUtf8("positiontopic"));

        gridLayout->addWidget(positiontopic, 7, 2, 1, 1);

        topic = new QLineEdit(route_config);
        topic->setObjectName(QString::fromUtf8("topic"));
        topic->setFont(font1);

        gridLayout->addWidget(topic, 2, 2, 1, 1);

        label_4 = new QLabel(route_config);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setPointSize(8);
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        selectpositiontopic = new QPushButton(route_config);
        selectpositiontopic->setObjectName(QString::fromUtf8("selectpositiontopic"));
        selectpositiontopic->setEnabled(true);
        selectpositiontopic->setMaximumSize(QSize(55, 16777215));
        selectpositiontopic->setFont(font2);

        gridLayout->addWidget(selectpositiontopic, 7, 3, 1, 1);

        label_5 = new QLabel(route_config);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        gridLayout->addWidget(label_5, 8, 0, 1, 1);

        label_2 = new QLabel(route_config);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 10, 0, 1, 1);

        iconsize = new QSlider(route_config);
        iconsize->setObjectName(QString::fromUtf8("iconsize"));
        iconsize->setMinimum(1);
        iconsize->setMaximum(30);
        iconsize->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(iconsize, 9, 2, 1, 1);

        label_6 = new QLabel(route_config);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        gridLayout->addWidget(label_6, 9, 0, 1, 1);


        retranslateUi(route_config);

        QMetaObject::connectSlotsByName(route_config);
    } // setupUi

    void retranslateUi(QWidget *route_config)
    {
        route_config->setWindowTitle(QCoreApplication::translate("route_config", "Form", nullptr));
        positioncolor->setText(QString());
        drawstyle->setItemText(0, QCoreApplication::translate("route_config", "lines", nullptr));
        drawstyle->setItemText(1, QCoreApplication::translate("route_config", "points", nullptr));

        status->setText(QCoreApplication::translate("route_config", "No topic", nullptr));
        label_3->setText(QCoreApplication::translate("route_config", "Color:", nullptr));
        label->setText(QCoreApplication::translate("route_config", "Topic:", nullptr));
        selecttopic->setText(QCoreApplication::translate("route_config", "Select", nullptr));
        label_7->setText(QCoreApplication::translate("route_config", "Draw Style:", nullptr));
        color->setText(QString());
        label_4->setText(QCoreApplication::translate("route_config", "Position Topic:", nullptr));
        selectpositiontopic->setText(QCoreApplication::translate("route_config", "Select", nullptr));
        label_5->setText(QCoreApplication::translate("route_config", "Waypoint Color:", nullptr));
        label_2->setText(QCoreApplication::translate("route_config", "Status:", nullptr));
        label_6->setText(QCoreApplication::translate("route_config", "Icon Size:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class route_config: public Ui_route_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTE_CONFIG_H
