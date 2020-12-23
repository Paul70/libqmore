#ifndef FLOATSLIDERTEST_H
#define FLOATSLIDERTEST_H

#include <gtest/gtest.h>
#include <QApplication>
#include "libqmorewidgets/floatslider.h"




class FloatSliderTest : public::testing::Test
{
protected:
    explicit FloatSliderTest();

    ~FloatSliderTest() = default;

    static constexpr double ADD_ {0.00001};

    QtWidgets::FloatSlider sliderAccuruacyOne_;
    QtWidgets::FloatSlider sliderAccuruacyTwo_;
    QtWidgets::FloatSlider sliderAccuruacyThree_;



};

#endif // FLOATSLIDERTEST_H
