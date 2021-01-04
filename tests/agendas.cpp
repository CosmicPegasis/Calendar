#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../src/features/agendas.hpp"

// TODO Run this to figure out what the error is
TEST_CASE("Agenda is made", "[agendas.hpp]") {
    AgendaHelper helper;
    helper.make_agenda("Happy Birthday", "aviral", "19", "8", "2004");
}
TEST_CASE("Agenda is checked", "[agendas.hpp") {
    AgendaHelper helper;
    CHECK(helper.get_agenda("aviral", "19", "8", "2004") == "Happy Birthday");
}