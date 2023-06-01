#include <stdexcept>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"



TEST_CASE("Magical Container operation") {
    ariel::MagicalContainer container;
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
    ariel::MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    ariel::MagicalContainer::AscendingIterator asc_it(container);
    CHECK(*asc_it == 2);  ++asc_it;
    CHECK(*asc_it == 3);  ++asc_it;
    CHECK(*asc_it == 9);  ++asc_it;
    CHECK(*asc_it == 17); ++asc_it;
    CHECK(*asc_it == 25); 

    asc_it = asc_it.begin();
    ariel::MagicalContainer::AscendingIterator asc_it2(asc_it);

    CHECK(*asc_it == *asc_it2);
    ++asc_it;
    CHECK(*asc_it2 == 2);
    CHECK(*asc_it == 3);

    asc_it.begin();
    asc_it2.begin();

    CHECK(!(asc_it != asc_it2));
    ++asc_it2;
    CHECK(asc_it != asc_it2);

    asc_it.begin();
    asc_it2.begin();

    ++asc_it2;
    CHECK(asc_it2 > asc_it);
    CHECK(asc_it2 < asc_it);
    ++asc_it;
    CHECK(asc_it == asc_it2);

    asc_it.end();
    CHECK_THROWS_AS(*asc_it, std::runtime_error);

    ariel::MagicalContainer::SideCrossIterator sdc_ite(container);

try {
        bool res = asc_it > sdc_ite;
    }
    catch (const std::logic_error& e) {
        CHECK(true);
    }

    try {
        bool res = sdc_ite < asc_it;
    }
    catch (const std::logic_error& e) {
        CHECK(true);
    }

    asc_it.end();
    CHECK_THROWS_AS(*asc_it, std::runtime_error);
}

TEST_CASE("Testing AscendingIterator with empty container") {
    ariel::MagicalContainer container;
    ariel::MagicalContainer::AscendingIterator asc_it(container);
    CHECK( asc_it.begin() == asc_it.end());
}


TEST_CASE("SideCross Iterator operation") {
    ariel::MagicalContainer container;
    container.addElement(22);
    container.addElement(8);
    container.addElement(31);
    container.addElement(14);
    container.addElement(11);
    container.addElement(13);
    container.addElement(33);

    ariel::MagicalContainer::SideCrossIterator sdc_it(container);
    CHECK(*sdc_it == 22); ++sdc_it;
    CHECK(*sdc_it == 33); ++sdc_it;
    CHECK(*sdc_it == 8);  ++sdc_it;
    CHECK(*sdc_it == 13); ++sdc_it;
    CHECK(*sdc_it == 31); ++sdc_it; 
    CHECK(*sdc_it == 11); ++sdc_it; 
    CHECK(*sdc_it == 14);

    sdc_it = sdc_it.begin();
    ariel::MagicalContainer::SideCrossIterator sdc_it2(sdc_it);

    CHECK(*sdc_it == *sdc_it2);
    ++sdc_it;
    CHECK(*sdc_it2 == 22);
    CHECK(*sdc_it == 33);

    sdc_it.begin();
    sdc_it2.begin();

    CHECK(!(sdc_it != sdc_it2));
    ++sdc_it2;
    CHECK(sdc_it != sdc_it2);

    sdc_it.begin();
    sdc_it2.begin();

    ++sdc_it2;
    CHECK(sdc_it2 > sdc_it);
    CHECK(sdc_it2 < sdc_it);
    ++sdc_it;
    CHECK(sdc_it == sdc_it2);

    sdc_it.end();
    CHECK_THROWS_AS(*sdc_it , std::runtime_error);

    ariel::MagicalContainer::AscendingIterator asc_ite(container);

try {
        bool res = sdc_it > asc_ite;
    }
    catch (const std::logic_error& e) {
        CHECK(true);
    }

    try {
        bool res = asc_ite < sdc_it;
    }
    catch (const std::logic_error& e) {
        CHECK(true);
    }

}


TEST_CASE("Prime Iterator operation") {
    ariel::MagicalContainer container;
    container.addElement(22);
    container.addElement(8);
    container.addElement(31);
    container.addElement(14);
    container.addElement(11);
    container.addElement(13);
    container.addElement(33);

    ariel::MagicalContainer::PrimeIterator prm_it(container);
    CHECK(*prm_it == 31); ++prm_it;
    CHECK(*prm_it == 11); ++prm_it;
    CHECK(*prm_it == 13);  

    prm_it = prm_it.begin();
    ariel::MagicalContainer::PrimeIterator prm_it2(prm_it);

    CHECK(*prm_it == *prm_it2);
    ++prm_it;
    CHECK(*prm_it2 == 31);
    CHECK(*prm_it == 11);

    prm_it.begin();
    prm_it2.begin();

    CHECK(!(prm_it != prm_it2));
    ++prm_it2;
    CHECK(prm_it != prm_it2);

    prm_it.begin();
    prm_it2.begin();

    ++prm_it2;
    CHECK(prm_it2 > prm_it);
    CHECK(prm_it2 < prm_it);
    ++prm_it;
    CHECK(prm_it == prm_it2);

    prm_it.end();
    CHECK_THROWS_AS(*prm_it , std::runtime_error);

    ariel::MagicalContainer::AscendingIterator asc_ite(container);

    try {
        bool res = prm_it > asc_ite;
    }
    catch (const std::logic_error& e) {
        CHECK(true);
    }

    try {
        bool res = prm_it < asc_ite;
    }
    catch (const std::logic_error& e) {
        CHECK(true);
    }

}


// Ressources : 
//https://github.com/doctest/doctest/issues/356
