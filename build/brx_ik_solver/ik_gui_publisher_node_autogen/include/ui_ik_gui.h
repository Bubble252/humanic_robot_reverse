/********************************************************************************
** Form generated from reading UI file 'ik_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IK_GUI_H
#define UI_IK_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IKGui
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *arm1GroupBox;
    QFormLayout *formLayout1;
    QLabel *label;
    QDoubleSpinBox *xSpinBox1;
    QLabel *label1;
    QDoubleSpinBox *ySpinBox1;
    QLabel *label2;
    QDoubleSpinBox *zSpinBox1;
    QLabel *label3;
    QDoubleSpinBox *rollSpinBox1;
    QLabel *label4;
    QDoubleSpinBox *pitchSpinBox1;
    QLabel *label5;
    QDoubleSpinBox *yawSpinBox1;
    QGroupBox *arm2GroupBox;
    QFormLayout *formLayout2;
    QLabel *label6;
    QDoubleSpinBox *xSpinBox2;
    QLabel *label7;
    QDoubleSpinBox *ySpinBox2;
    QLabel *label8;
    QDoubleSpinBox *zSpinBox2;
    QLabel *label9;
    QDoubleSpinBox *rollSpinBox2;
    QLabel *label10;
    QDoubleSpinBox *pitchSpinBox2;
    QLabel *label11;
    QDoubleSpinBox *yawSpinBox2;
    QPushButton *sendButton_left;
    QPushButton *sendButton_right;

    void setupUi(QWidget *IKGui)
    {
        if (IKGui->objectName().isEmpty())
            IKGui->setObjectName(QString::fromUtf8("IKGui"));
        IKGui->resize(600, 500);
        verticalLayout = new QVBoxLayout(IKGui);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        arm1GroupBox = new QGroupBox(IKGui);
        arm1GroupBox->setObjectName(QString::fromUtf8("arm1GroupBox"));
        formLayout1 = new QFormLayout(arm1GroupBox);
        formLayout1->setObjectName(QString::fromUtf8("formLayout1"));
        label = new QLabel(arm1GroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout1->setWidget(0, QFormLayout::LabelRole, label);

        xSpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        xSpinBox1->setObjectName(QString::fromUtf8("xSpinBox1"));
        xSpinBox1->setMinimum(-100.000000000000000);
        xSpinBox1->setMaximum(100.000000000000000);

        formLayout1->setWidget(0, QFormLayout::FieldRole, xSpinBox1);

        label1 = new QLabel(arm1GroupBox);
        label1->setObjectName(QString::fromUtf8("label1"));

        formLayout1->setWidget(1, QFormLayout::LabelRole, label1);

        ySpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        ySpinBox1->setObjectName(QString::fromUtf8("ySpinBox1"));
        ySpinBox1->setMinimum(-100.000000000000000);
        ySpinBox1->setMaximum(100.000000000000000);

        formLayout1->setWidget(1, QFormLayout::FieldRole, ySpinBox1);

        label2 = new QLabel(arm1GroupBox);
        label2->setObjectName(QString::fromUtf8("label2"));

        formLayout1->setWidget(2, QFormLayout::LabelRole, label2);

        zSpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        zSpinBox1->setObjectName(QString::fromUtf8("zSpinBox1"));
        zSpinBox1->setMinimum(-100.000000000000000);
        zSpinBox1->setMaximum(100.000000000000000);

        formLayout1->setWidget(2, QFormLayout::FieldRole, zSpinBox1);

        label3 = new QLabel(arm1GroupBox);
        label3->setObjectName(QString::fromUtf8("label3"));

        formLayout1->setWidget(3, QFormLayout::LabelRole, label3);

        rollSpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        rollSpinBox1->setObjectName(QString::fromUtf8("rollSpinBox1"));
        rollSpinBox1->setMinimum(-100.000000000000000);
        rollSpinBox1->setMaximum(100.000000000000000);

        formLayout1->setWidget(3, QFormLayout::FieldRole, rollSpinBox1);

        label4 = new QLabel(arm1GroupBox);
        label4->setObjectName(QString::fromUtf8("label4"));

        formLayout1->setWidget(4, QFormLayout::LabelRole, label4);

        pitchSpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        pitchSpinBox1->setObjectName(QString::fromUtf8("pitchSpinBox1"));
        pitchSpinBox1->setMinimum(-100.000000000000000);
        pitchSpinBox1->setMaximum(100.000000000000000);

        formLayout1->setWidget(4, QFormLayout::FieldRole, pitchSpinBox1);

        label5 = new QLabel(arm1GroupBox);
        label5->setObjectName(QString::fromUtf8("label5"));

        formLayout1->setWidget(5, QFormLayout::LabelRole, label5);

        yawSpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        yawSpinBox1->setObjectName(QString::fromUtf8("yawSpinBox1"));
        yawSpinBox1->setMinimum(-100.000000000000000);
        yawSpinBox1->setMaximum(100.000000000000000);

        formLayout1->setWidget(5, QFormLayout::FieldRole, yawSpinBox1);


        verticalLayout->addWidget(arm1GroupBox);

        arm2GroupBox = new QGroupBox(IKGui);
        arm2GroupBox->setObjectName(QString::fromUtf8("arm2GroupBox"));
        formLayout2 = new QFormLayout(arm2GroupBox);
        formLayout2->setObjectName(QString::fromUtf8("formLayout2"));
        label6 = new QLabel(arm2GroupBox);
        label6->setObjectName(QString::fromUtf8("label6"));

        formLayout2->setWidget(0, QFormLayout::LabelRole, label6);

        xSpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        xSpinBox2->setObjectName(QString::fromUtf8("xSpinBox2"));
        xSpinBox2->setMinimum(-100.000000000000000);
        xSpinBox2->setMaximum(100.000000000000000);

        formLayout2->setWidget(0, QFormLayout::FieldRole, xSpinBox2);

        label7 = new QLabel(arm2GroupBox);
        label7->setObjectName(QString::fromUtf8("label7"));

        formLayout2->setWidget(1, QFormLayout::LabelRole, label7);

        ySpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        ySpinBox2->setObjectName(QString::fromUtf8("ySpinBox2"));
        ySpinBox2->setMinimum(-100.000000000000000);
        ySpinBox2->setMaximum(100.000000000000000);

        formLayout2->setWidget(1, QFormLayout::FieldRole, ySpinBox2);

        label8 = new QLabel(arm2GroupBox);
        label8->setObjectName(QString::fromUtf8("label8"));

        formLayout2->setWidget(2, QFormLayout::LabelRole, label8);

        zSpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        zSpinBox2->setObjectName(QString::fromUtf8("zSpinBox2"));
        zSpinBox2->setMinimum(-100.000000000000000);
        zSpinBox2->setMaximum(100.000000000000000);

        formLayout2->setWidget(2, QFormLayout::FieldRole, zSpinBox2);

        label9 = new QLabel(arm2GroupBox);
        label9->setObjectName(QString::fromUtf8("label9"));

        formLayout2->setWidget(3, QFormLayout::LabelRole, label9);

        rollSpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        rollSpinBox2->setObjectName(QString::fromUtf8("rollSpinBox2"));
        rollSpinBox2->setMinimum(-100.000000000000000);
        rollSpinBox2->setMaximum(100.000000000000000);

        formLayout2->setWidget(3, QFormLayout::FieldRole, rollSpinBox2);

        label10 = new QLabel(arm2GroupBox);
        label10->setObjectName(QString::fromUtf8("label10"));

        formLayout2->setWidget(4, QFormLayout::LabelRole, label10);

        pitchSpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        pitchSpinBox2->setObjectName(QString::fromUtf8("pitchSpinBox2"));
        pitchSpinBox2->setMinimum(-100.000000000000000);
        pitchSpinBox2->setMaximum(100.000000000000000);

        formLayout2->setWidget(4, QFormLayout::FieldRole, pitchSpinBox2);

        label11 = new QLabel(arm2GroupBox);
        label11->setObjectName(QString::fromUtf8("label11"));

        formLayout2->setWidget(5, QFormLayout::LabelRole, label11);

        yawSpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        yawSpinBox2->setObjectName(QString::fromUtf8("yawSpinBox2"));
        yawSpinBox2->setMinimum(-100.000000000000000);
        yawSpinBox2->setMaximum(100.000000000000000);

        formLayout2->setWidget(5, QFormLayout::FieldRole, yawSpinBox2);


        verticalLayout->addWidget(arm2GroupBox);

        sendButton_left = new QPushButton(IKGui);
        sendButton_left->setObjectName(QString::fromUtf8("sendButton_left"));

        verticalLayout->addWidget(sendButton_left);

        sendButton_right = new QPushButton(IKGui);
        sendButton_right->setObjectName(QString::fromUtf8("sendButton_right"));

        verticalLayout->addWidget(sendButton_right);


        retranslateUi(IKGui);

        QMetaObject::connectSlotsByName(IKGui);
    } // setupUi

    void retranslateUi(QWidget *IKGui)
    {
        arm1GroupBox->setTitle(QApplication::translate("IKGui", "Arm left Pose", nullptr));
        label->setText(QApplication::translate("IKGui", "X", nullptr));
        label1->setText(QApplication::translate("IKGui", "Y", nullptr));
        label2->setText(QApplication::translate("IKGui", "Z", nullptr));
        label3->setText(QApplication::translate("IKGui", "Roll", nullptr));
        label4->setText(QApplication::translate("IKGui", "Pitch", nullptr));
        label5->setText(QApplication::translate("IKGui", "Yaw", nullptr));
        arm2GroupBox->setTitle(QApplication::translate("IKGui", "Arm right Pose", nullptr));
        label6->setText(QApplication::translate("IKGui", "X", nullptr));
        label7->setText(QApplication::translate("IKGui", "Y", nullptr));
        label8->setText(QApplication::translate("IKGui", "Z", nullptr));
        label9->setText(QApplication::translate("IKGui", "Roll", nullptr));
        label10->setText(QApplication::translate("IKGui", "Pitch", nullptr));
        label11->setText(QApplication::translate("IKGui", "Yaw", nullptr));
        sendButton_left->setText(QApplication::translate("IKGui", "Set left Poses", nullptr));
        sendButton_right->setText(QApplication::translate("IKGui", "Set right Poses", nullptr));
        Q_UNUSED(IKGui);
    } // retranslateUi

};

namespace Ui {
    class IKGui: public Ui_IKGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IK_GUI_H
