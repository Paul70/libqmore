#ifndef LEDINDICATORTEST_H
#define LEDINDICATORTEST_H

#include <gtest/gtest.h>
#include <QApplication>
#include <libqmorewidgets/ledindicator.h>




class LedIndicatorTest : public::testing::Test
{
protected:
    explicit LedIndicatorTest();

    ~LedIndicatorTest() = default;

    QtWidgets::LedIndicator ledOne_;
    QtWidgets::LedIndicator ledTwo_;
    QtWidgets::LedIndicator ledThree_;
    QtWidgets::LedIndicator ledFour_;
};

#endif // LEDINDICATORTEST_H
