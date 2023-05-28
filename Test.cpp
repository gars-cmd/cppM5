#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sources/MagicalContainer.hpp"



TEST_CASE("Magical Container operation") {
    MagicalContainer container;
    CHECK_EQ(container.size(), 0);
    container.addElement(0);
    container.addElement(1);
    CHECK_EQ(container.size(), 2);
    container.addElement(2);
    container.addElement(3);
    CHECK_EQ(container.size(), 4);
    container.addElement(4);
    container.addElement(5);
    CHECK_EQ(container.size(), 6);
    container.removeElement(4);
    CHECK_EQ(container.size(), 5);
    container.removeElement(2);
    CHECK_EQ(container.size(), 4);
    container.removeElement(3);
    CHECK_EQ(container.size(), 3);
}

TEST_CASE("Ascending Iterator operation") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    AscendingIterator asc_it(container);
    std::vector<int> result;

}

