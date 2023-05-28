#include "MagicalContainer.hpp"
#include <complex>
#include <vector>

    void MagicalContainer::addElement(int new_val){
}
    void MagicalContainer::removeElement(int element){
}
    int MagicalContainer::size() const{
        return 0;
}



AscendingIterator::AscendingIterator(const MagicalContainer& container)
    : container(container), index(0){}

AscendingIterator::AscendingIterator(const AscendingIterator& other)
    :container(other.container), index(other.index){}

AscendingIterator::~AscendingIterator(){
}

AscendingIterator& AscendingIterator::operator=(const AscendingIterator& other){
    return *this;
}

bool AscendingIterator::operator==(const AscendingIterator&other) const{
    return false;
}

bool AscendingIterator::operator!=(const AscendingIterator&other) const{
    return false;
}

bool AscendingIterator::operator>(const AscendingIterator&other) const{
    return false;
}

bool AscendingIterator::operator<(const AscendingIterator&other) const{
    return false;
}

AscendingIterator AscendingIterator::begin() const{
    return AscendingIterator(container);
}

AscendingIterator AscendingIterator::end() const{
    return AscendingIterator(container, container.size());
}

int AscendingIterator::operator*() const{
    return 0;
}

AscendingIterator& AscendingIterator::operator++(){
    return *this;
}




SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
    :container(container), index(0), fromStart(true){}

SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container), index(other.index), fromStart(other.fromStart){}

SideCrossIterator::~SideCrossIterator(){}

SideCrossIterator& SideCrossIterator::operator=(const SideCrossIterator& other){
    return *this;
}

bool SideCrossIterator::operator==(const SideCrossIterator& other) const{
    return false;
}

bool SideCrossIterator::operator!=(const SideCrossIterator& other) const{
    return false;
}

bool SideCrossIterator::operator>(const SideCrossIterator& other) const{
    return false;
}

bool SideCrossIterator::operator<(const SideCrossIterator& other) const{
    return false;
}

SideCrossIterator SideCrossIterator::begin() const{
    return SideCrossIterator(container);
}

SideCrossIterator SideCrossIterator::end() const{
    return SideCrossIterator(container, container.size(), false);
}

int SideCrossIterator::operator*() const{
    return 0;
}

SideCrossIterator& SideCrossIterator::operator++(){
    return *this;
}



PrimeIterator::PrimeIterator(const MagicalContainer& container)
    :container(container), index(0){}

PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container), index(other.index){}

PrimeIterator::~PrimeIterator(){}

PrimeIterator& PrimeIterator::operator=(const PrimeIterator& other){
    return *this;
}

bool PrimeIterator::operator==(const PrimeIterator& other) const{
    return false;
}

bool PrimeIterator::operator!=(const PrimeIterator& other) const{
    return false;
}

bool PrimeIterator::operator>(const PrimeIterator& other) const{
    return false;
}

bool PrimeIterator::operator<(const PrimeIterator& other) const{
    return false;
}

PrimeIterator PrimeIterator::begin() const{
    return PrimeIterator(container);
}

PrimeIterator PrimeIterator::end() const{
    return PrimeIterator(container, container.size());
}

int PrimeIterator::operator*() const{
    return 0;
}

PrimeIterator& PrimeIterator::operator++(){
    return *this;
}

//Ressources : 
//https://www.youtube.com/watch?v=F9eDv-YIOQ0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=94
