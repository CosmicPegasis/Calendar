#include <catch2/catch.hpp>
#include "../src/features/agendas.hpp"

TEST_CASE("Agenda is made", "[agendas.hpp]") {
    Agenda agenda;
    CHECK(agenda.set_agenda("Happy Birthday", "aviral", 19, 08, 2004) == agenda.fetch_agenda("aviral", 19, 08, 2004));
}