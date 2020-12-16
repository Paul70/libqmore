#include <math.h>
#include "floatslider.h"

#include <QDebug>


namespace QtWidgets {


FloatSlider::FloatSlider(QWidget *parent) :
    QSlider   (parent),
    accuracy_ {SliderAccuracy::eDecPlaceOne}
{
    QSlider::setMaximum(QSlider::maximum() * scaling());
    connect(this, &QSlider::valueChanged, this, &FloatSlider::rescale);
}


FloatSlider::FloatSlider(const SliderAccuracy accuracy, QWidget  * parent) :
    QSlider   (parent),
    accuracy_ {accuracy}
{
    QSlider::setMaximum(QSlider::maximum() * scaling());
    connect(this, &QSlider::valueChanged, this, &FloatSlider::rescale);
}


FloatSlider::FloatSlider(const SliderAccuracy accuracy, const Qt::Orientation orientation, QWidget *parent) :
    QSlider   (parent),
    accuracy_ {accuracy}
{
    QSlider::setOrientation(orientation);
    QSlider::setMaximum(QSlider::maximum() * scaling());
    connect(this, &QSlider::valueChanged, this, &FloatSlider::rescale);
}


FloatSlider::~FloatSlider()
{

}


FloatSlider::SliderAccuracy FloatSlider::accuracy() const
{
    return accuracy_;
}


double FloatSlider::scaling() const
{
    switch (accuracy_) {
    case SliderAccuracy::eDecPlaceOne:   return 10.0;
        break;
    case SliderAccuracy::eDecPlaceTwo:   return 100.0;
        break;
    case SliderAccuracy::eDecPlaceThree: return 1000.0;
        break;
    default: return 10.0;
    }
}




void FloatSlider::setMaximum(const double max)
{
    QSlider::setMaximum(static_cast<int>(max * scaling()));
}



void FloatSlider::setMinimum(const double min)
{
    QSlider::setMinimum(static_cast<int>(min * scaling()));
}



double FloatSlider::maximum() const
{
    return static_cast<double>(QSlider::maximum() * 1 / scaling());
}



double FloatSlider::minimum() const
{
    return QSlider::minimum() * 1 / scaling();
}




void FloatSlider::setValue(const double newValue)
{
    QSlider::setValue(static_cast<int>(newValue * scaling() + ADD_));
}



double FloatSlider::value() const
{
    return QSlider::value() * 1 / scaling() +ADD_;
}



void FloatSlider::rescale(const int value)
{
    emit FloatSlider::valueChanged(value * 1 / scaling());
}

} // namespace QtCustomWidgets

