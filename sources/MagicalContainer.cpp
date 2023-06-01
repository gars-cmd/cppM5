#include "MagicalContainer.hpp"
#include <algorithm>
#include <complex>
#include <vector>
    

ariel::MagicalContainer::MagicalContainer() noexcept {}

void ariel::MagicalContainer::addElement(int new_val){
    container.push_back(new_val);
}

void ariel::MagicalContainer::removeElement(int element){
    auto iterator = std::find(container.begin(), container.end(), element);
    if (iterator != container.end()) {
        container.erase(iterator);
    }
}

int ariel::MagicalContainer::size() const{
        return container.size();
}

ariel::MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
    : container(&container), index(0){}

ariel::MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
    :container(other.container), index(other.index){}

ariel::MagicalContainer::AscendingIterator::~AscendingIterator(){
}

ariel::MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
    return *this;
}

bool ariel::MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
    return false;
}

bool ariel::MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
    return false;
}

bool ariel::MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
    return false;
}

bool ariel::MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
    return false;
}

ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::begin() const{
    return AscendingIterator(*container);
}

ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::end() const{
    return AscendingIterator(*container, container->size());
}

int ariel::MagicalContainer::AscendingIterator::operator*() const{
    return 0;
}

ariel::MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator++(){
    return *this;
}

ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
    :container(container), index(0), fromStart(true){}

ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container), index(other.index), fromStart(other.fromStart){}

ariel::MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

ariel::MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
    return *this;
}

bool ariel::MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
    return false;
}

bool ariel::MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
    return false;
}

bool ariel::MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
    return false;
}

bool ariel::MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
    return false;
}

ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::begin() const{
    return SideCrossIterator(container);
}

ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::end() const{
    return SideCrossIterator(container, container.size(), false);
}

int ariel::MagicalContainer::SideCrossIterator::operator*() const{
    return 0;
}

ariel::MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator++(){
    return *this;
}

ariel::MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
    :container(container), index(0){}

ariel::MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container), index(other.index){}

ariel::MagicalContainer::PrimeIterator::~PrimeIterator(){}

ariel::MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
    return *this;
}

bool ariel::MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
    return false;
}

bool ariel::MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
    return false;
}

bool ariel::MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
    return false;
}

bool ariel::MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
    return false;
}

ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::begin() const{
    return PrimeIterator(container);
}

ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::end() const{
    return PrimeIterator(container, container.size());
}

int ariel::MagicalContainer::PrimeIterator::operator*() const{
    return 0;
}

ariel::MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator++(){
    return *this;
}

//Ressources : 
//https://www.youtube.com/watch?v=F9eDv-YIOQ0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=94
