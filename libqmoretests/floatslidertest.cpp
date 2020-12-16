#include "floatslidertest.h"

using namespace QtWidgets;

FloatSliderTest::FloatSliderTest() :
    sliderAccuruacyOne_  (FloatSlider::SliderAccuracy::eDecPlaceOne),
    sliderAccuruacyTwo_  (FloatSlider::SliderAccuracy::eDecPlaceTwo),
    sliderAccuruacyThree_(FloatSlider::SliderAccuracy::eDecPlaceThree)
{
}

TEST_F(FloatSliderTest, valueWorks)
{
    // first, each slider should return the default value which is (double)0.0
    auto value = sliderAccuruacyOne_.value();
    bool isDouble = std::is_same<decltype (value), double>::value;
    EXPECT_TRUE(isDouble && value > -0.99999 && value < 0.0001);

    value = sliderAccuruacyTwo_.value();
    isDouble = std::is_same<decltype (value), double>::value;
    EXPECT_TRUE(isDouble && value > -0.99999 && value < 0.0001);

    value = sliderAccuruacyThree_.value();
    isDouble = std::is_same<decltype (value), double>::value;
    EXPECT_TRUE(isDouble && value > -0.99999 && value < 0.0001);
}

TEST_F(FloatSliderTest, setValueWorks)
{
    int i = 1;
    double newValue = 74.1;
    bool isDouble = false;


    sliderAccuruacyOne_.setValue(newValue);
    auto value = sliderAccuruacyOne_.value();
    isDouble = std::is_same<decltype (value), double>::value;
    EXPECT_TRUE(isDouble && static_cast<int>(value*10.0) == static_cast<int>(newValue*10.0));

    while(i < 11){
        newValue += 0.1;
        sliderAccuruacyOne_.setValue(newValue);
        value = sliderAccuruacyOne_.value();
        EXPECT_TRUE(static_cast<int>(value*10.0) == static_cast<int>((newValue+ADD_)*10.0));
    ++i;
    }

    newValue = 74.18;
    sliderAccuruacyTwo_.setValue(newValue);
    value = sliderAccuruacyTwo_.value();
    isDouble = std::is_same<decltype (value), double>::value;
    EXPECT_TRUE(isDouble && static_cast<int>(value*100.0) == static_cast<int>(newValue*100.0));

    i = 1;
    while(i < 11){
        newValue += 0.11;
        sliderAccuruacyTwo_.setValue(newValue);
        value = sliderAccuruacyTwo_.value();
        EXPECT_TRUE(static_cast<int>(value*100.0) == static_cast<int>((newValue+ ADD_)*100.0));
    ++i;
    }

    newValue = 74.184;
    sliderAccuruacyThree_.setValue(newValue);
    value = sliderAccuruacyThree_.value();
    isDouble = std::is_same<decltype (value), double>::value;
    EXPECT_TRUE(isDouble && static_cast<int>(value*1000.0) == static_cast<int>(newValue*1000.0));

    i = 1;
    while(i < 11){
        newValue += 0.111;
        sliderAccuruacyThree_.setValue(newValue);
        value = sliderAccuruacyThree_.value();
        EXPECT_TRUE(static_cast<int>(value*1000.0) == static_cast<int>((newValue+ ADD_)*1000.0));
    ++i;
    }
}

TEST_F(FloatSliderTest, accuracyWorks)
{
    EXPECT_TRUE(sliderAccuruacyOne_.accuracy() == FloatSlider::SliderAccuracy::eDecPlaceOne ||
                sliderAccuruacyOne_.accuracy() == FloatSlider::SliderAccuracy::eDecPlaceTwo ||
                sliderAccuruacyOne_.accuracy() == FloatSlider::SliderAccuracy::eDecPlaceThree);
};


TEST_F(FloatSliderTest, maximumWorks)
{
    // the default maximal value set by QSlider's constructor is (int) 99
    EXPECT_TRUE(sliderAccuruacyOne_.maximum() < 99.1 && sliderAccuruacyOne_.maximum() > 89.9);
    EXPECT_TRUE(sliderAccuruacyTwo_.maximum() < 99.01 && sliderAccuruacyOne_.maximum() > 89.99);
    EXPECT_TRUE(sliderAccuruacyTwo_.maximum() < 99.001 && sliderAccuruacyOne_.maximum() > 89.999);
};


TEST_F(FloatSliderTest, setMaximumWorks)
{
    sliderAccuruacyOne_.setMaximum(1.0);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyOne_.maximum() * 10.0) == 10);
    sliderAccuruacyOne_.setMaximum(1.9);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyOne_.maximum() * 10.0) == 19);
    sliderAccuruacyTwo_.setMaximum(777.77);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyTwo_.maximum() * 100.0) == 77777);
    sliderAccuruacyTwo_.setMaximum(7.99);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyTwo_.maximum() * 100.0) == 799);
    sliderAccuruacyThree_.setMaximum(156.999);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyThree_.maximum() * 1000.0) == 156999);
};

TEST_F(FloatSliderTest, setMinimumWorks)
{
    sliderAccuruacyOne_.setMinimum(1.0);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyOne_.minimum() * 10.0) == 10);
    sliderAccuruacyOne_.setMinimum(1.9);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyOne_.minimum() * 10.0) == 19);
    sliderAccuruacyTwo_.setMinimum(777.77);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyTwo_.minimum() * 100.0) == 77777);
    sliderAccuruacyTwo_.setMinimum(7.99);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyTwo_.minimum() * 100.0) == 799);
    sliderAccuruacyThree_.setMinimum(156.999);
    EXPECT_TRUE(static_cast<int>(sliderAccuruacyThree_.minimum() * 1000.0) == 156999);
}





