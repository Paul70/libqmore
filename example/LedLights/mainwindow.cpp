#include "mainwindow.h"
#include "libqmorewidgets/ledindicator.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    pCentralWidget_(new QWidget),
    pLedStateLabel_(new QLabel(tr("Led light state: not active"))),
    pLed_          (new QtWidgets::LedIndicator())
{
    createCentralWidget();
    setGeometry(200,300,350,180);
}


void MainWindow::changeState()
{
    switch (pLed_->getState()) {
        case QtWidgets::LedIndicator::LedState::eNotActive:
        pLed_->setState(QtWidgets::LedIndicator::LedState::eBussy);
        pLedStateLabel_->setText("Led light state: bussy");
        break;
        case QtWidgets::LedIndicator::LedState::eBussy:
        pLed_->setState(QtWidgets::LedIndicator::LedState::eSuccess);
        pLedStateLabel_->setText("Led light state: success");
        break;
        case QtWidgets::LedIndicator::LedState::eSuccess:
        pLed_->setState(QtWidgets::LedIndicator::LedState::eError);
        pLedStateLabel_->setText("Led light state: error");
        break;
        case QtWidgets::LedIndicator::LedState::eError:
        pLed_->setState(QtWidgets::LedIndicator::LedState::eReady);
        pLedStateLabel_->setText("Led light state: ready");
        break;
        case QtWidgets::LedIndicator::LedState::eReady:
        pLed_->setState(QtWidgets::LedIndicator::LedState::eBlinking);
        pLedStateLabel_->setText("Led light state: blinking");
        break;
        case QtWidgets::LedIndicator::LedState::eBlinking:
        pLed_->setState(QtWidgets::LedIndicator::LedState::eOther);
        pLedStateLabel_->setText("Led light state: other");
        break;
        case QtWidgets::LedIndicator::LedState::eOther:
        pLed_->setState(QtWidgets::LedIndicator::LedState::eNotActive);
        pLedStateLabel_->setText("Led light state: not active");
        break;
    }
}


void MainWindow::increaseLedRadius()
{
    pLed_->setLedSize(pLed_->getLedSize() + 5);
}


void MainWindow::createCentralWidget()
{
    pCentralWidget_ = new QWidget();
    setCentralWidget(pCentralWidget_);

    QGridLayout * layout = new QGridLayout;
    centralWidget()->setLayout(layout);

    layout->addWidget(pLed_, 0,0);
    layout->addWidget(pLedStateLabel_,0,1);
    QPushButton * buttonSwitch = new QPushButton(tr("Switch State"));
    layout->addWidget(buttonSwitch, 1, 1);
    QPushButton * buttonRadius = new QPushButton(tr("Increase Led Radius"));
    layout->addWidget(buttonRadius, 2, 1);

    connect(buttonSwitch, &QPushButton::clicked, this, &MainWindow::changeState);
    connect(buttonRadius, &QPushButton::clicked, this, &MainWindow::increaseLedRadius);
}

