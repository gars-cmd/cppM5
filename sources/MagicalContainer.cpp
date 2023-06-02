#include "MagicalContainer.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
    

ariel::MagicalContainer::MagicalContainer() noexcept {}

ariel::MagicalContainer::~MagicalContainer(){
    for (int* pointer : this->prime_container) {
        delete pointer;
    }
}
    void ariel::MagicalContainer::sortedAdd(bool isPrime, int element){
    if (isPrime) {
        int* temp = new int(element);
        this->prime_container.insert(std::upper_bound(
            this->prime_container.begin(),
            this->prime_container.end(),
            temp,
            compare), new int(element));
        delete temp;
    }
    this->container.insert(std::upper_bound(
        this->container.begin(),
        this->container.end(),
        element), element);
}

bool ariel::MagicalContainer::isAlreadyIn(int element){
    return std::find(this->container.begin(), this->container.end(), element) != this->container.end();
}

bool ariel::MagicalContainer::isPrime(int number) const{
    // Corner cases
    if (number <= 1){ return false;}
    if (number <= 3){return true;}
    if (number % 2 == 0 || number % 3 == 0){ return false;}
    for (int index = 5; index * index <= number; index = index + 6){
        if (number % index == 0 || number % (index + 2) == 0){
            return false;
        }
    }
    return true;
}


void ariel::MagicalContainer::addElement(int new_val){
   if (!this->isAlreadyIn(new_val)) {
        this->sortedAdd(this->isPrime(new_val), new_val);
   }else {
       std::cout << "the element is already in the container" << std::endl; 
   }
}


void ariel::MagicalContainer::removeElementHelper(bool isPrime, int element) {
    if (isPrime) {
        for (auto it = this->prime_container.begin(); it != this->prime_container.end(); ++it) {
            if (**it == element) {
                delete *it;
                this->prime_container.erase(it);
                break;
            }
        }
    }
    auto iterator = std::find(this->container.begin(), container.end(), element);
    if (iterator != container.end()) {
        container.erase(iterator);
    }else {
        throw std::runtime_error("the element doesn't exist");
    }
}

void ariel::MagicalContainer::removeElement(int element){
    this->removeElementHelper(this->isPrime(element), element);
}

size_t ariel::MagicalContainer::size() const{
        return container.size();
}

ariel::MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
    : magic_container(&container), index(0){}

ariel::MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
    :magic_container(other.magic_container), index(other.index){}

ariel::MagicalContainer::AscendingIterator::~AscendingIterator(){
}

ariel::MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
    if (this->magic_container->container != other.magic_container->container) {
        throw std::runtime_error("both of the container are not the same");
    }
    this->magic_container = other.magic_container;
    this->index = other.index;
    return *this;
}

bool ariel::MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
    return (this->magic_container == other.magic_container) && (this->index == other.index) ;
}

bool ariel::MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
    return !(*this == other );
}



bool ariel::MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
    this->throwOnDiffContainer(other);
    return this->index > other.index;
}

bool ariel::MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
    this->throwOnDiffContainer(other);
    return this->index < other.index;
}

ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::begin() const{
    return AscendingIterator(*magic_container);
}

ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::end() const{
    return AscendingIterator(*magic_container, magic_container->size());
}

int ariel::MagicalContainer::AscendingIterator::operator*() const{
    return this->magic_container->container[this->index] ;
}

void ariel::MagicalContainer::AscendingIterator::throwOnOverIncrementation() const{
    if (this->index >= this->magic_container->size() ) {
        throw std::runtime_error("we already reach the end of the SideCrossIterator");
    }
}

ariel::MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator++(){
    this->throwOnOverIncrementation();
    ++this->index;
    return *this;
}

ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
    :magic_container(&container), index(0), offset(0){}

ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : magic_container(other.magic_container), index(other.index), offset(other.offset){}

ariel::MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

ariel::MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
    if (this->magic_container->container != other.magic_container->container) {
        throw std::runtime_error("both of the container are not the same");
    }
    this->magic_container = other.magic_container;
    this->index = other.index;
    this->offset = other.offset;
    return *this;
}

bool ariel::MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
    return (this->magic_container == other.magic_container) && (this->index == other.index) ;
}

bool ariel::MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
    return !(*this == other);
}

bool ariel::MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
    this->throwOnDiffContainer(other);
    return this->index > other.index;
}

bool ariel::MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
    this->throwOnDiffContainer(other);
    return this->index < other.index;
}

ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::begin() const{
    return SideCrossIterator(*magic_container);
}

ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::end() const{
    return SideCrossIterator(*magic_container, magic_container->size(), false);
}

int ariel::MagicalContainer::SideCrossIterator::operator*() {
    if (this->index % 2 == 0) {
        return this->magic_container->container[this->index - this->offset];
    }else {
        this->offset++;
        return this->magic_container->container[this->magic_container->size() - this->offset];
    }
}

void ariel::MagicalContainer::SideCrossIterator::throwOnOverIncrementation() const{
    if (this->index >= this->magic_container->size() ) {
        throw std::runtime_error("we already reach the end of the SideCrossIterator");
    }
}


ariel::MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator++(){
    this->throwOnOverIncrementation();
    this->index++;
    return *this;
}

ariel::MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
    :magic_container(&container), index(0){}

ariel::MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : magic_container(other.magic_container), index(other.index){}

ariel::MagicalContainer::PrimeIterator::~PrimeIterator(){}

ariel::MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
    if (this->magic_container->container != other.magic_container->container) {
        throw std::runtime_error("both of the container are not the same");
    }
    this->magic_container = other.magic_container;
    this->index = other.index;
    return *this;
}

bool ariel::MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
    return (this->magic_container == other.magic_container) && (this->index == other.index) ;
}

bool ariel::MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
    return !(*this == other);
}

bool ariel::MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
    this->throwOnDiffContainer(other);
    return this->index > other.index;
}

bool ariel::MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
    this->throwOnDiffContainer(other);
    return this->index < other.index;
}

ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::begin() const{
    return PrimeIterator(*magic_container);
}

ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::end() const{
    return PrimeIterator(*magic_container, magic_container->prime_container.size());
}

int ariel::MagicalContainer::PrimeIterator::operator*() const{
    return *(this->magic_container->prime_container[this->index]) ;
}


void ariel::MagicalContainer::PrimeIterator::throwOnOverIncrementation() const{
    if (this->index >= this->magic_container->prime_container.size() ) {
        throw std::runtime_error("we already reach the end of the SideCrossIterator");
    }
}

ariel::MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator++(){
    if (this->index >= this->magic_container->prime_container.size()) {
        throw std::runtime_error("the index is beyond the size of the prime container");
    }    
    ++this->index;
    return *this;
}

//Ressources : 
//https://www.youtube.com/watch?v=F9eDv-YIOQ0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=94
//https://stackoverflow.com/questions/15843525/how-do-you-insert-the-value-in-a-sorted-vector
//https://stackoverflow.com/questions/869593/compare-function-for-upper-bound-lower-bound
