#include "ledindicatorbulb.h"

#include <QPainter>

LedIndicatorBulb::LedIndicatorBulb(QWidget *parent) :
    QWidget(parent),

    color_     (),
    ledPattern_{Qt::SolidPattern},
    state_     {LedState::eNotActive},
    ledSize_   {8}
{
    setFixedSize(30, 30);
}



LedIndicatorBulb::~LedIndicatorBulb()
{

}



void LedIndicatorBulb::setLedSize(int size)
{
    ledSize_ = size;
    setFixedSize(size+10, size+10);
    repaint();
}



void LedIndicatorBulb::setCustomColor(const QColor color)
{
    color_ = color;
    repaint();
}




void LedIndicatorBulb::setState(const LedState state)
{
    state_ = state;
    repaint();
}


LedState LedIndicatorBulb::getState() const
{
    return state_;
}




void LedIndicatorBulb::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    switch (state_) {
        case LedState::eNotActive:
        color_ = Qt::gray;
        painter.setBrush(QBrush(color_, ledPattern_));
        break;

        case LedState::eBussy:
        color_ = Qt::yellow;
        painter.setBrush(QBrush(color_, ledPattern_));
        break;

        case LedState::eReady:
        color_ = Qt::blue;
        painter.setBrush(QBrush(color_, ledPattern_));
        break;

        case LedState::eSuccess:
        color_ = Qt::green;
        painter.setBrush(QBrush(color_, ledPattern_));
        break;

        case LedState::eError:
        color_ = Qt::red;
        painter.setBrush(QBrush(color_, ledPattern_));
        break;
    }

    painter.drawEllipse(QPointF(width()/2.0, height()/2.0), ledSize_,ledSize_);
}
