/********************************************************************************
** Form generated from reading UI file 'textured_marker_config.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTURED_MARKER_CONFIG_H
#define UI_TEXTURED_MARKER_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textured_marker_config
{
public:
    QGridLayout *gridLayout;
    QLabel *status;
    QLineEdit *topic;
    QLabel *label_2;
    QPushButton *selecttopic;
    QLabel *label;
    QPushButton *clear;
    QLabel *alphaLabel;
    QSlider *alphaSlide;

    void setupUi(QWidget *textured_marker_config)
    {
        if (textured_marker_config->objectName().isEmpty())
            textured_marker_config->setObjectName(QString::fromUtf8("textured_marker_config"));
        textured_marker_config->resize(400, 330);
        textured_marker_config->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(textured_marker_config);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(4);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        status = new QLabel(textured_marker_config);
        status->setObjectName(QString::fromUtf8("status"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(8);
        status->setFont(font);
        status->setStyleSheet(QString::fromUtf8(""));
        status->setWordWrap(true);

        gridLayout->addWidget(status, 5, 1, 1, 2);

        topic = new QLineEdit(textured_marker_config);
        topic->setObjectName(QString::fromUtf8("topic"));
        topic->setFont(font);

        gridLayout->addWidget(topic, 2, 1, 1, 1);

        label_2 = new QLabel(textured_marker_config);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        selecttopic = new QPushButton(textured_marker_config);
        selecttopic->setObjectName(QString::fromUtf8("selecttopic"));
        selecttopic->setMaximumSize(QSize(55, 16777215));
        selecttopic->setFont(font);
        selecttopic->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(selecttopic, 2, 2, 1, 1);

        label = new QLabel(textured_marker_config);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        clear = new QPushButton(textured_marker_config);
        clear->setObjectName(QString::fromUtf8("clear"));

        gridLayout->addWidget(clear, 4, 1, 1, 1);

        alphaLabel = new QLabel(textured_marker_config);
        alphaLabel->setObjectName(QString::fromUtf8("alphaLabel"));
        alphaLabel->setFont(font);

        gridLayout->addWidget(alphaLabel, 3, 0, 1, 1);

        alphaSlide = new QSlider(textured_marker_config);
        alphaSlide->setObjectName(QString::fromUtf8("alphaSlide"));
        alphaSlide->setMinimum(5);
        alphaSlide->setMaximum(25);
        alphaSlide->setValue(25);
        alphaSlide->setOrientation(Qt::Horizontal);
        alphaSlide->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(alphaSlide, 3, 1, 1, 1);


        retranslateUi(textured_marker_config);

        QMetaObject::connectSlotsByName(textured_marker_config);
    } // setupUi

    void retranslateUi(QWidget *textured_marker_config)
    {
        textured_marker_config->setWindowTitle(QCoreApplication::translate("textured_marker_config", "Form", nullptr));
        status->setText(QCoreApplication::translate("textured_marker_config", "No topic", nullptr));
        label_2->setText(QCoreApplication::translate("textured_marker_config", "Status:", nullptr));
        selecttopic->setText(QCoreApplication::translate("textured_marker_config", "Select", nullptr));
        label->setText(QCoreApplication::translate("textured_marker_config", "Topic:", nullptr));
        clear->setText(QCoreApplication::translate("textured_marker_config", " Clear All Markers", nullptr));
        alphaLabel->setText(QCoreApplication::translate("textured_marker_config", "Alpha:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class textured_marker_config: public Ui_textured_marker_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTURED_MARKER_CONFIG_H
