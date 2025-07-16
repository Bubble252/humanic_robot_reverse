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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
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
    QGroupBox *jointControlBox;
    QGridLayout *jointGridLayout;
    QLabel *label12;
    QDoubleSpinBox *jointSpinBox_1;
    QCheckBox *jointLock_1;
    QLabel *label13;
    QDoubleSpinBox *jointSpinBox_2;
    QCheckBox *jointLock_2;
    QLabel *label14;
    QDoubleSpinBox *jointSpinBox_3;
    QCheckBox *jointLock_3;
    QLabel *label15;
    QDoubleSpinBox *jointSpinBox_4;
    QCheckBox *jointLock_4;
    QLabel *label16;
    QDoubleSpinBox *jointSpinBox_5;
    QCheckBox *jointLock_5;
    QLabel *label17;
    QDoubleSpinBox *jointSpinBox_6;
    QCheckBox *jointLock_6;
    QLabel *label18;
    QDoubleSpinBox *jointSpinBox_7;
    QCheckBox *jointLock_7;
    QLabel *label19;
    QDoubleSpinBox *jointSpinBox_8;
    QCheckBox *jointLock_8;
    QLabel *label20;
    QDoubleSpinBox *jointSpinBox_9;
    QCheckBox *jointLock_9;
    QLabel *label21;
    QDoubleSpinBox *jointSpinBox_10;
    QCheckBox *jointLock_10;
    QLabel *label22;
    QDoubleSpinBox *jointSpinBox_11;
    QCheckBox *jointLock_11;
    QLabel *label23;
    QDoubleSpinBox *jointSpinBox_12;
    QCheckBox *jointLock_12;
    QLabel *label24;
    QDoubleSpinBox *jointSpinBox_13;
    QCheckBox *jointLock_13;
    QLabel *label25;
    QDoubleSpinBox *jointSpinBox_14;
    QCheckBox *jointLock_14;
    QHBoxLayout *hboxLayout;
    QLabel *label26;
    QComboBox *solveTypeCombo;
    QHBoxLayout *hboxLayout1;
    QPushButton *sendButton_left;
    QPushButton *sendButton_right;

    void setupUi(QWidget *IKGui)
    {
        if (IKGui->objectName().isEmpty())
            IKGui->setObjectName(QString::fromUtf8("IKGui"));
        IKGui->resize(1000, 700);
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

        formLayout1->setWidget(0, QFormLayout::FieldRole, xSpinBox1);

        label1 = new QLabel(arm1GroupBox);
        label1->setObjectName(QString::fromUtf8("label1"));

        formLayout1->setWidget(1, QFormLayout::LabelRole, label1);

        ySpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        ySpinBox1->setObjectName(QString::fromUtf8("ySpinBox1"));

        formLayout1->setWidget(1, QFormLayout::FieldRole, ySpinBox1);

        label2 = new QLabel(arm1GroupBox);
        label2->setObjectName(QString::fromUtf8("label2"));

        formLayout1->setWidget(2, QFormLayout::LabelRole, label2);

        zSpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        zSpinBox1->setObjectName(QString::fromUtf8("zSpinBox1"));

        formLayout1->setWidget(2, QFormLayout::FieldRole, zSpinBox1);

        label3 = new QLabel(arm1GroupBox);
        label3->setObjectName(QString::fromUtf8("label3"));

        formLayout1->setWidget(3, QFormLayout::LabelRole, label3);

        rollSpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        rollSpinBox1->setObjectName(QString::fromUtf8("rollSpinBox1"));

        formLayout1->setWidget(3, QFormLayout::FieldRole, rollSpinBox1);

        label4 = new QLabel(arm1GroupBox);
        label4->setObjectName(QString::fromUtf8("label4"));

        formLayout1->setWidget(4, QFormLayout::LabelRole, label4);

        pitchSpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        pitchSpinBox1->setObjectName(QString::fromUtf8("pitchSpinBox1"));

        formLayout1->setWidget(4, QFormLayout::FieldRole, pitchSpinBox1);

        label5 = new QLabel(arm1GroupBox);
        label5->setObjectName(QString::fromUtf8("label5"));

        formLayout1->setWidget(5, QFormLayout::LabelRole, label5);

        yawSpinBox1 = new QDoubleSpinBox(arm1GroupBox);
        yawSpinBox1->setObjectName(QString::fromUtf8("yawSpinBox1"));

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

        formLayout2->setWidget(0, QFormLayout::FieldRole, xSpinBox2);

        label7 = new QLabel(arm2GroupBox);
        label7->setObjectName(QString::fromUtf8("label7"));

        formLayout2->setWidget(1, QFormLayout::LabelRole, label7);

        ySpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        ySpinBox2->setObjectName(QString::fromUtf8("ySpinBox2"));

        formLayout2->setWidget(1, QFormLayout::FieldRole, ySpinBox2);

        label8 = new QLabel(arm2GroupBox);
        label8->setObjectName(QString::fromUtf8("label8"));

        formLayout2->setWidget(2, QFormLayout::LabelRole, label8);

        zSpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        zSpinBox2->setObjectName(QString::fromUtf8("zSpinBox2"));

        formLayout2->setWidget(2, QFormLayout::FieldRole, zSpinBox2);

        label9 = new QLabel(arm2GroupBox);
        label9->setObjectName(QString::fromUtf8("label9"));

        formLayout2->setWidget(3, QFormLayout::LabelRole, label9);

        rollSpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        rollSpinBox2->setObjectName(QString::fromUtf8("rollSpinBox2"));

        formLayout2->setWidget(3, QFormLayout::FieldRole, rollSpinBox2);

        label10 = new QLabel(arm2GroupBox);
        label10->setObjectName(QString::fromUtf8("label10"));

        formLayout2->setWidget(4, QFormLayout::LabelRole, label10);

        pitchSpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        pitchSpinBox2->setObjectName(QString::fromUtf8("pitchSpinBox2"));

        formLayout2->setWidget(4, QFormLayout::FieldRole, pitchSpinBox2);

        label11 = new QLabel(arm2GroupBox);
        label11->setObjectName(QString::fromUtf8("label11"));

        formLayout2->setWidget(5, QFormLayout::LabelRole, label11);

        yawSpinBox2 = new QDoubleSpinBox(arm2GroupBox);
        yawSpinBox2->setObjectName(QString::fromUtf8("yawSpinBox2"));

        formLayout2->setWidget(5, QFormLayout::FieldRole, yawSpinBox2);


        verticalLayout->addWidget(arm2GroupBox);

        jointControlBox = new QGroupBox(IKGui);
        jointControlBox->setObjectName(QString::fromUtf8("jointControlBox"));
        jointGridLayout = new QGridLayout(jointControlBox);
        jointGridLayout->setObjectName(QString::fromUtf8("jointGridLayout"));
        label12 = new QLabel(jointControlBox);
        label12->setObjectName(QString::fromUtf8("label12"));

        jointGridLayout->addWidget(label12, 0, 0, 1, 1);

        jointSpinBox_1 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_1->setObjectName(QString::fromUtf8("jointSpinBox_1"));

        jointGridLayout->addWidget(jointSpinBox_1, 0, 1, 1, 1);

        jointLock_1 = new QCheckBox(jointControlBox);
        jointLock_1->setObjectName(QString::fromUtf8("jointLock_1"));

        jointGridLayout->addWidget(jointLock_1, 0, 2, 1, 1);

        label13 = new QLabel(jointControlBox);
        label13->setObjectName(QString::fromUtf8("label13"));

        jointGridLayout->addWidget(label13, 1, 0, 1, 1);

        jointSpinBox_2 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_2->setObjectName(QString::fromUtf8("jointSpinBox_2"));

        jointGridLayout->addWidget(jointSpinBox_2, 1, 1, 1, 1);

        jointLock_2 = new QCheckBox(jointControlBox);
        jointLock_2->setObjectName(QString::fromUtf8("jointLock_2"));

        jointGridLayout->addWidget(jointLock_2, 1, 2, 1, 1);

        label14 = new QLabel(jointControlBox);
        label14->setObjectName(QString::fromUtf8("label14"));

        jointGridLayout->addWidget(label14, 2, 0, 1, 1);

        jointSpinBox_3 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_3->setObjectName(QString::fromUtf8("jointSpinBox_3"));

        jointGridLayout->addWidget(jointSpinBox_3, 2, 1, 1, 1);

        jointLock_3 = new QCheckBox(jointControlBox);
        jointLock_3->setObjectName(QString::fromUtf8("jointLock_3"));

        jointGridLayout->addWidget(jointLock_3, 2, 2, 1, 1);

        label15 = new QLabel(jointControlBox);
        label15->setObjectName(QString::fromUtf8("label15"));

        jointGridLayout->addWidget(label15, 3, 0, 1, 1);

        jointSpinBox_4 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_4->setObjectName(QString::fromUtf8("jointSpinBox_4"));

        jointGridLayout->addWidget(jointSpinBox_4, 3, 1, 1, 1);

        jointLock_4 = new QCheckBox(jointControlBox);
        jointLock_4->setObjectName(QString::fromUtf8("jointLock_4"));

        jointGridLayout->addWidget(jointLock_4, 3, 2, 1, 1);

        label16 = new QLabel(jointControlBox);
        label16->setObjectName(QString::fromUtf8("label16"));

        jointGridLayout->addWidget(label16, 4, 0, 1, 1);

        jointSpinBox_5 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_5->setObjectName(QString::fromUtf8("jointSpinBox_5"));

        jointGridLayout->addWidget(jointSpinBox_5, 4, 1, 1, 1);

        jointLock_5 = new QCheckBox(jointControlBox);
        jointLock_5->setObjectName(QString::fromUtf8("jointLock_5"));

        jointGridLayout->addWidget(jointLock_5, 4, 2, 1, 1);

        label17 = new QLabel(jointControlBox);
        label17->setObjectName(QString::fromUtf8("label17"));

        jointGridLayout->addWidget(label17, 5, 0, 1, 1);

        jointSpinBox_6 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_6->setObjectName(QString::fromUtf8("jointSpinBox_6"));

        jointGridLayout->addWidget(jointSpinBox_6, 5, 1, 1, 1);

        jointLock_6 = new QCheckBox(jointControlBox);
        jointLock_6->setObjectName(QString::fromUtf8("jointLock_6"));

        jointGridLayout->addWidget(jointLock_6, 5, 2, 1, 1);

        label18 = new QLabel(jointControlBox);
        label18->setObjectName(QString::fromUtf8("label18"));

        jointGridLayout->addWidget(label18, 6, 0, 1, 1);

        jointSpinBox_7 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_7->setObjectName(QString::fromUtf8("jointSpinBox_7"));

        jointGridLayout->addWidget(jointSpinBox_7, 6, 1, 1, 1);

        jointLock_7 = new QCheckBox(jointControlBox);
        jointLock_7->setObjectName(QString::fromUtf8("jointLock_7"));

        jointGridLayout->addWidget(jointLock_7, 6, 2, 1, 1);

        label19 = new QLabel(jointControlBox);
        label19->setObjectName(QString::fromUtf8("label19"));

        jointGridLayout->addWidget(label19, 0, 3, 1, 1);

        jointSpinBox_8 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_8->setObjectName(QString::fromUtf8("jointSpinBox_8"));

        jointGridLayout->addWidget(jointSpinBox_8, 0, 4, 1, 1);

        jointLock_8 = new QCheckBox(jointControlBox);
        jointLock_8->setObjectName(QString::fromUtf8("jointLock_8"));

        jointGridLayout->addWidget(jointLock_8, 0, 5, 1, 1);

        label20 = new QLabel(jointControlBox);
        label20->setObjectName(QString::fromUtf8("label20"));

        jointGridLayout->addWidget(label20, 1, 3, 1, 1);

        jointSpinBox_9 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_9->setObjectName(QString::fromUtf8("jointSpinBox_9"));

        jointGridLayout->addWidget(jointSpinBox_9, 1, 4, 1, 1);

        jointLock_9 = new QCheckBox(jointControlBox);
        jointLock_9->setObjectName(QString::fromUtf8("jointLock_9"));

        jointGridLayout->addWidget(jointLock_9, 1, 5, 1, 1);

        label21 = new QLabel(jointControlBox);
        label21->setObjectName(QString::fromUtf8("label21"));

        jointGridLayout->addWidget(label21, 2, 3, 1, 1);

        jointSpinBox_10 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_10->setObjectName(QString::fromUtf8("jointSpinBox_10"));

        jointGridLayout->addWidget(jointSpinBox_10, 2, 4, 1, 1);

        jointLock_10 = new QCheckBox(jointControlBox);
        jointLock_10->setObjectName(QString::fromUtf8("jointLock_10"));

        jointGridLayout->addWidget(jointLock_10, 2, 5, 1, 1);

        label22 = new QLabel(jointControlBox);
        label22->setObjectName(QString::fromUtf8("label22"));

        jointGridLayout->addWidget(label22, 3, 3, 1, 1);

        jointSpinBox_11 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_11->setObjectName(QString::fromUtf8("jointSpinBox_11"));

        jointGridLayout->addWidget(jointSpinBox_11, 3, 4, 1, 1);

        jointLock_11 = new QCheckBox(jointControlBox);
        jointLock_11->setObjectName(QString::fromUtf8("jointLock_11"));

        jointGridLayout->addWidget(jointLock_11, 3, 5, 1, 1);

        label23 = new QLabel(jointControlBox);
        label23->setObjectName(QString::fromUtf8("label23"));

        jointGridLayout->addWidget(label23, 4, 3, 1, 1);

        jointSpinBox_12 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_12->setObjectName(QString::fromUtf8("jointSpinBox_12"));

        jointGridLayout->addWidget(jointSpinBox_12, 4, 4, 1, 1);

        jointLock_12 = new QCheckBox(jointControlBox);
        jointLock_12->setObjectName(QString::fromUtf8("jointLock_12"));

        jointGridLayout->addWidget(jointLock_12, 4, 5, 1, 1);

        label24 = new QLabel(jointControlBox);
        label24->setObjectName(QString::fromUtf8("label24"));

        jointGridLayout->addWidget(label24, 5, 3, 1, 1);

        jointSpinBox_13 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_13->setObjectName(QString::fromUtf8("jointSpinBox_13"));

        jointGridLayout->addWidget(jointSpinBox_13, 5, 4, 1, 1);

        jointLock_13 = new QCheckBox(jointControlBox);
        jointLock_13->setObjectName(QString::fromUtf8("jointLock_13"));

        jointGridLayout->addWidget(jointLock_13, 5, 5, 1, 1);

        label25 = new QLabel(jointControlBox);
        label25->setObjectName(QString::fromUtf8("label25"));

        jointGridLayout->addWidget(label25, 6, 3, 1, 1);

        jointSpinBox_14 = new QDoubleSpinBox(jointControlBox);
        jointSpinBox_14->setObjectName(QString::fromUtf8("jointSpinBox_14"));

        jointGridLayout->addWidget(jointSpinBox_14, 6, 4, 1, 1);

        jointLock_14 = new QCheckBox(jointControlBox);
        jointLock_14->setObjectName(QString::fromUtf8("jointLock_14"));

        jointGridLayout->addWidget(jointLock_14, 6, 5, 1, 1);


        verticalLayout->addWidget(jointControlBox);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label26 = new QLabel(IKGui);
        label26->setObjectName(QString::fromUtf8("label26"));

        hboxLayout->addWidget(label26);

        solveTypeCombo = new QComboBox(IKGui);
        solveTypeCombo->addItem(QString());
        solveTypeCombo->addItem(QString());
        solveTypeCombo->addItem(QString());
        solveTypeCombo->setObjectName(QString::fromUtf8("solveTypeCombo"));

        hboxLayout->addWidget(solveTypeCombo);


        verticalLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        sendButton_left = new QPushButton(IKGui);
        sendButton_left->setObjectName(QString::fromUtf8("sendButton_left"));

        hboxLayout1->addWidget(sendButton_left);

        sendButton_right = new QPushButton(IKGui);
        sendButton_right->setObjectName(QString::fromUtf8("sendButton_right"));

        hboxLayout1->addWidget(sendButton_right);


        verticalLayout->addLayout(hboxLayout1);


        retranslateUi(IKGui);

        QMetaObject::connectSlotsByName(IKGui);
    } // setupUi

    void retranslateUi(QWidget *IKGui)
    {
        arm1GroupBox->setTitle(QApplication::translate("IKGui", "Arm Left Pose", nullptr));
        label->setText(QApplication::translate("IKGui", "X", nullptr));
        label1->setText(QApplication::translate("IKGui", "Y", nullptr));
        label2->setText(QApplication::translate("IKGui", "Z", nullptr));
        label3->setText(QApplication::translate("IKGui", "Roll", nullptr));
        label4->setText(QApplication::translate("IKGui", "Pitch", nullptr));
        label5->setText(QApplication::translate("IKGui", "Yaw", nullptr));
        arm2GroupBox->setTitle(QApplication::translate("IKGui", "Arm Right Pose", nullptr));
        label6->setText(QApplication::translate("IKGui", "X", nullptr));
        label7->setText(QApplication::translate("IKGui", "Y", nullptr));
        label8->setText(QApplication::translate("IKGui", "Z", nullptr));
        label9->setText(QApplication::translate("IKGui", "Roll", nullptr));
        label10->setText(QApplication::translate("IKGui", "Pitch", nullptr));
        label11->setText(QApplication::translate("IKGui", "Yaw", nullptr));
        jointControlBox->setTitle(QApplication::translate("IKGui", "Joint Control (14 joints)", nullptr));
        label12->setText(QApplication::translate("IKGui", "L-Joint 1", nullptr));
        jointLock_1->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label13->setText(QApplication::translate("IKGui", "L-Joint 2", nullptr));
        jointLock_2->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label14->setText(QApplication::translate("IKGui", "L-Joint 3", nullptr));
        jointLock_3->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label15->setText(QApplication::translate("IKGui", "L-Joint 4", nullptr));
        jointLock_4->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label16->setText(QApplication::translate("IKGui", "L-Joint 5", nullptr));
        jointLock_5->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label17->setText(QApplication::translate("IKGui", "L-Joint 6", nullptr));
        jointLock_6->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label18->setText(QApplication::translate("IKGui", "L-Joint 7", nullptr));
        jointLock_7->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label19->setText(QApplication::translate("IKGui", "R-Joint 1", nullptr));
        jointLock_8->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label20->setText(QApplication::translate("IKGui", "R-Joint 2", nullptr));
        jointLock_9->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label21->setText(QApplication::translate("IKGui", "R-Joint 3", nullptr));
        jointLock_10->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label22->setText(QApplication::translate("IKGui", "R-Joint 4", nullptr));
        jointLock_11->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label23->setText(QApplication::translate("IKGui", "R-Joint 5", nullptr));
        jointLock_12->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label24->setText(QApplication::translate("IKGui", "R-Joint 6", nullptr));
        jointLock_13->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label25->setText(QApplication::translate("IKGui", "R-Joint 7", nullptr));
        jointLock_14->setText(QApplication::translate("IKGui", "Lock", nullptr));
        label26->setText(QApplication::translate("IKGui", "Solve Type:", nullptr));
        solveTypeCombo->setItemText(0, QApplication::translate("IKGui", "Speed", nullptr));
        solveTypeCombo->setItemText(1, QApplication::translate("IKGui", "Distance", nullptr));
        solveTypeCombo->setItemText(2, QApplication::translate("IKGui", "Manipulation1", nullptr));

        sendButton_left->setText(QApplication::translate("IKGui", "Set Left Pose", nullptr));
        sendButton_right->setText(QApplication::translate("IKGui", "Set Right Pose", nullptr));
        Q_UNUSED(IKGui);
    } // retranslateUi

};

namespace Ui {
    class IKGui: public Ui_IKGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IK_GUI_H
