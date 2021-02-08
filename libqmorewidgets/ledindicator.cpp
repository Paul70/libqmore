#include "ledindicator.h"
#include <QTimerEvent>
#include <QPainter>
#include <QPen>

namespace QtWidgets {


std::map<LedIndicator::LedState, QColor> LedIndicator::sStateLightMap_
{
    {LedState::eNotActive, Qt::gray},
    {LedState::eReady, Qt::blue},
    {LedState::eSuccess, Qt::green},
    {LedState::eError, Qt::red},
    {LedState::eBussy, Qt::yellow},
    {LedState::eBlinking, Qt::yellow},
    {LedState::eOther, Qt::white},
};



LedIndicator::LedIndicator(QWidget *parent) :
    QWidget(parent),
    idTimer_{0},
    size_   {8},
    state_  (LedState::eNotActive),
    pattern_(Qt::SolidPattern)

{
    connect(this, &LedIndicator::repaintWidget, this, &LedIndicator::repaint);
}


LedIndicator::LedIndicator(const int size, QWidget *parent) :
    QWidget (parent),
    idTimer_{0},
    size_   {size},
    state_  (LedState::eNotActive),
    pattern_(Qt::SolidPattern)
{
    // set the size of the underlying (invisible) QWidger rectangle
    // this rectangel is the "frame" of the led circle
    setFixedSize(2*size_+3, 2*size_+3);

    connect(this, &LedIndicator::repaintWidget, this, &LedIndicator::repaint);
}


LedIndicator::LedIndicator(LedState ledState, QWidget *parent) :
    QWidget(parent),
    idTimer_{0},
    size_   {8},
    state_  (ledState),
    pattern_(Qt::SolidPattern)
{
    // set the size of the underlying (invisible) QWidger rectangle
    // this rectangel is the "frame" of the led circle
    setFixedSize(2*size_+3, 2*size_+3);

    connect(this, &LedIndicator::repaintWidget, this, &LedIndicator::repaint);
}


LedIndicator::LedIndicator(LedState ledState, QColor color, QWidget *parent) :
    QWidget (parent),
    idTimer_{0},
    size_   {8},
    state_  (ledState),
    pattern_(Qt::SolidPattern)
{
    // set the size of the underlying (invisible) QWidger rectangle
    // this rectangel is the "frame" of the led circle
    setFixedSize(2*size_+3, 2*size_+3);

    setColor(ledState, color);
    connect(this, &LedIndicator::repaintWidget, this, &LedIndicator::repaint);
}


LedIndicator::LedIndicator(const int size, LedState ledState, QWidget *parent) :
    QWidget (parent),
    idTimer_{0},
    size_   {size},
    state_  (ledState),
    pattern_(Qt::SolidPattern)
{
    // set the size of the underlying (invisible) QWidger rectangle
    // this rectangel is the "frame" of the led circle
    setFixedSize(2*size_+3, 2*size_+3);

    connect(this, &LedIndicator::repaintWidget, this, &LedIndicator::repaint);
}


LedIndicator::LedIndicator(int size, LedState ledState, QColor color, QWidget *parent) :
    QWidget (parent),
    idTimer_{0},
    size_   {size},
    state_  (ledState),
    pattern_(Qt::SolidPattern)
{
    // set the size of the underlying (invisible) QWidger rectangle
    // this rectangel is the "frame" of the led circle
    setFixedSize(2*size_+3, 2*size_+3);

    setColor(ledState, color);
    connect(this, &LedIndicator::repaintWidget, this, &LedIndicator::repaint);
}


void LedIndicator::setLedSize(int size)
{
    size_ = size;
    setFixedSize(2*size_+3, 2*size_+3);
    emit repaintWidget();
}


void LedIndicator::setColor(const LedState state, const QColor color)
{
    sStateLightMap_.at(state) = color;
}


QColor const & LedIndicator::getColor(const LedState state)
{
    return sStateLightMap_.at(state);
}


void LedIndicator::setState(const LedState state)
{
    state_ = state;
    if(state_ == LedState::eBlinking){
        idTimer_ = startTimer(400);
    }
    else if(state_ != LedState::eBlinking && idTimer_ != 0){
        killTimer(idTimer_);
        idTimer_ = 0;
    }
    emit repaintWidget();
}


void LedIndicator::paintEvent(QPaintEvent *)
{
    // setup pen and painter
    QPen * pen  = new QPen(Qt::black);
    pen->setWidth(2);
    QPainter painter(this);
    painter.setPen(*pen);

    if(state_ == LedState::eBlinking){
        painter.setBrush(QBrush(sStateLightMap_.at(LedState::eBlinking), pattern_));
        if(getColor(state_) == sStateLightMap_.at(LedState::eNotActive)){
            setColor(LedState::eBlinking, sStateLightMap_.at(LedState::eBussy));
        }
        else {
            setColor(LedState::eBlinking, sStateLightMap_.at(LedState::eNotActive));
        }
    }
    else {
        painter.setBrush(QBrush(sStateLightMap_.at(state_), pattern_));
    }
    painter.drawEllipse(QPointF(width()/2.0, height()/2.0), size_,size_);
}


void LedIndicator::timerEvent(QTimerEvent *)
{
    emit repaintWidget();
}

} // namespace QtWidgets





