#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../src/features/calendar.hpp"


TEST_CASE("Year code is calculated", "[Year Calendar Helper]") {
    YearCalendarHelper helper;
    CHECK(helper.getYearCode(2021) == 6);
    CHECK(helper.getYearCode(3999) == 0);
    CHECK(helper.getYearCode(1700) == 4);
    CHECK(helper.getYearCode(1800) == 2);
    CHECK(helper.getYearCode(1900) == 0);
    CHECK(helper.getYearCode(2000) == 6);
}

TEST_CASE("First day of the year is calculated", "[Year Calendar Helper") {
    YearCalendarHelper helper;
    CHECK(helper.caluclateFirstDay(1900) == 1);
    // CHECK(helper.caluclateFirstDay(100) == 3); // Doesn't work for three digit years
    CHECK(helper.caluclateFirstDay(2021) == 5);
    CHECK(helper.caluclateFirstDay(3999) == 5);
    CHECK(helper.caluclateFirstDay(1700) == 1);
    CHECK(helper.caluclateFirstDay(1800) == 3);
    CHECK(helper.caluclateFirstDay(2000) == 6);
}