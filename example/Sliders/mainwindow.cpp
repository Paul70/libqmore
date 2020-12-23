#include "mainwindow.h"
#include "libqmorewidgets/floatslider.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),

    pCentralWidget_      (new QWidget(this)),
    pSliderDecPointOne_  (new QtWidgets::FloatSlider(QtWidgets::FloatSlider::SliderAccuracy::eDecPlaceOne,
                                                     Qt::Orientation::Horizontal)),
    pSliderDecPointTwo_  (new QtWidgets::FloatSlider(QtWidgets::FloatSlider::SliderAccuracy::eDecPlaceTwo,
                                                     Qt::Orientation::Horizontal)),
    pSliderDecPointThree_(new QtWidgets::FloatSlider(QtWidgets::FloatSlider::SliderAccuracy::eDecPlaceThree,
                                                     Qt::Orientation::Horizontal)),
    pValueLabelSliderOne_  (new QLabel()),
    pValueLabelSliderTwo_  (new QLabel()),
    pValueLabelSliderThree_(new QLabel())
{
    createWidgets();
}


void MainWindow::onButtonLeftSliderOneClicked()
{
    // decrease slider value for 0.1
    pSliderDecPointOne_->setValue(pSliderDecPointOne_->value() - 0.1);
    QString str;
    pValueLabelSliderOne_->setText(str.setNum(pSliderDecPointOne_->value(),'f', 1));

}


void MainWindow::onButtonRightSliderOneClicked()
{
    // increase slider value for 0.1
    pSliderDecPointOne_->setValue(pSliderDecPointOne_->value() + 0.1);
    QString str;
    pValueLabelSliderOne_->setText(str.setNum(pSliderDecPointOne_->value(),'f', 1));
}


void MainWindow::onButtonLeftSliderTwoClicked()
{
    // decrease slider value for 0.01
}


void MainWindow::onButtonRightSliderTwoClicked()
{
    // increase slider value for 0.01

}


void MainWindow::onButtonLeftSliderThreeClicked()
{
    // decrease slider value for 0.001
}


void MainWindow::onButtonRightSliderThreeClicked()
{
    // increase slider value for 0.001

}


void MainWindow::createWidgets()
{
    setCentralWidget(pCentralWidget_);
    QGridLayout * pMainLayout = new QGridLayout;
    centralWidget()->setLayout(pMainLayout);

    // create first slider
    QLabel * pLabelHeadOne = new QLabel("First Slider with one decimal place:");
    QLabel * pLabelFieldSliderOne = new QLabel("current value:");
    pMainLayout->addWidget(pLabelHeadOne,0,0,1,1);
    pMainLayout->addWidget(pLabelFieldSliderOne,1,1,1,1);
    pSliderDecPointOne_->setMaximum(10.0);
    pMainLayout->addWidget(pSliderDecPointOne_,0,1,1,4);

    QString str;
    pValueLabelSliderOne_->setText(str.setNum(pSliderDecPointOne_->value(),'f', 1));
    pMainLayout->addWidget(pValueLabelSliderOne_,1,2,1,1);
    QPushButton * pButtonLeftS1 = new QPushButton("<");
    QPushButton * pButtonRightS1 = new QPushButton(">");
    pMainLayout->addWidget(pButtonLeftS1,1,3,1,1);
    pMainLayout->addWidget(pButtonRightS1,1,4,1,1);

    //connections
    connect(pButtonLeftS1,  &QPushButton::clicked, this, &MainWindow::onButtonLeftSliderOneClicked);
    connect(pButtonRightS1, &QPushButton::clicked, this, &MainWindow::onButtonRightSliderOneClicked);


    // create second slider
    QLabel * pLabelHeadTwo = new QLabel("Second Slider with two decimal places:");
    QLabel * pLabelFieldSliderTwo = new QLabel("current value:");
    pMainLayout->addWidget(pLabelHeadTwo,2,0,1,1);
    pSliderDecPointTwo_->setMaximum(10.0);
    pMainLayout->addWidget(pSliderDecPointTwo_,2,1,1,4);
    pMainLayout->addWidget(pLabelFieldSliderTwo,3,1,1,1);

    pValueLabelSliderTwo_->setText(str.setNum(pSliderDecPointTwo_->value(),'f', 2));
    pMainLayout->addWidget(pValueLabelSliderTwo_,3,2,1,1);
    QPushButton * pButtonLeftS2 = new QPushButton("<");
    QPushButton * pButtonRightS2 = new QPushButton(">");
    pMainLayout->addWidget(pButtonLeftS2,3,3,1,1);
    pMainLayout->addWidget(pButtonRightS2,3,4,1,1);

    //connections
    connect(pButtonLeftS2, &QPushButton::clicked, this, &MainWindow::onButtonLeftSliderTwoClicked);
    connect(pButtonRightS2, &QPushButton::clicked, this, &MainWindow::onButtonRightSliderTwoClicked);


    // create third slider
    QLabel * pLabelHeadThree = new QLabel("Third Slider with three decimal places:");
    QLabel * pLabelFieldSliderThree = new QLabel("current value:");
    pMainLayout->addWidget(pLabelHeadThree,4,0,1,1);
    pSliderDecPointThree_->setMaximum(10.0);
    pMainLayout->addWidget(pSliderDecPointThree_,4,1,1,4);
    pMainLayout->addWidget(pLabelFieldSliderThree,5,1,1,1);

    pValueLabelSliderThree_->setText(str.setNum(pSliderDecPointOne_->value(),'f', 3));
    pMainLayout->addWidget(pValueLabelSliderThree_,5,2,1,1);
    QPushButton * pButtonLeftS3 = new QPushButton("<");
    QPushButton * pButtonRightS3 = new QPushButton(">");
    pMainLayout->addWidget(pButtonLeftS3,5,3,1,1);
    pMainLayout->addWidget(pButtonRightS3,5,4,1,1);

    // connections
    connect(pButtonLeftS3, &QPushButton::clicked, this, &MainWindow::onButtonLeftSliderThreeClicked);
    connect(pButtonRightS3, &QPushButton::clicked, this, &MainWindow::onButtonRightSliderThreeClicked);
}

























