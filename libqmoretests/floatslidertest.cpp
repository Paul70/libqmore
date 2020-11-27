#include "floatslidertest.h"

using namespace QtWidgets;

FloatSliderTest::FloatSliderTest() :
    sliderAccuruacyOne_  (FloatSlider::SliderAccuracy::eDecPlaceOne),
    sliderAccuruacyTwo_  (FloatSlider::SliderAccuracy::eDecPlaceTwo),
    sliderAccuruacyThree_(FloatSlider::SliderAccuracy::eDecPlaceThree)
{
}


TEST_F(FloatSliderTest, accuracyWorks)
{
    EXPECT_TRUE(sliderAccuruacyOne_.accuracy() == FloatSlider::SliderAccuracy::eDecPlaceOne ||
                sliderAccuruacyOne_.accuracy() == FloatSlider::SliderAccuracy::eDecPlaceTwo ||
                sliderAccuruacyOne_.accuracy() == FloatSlider::SliderAccuracy::eDecPlaceThree);
};


TEST_F(FloatSliderTest, maximumWorks)
{
    EXPECT_TRUE(sliderAccuruacyOne_.maximum() < 99.1 && sliderAccuruacyOne_.maximum() > 89.9);
    EXPECT_TRUE(sliderAccuruacyTwo_.maximum() < 99.01 && sliderAccuruacyOne_.maximum() > 89.99);
    EXPECT_TRUE(sliderAccuruacyTwo_.maximum() < 99.001 && sliderAccuruacyOne_.maximum() > 89.999);
};


TEST_F(FloatSliderTest, setMaximumWorks)
{
    sliderAccuruacyTwo_.setMaximum(777.77);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyTwo_.maximum() * 100.0) == 77777);
};







