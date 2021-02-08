#include "ledindicatortest.h"

LedIndicatorTest::LedIndicatorTest() :
    ledOne_  (),
    ledTwo_  (30),
    ledThree_(QtWidgets::LedIndicator::LedState::eSuccess),
    ledFour_ (30, QtWidgets::LedIndicator::LedState::eError)
{

}


TEST_F(LedIndicatorTest, getLedSizeWorks)
{
    EXPECT_TRUE(ledOne_.getLedSize() == 30);
    EXPECT_TRUE(ledTwo_.getLedSize() == 30);
    EXPECT_TRUE(ledThree_.getLedSize() == 30);
    EXPECT_TRUE(ledFour_.getLedSize() == 30);
}


TEST_F(LedIndicatorTest, setLedSizeWorks)
{
    int newSize = 50;
    ledOne_.setLedSize(newSize);
    EXPECT_TRUE(ledOne_.getLedSize() == newSize);
}


TEST_F(LedIndicatorTest, getStateWorks)
{
    EXPECT_TRUE(ledOne_.getState() == QtWidgets::LedIndicator::LedState::eNotActive);
    EXPECT_TRUE(ledThree_.getState() == QtWidgets::LedIndicator::LedState::eSuccess);
    EXPECT_TRUE(ledFour_.getState() == QtWidgets::LedIndicator::LedState::eError);
}


TEST_F(LedIndicatorTest, setStateWorks)
{
    QtWidgets::LedIndicator::LedState newState = QtWidgets::LedIndicator::LedState::eReady;
    ledOne_.setState(newState);
    EXPECT_TRUE(ledOne_.getState() == newState);
}


TEST_F(LedIndicatorTest, getColorWorks)
{
    EXPECT_TRUE(QtWidgets::LedIndicator::getColor(ledOne_.getState()) == Qt::gray);
}


TEST_F(LedIndicatorTest, setColorWorks)
{
    QtWidgets::LedIndicator::setColor(QtWidgets::LedIndicator::LedState::eNotActive, Qt::green);
    EXPECT_TRUE(QtWidgets::LedIndicator::getColor(QtWidgets::LedIndicator::LedState::eNotActive) == Qt::green);
}


TEST_F(LedIndicatorTest, constructorsWork)
{

}
