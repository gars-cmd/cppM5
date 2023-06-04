#ifndef MAGICALCONTAINER
#define MAGICALCONTAINER

#include <cstddef>
#include <stdexcept>
#include <vector>


namespace ariel {

class MagicalContainer {

private:
    std::vector<int> container;
    bool isPrime(int n) const;
    std::vector<int*> prime_container;
    void sortedAdd(bool isPrime, int element);
    bool isAlreadyIn(int element);

public:
    static bool compare(const int* var_a,const int* var_b){
        return *var_a < *var_b;
    }
    static  bool compareEqual(const int* p, int element)  {
        return *p == element;
    }
    ~MagicalContainer();
    MagicalContainer () noexcept;
    std::vector<int> getVec();
    void addElement(int new_val);
    void removeElementHelper(bool isPrime, int element);
    void removeElement( int element);
    size_t size() const;
    class BaseIterator;
    class AscendingIterator;
    class SideCrossIterator;
    class PrimeIterator;

    template <typename T, typename U>
    friend bool operator<(const T& left_It, const U& right_It){
        throw std::logic_error("cannot compare two different types");
    }
    template <typename T, typename U>
    friend bool operator>(const T& left_It, const U& right_It){
        throw std::logic_error("cannot compare two different types");
    }

};

class MagicalContainer::BaseIterator {
private:
    const MagicalContainer* magic_container;
    size_t index = 0;
    BaseIterator(const MagicalContainer& container, size_t index)
        : magic_container(&container), index(index) {}

public:
    BaseIterator& operator=(const BaseIterator& other);
    bool operator==(const BaseIterator& other) const;
    bool operator!=(const BaseIterator& other) const;
    void throwOnDiffContainer(const BaseIterator& other) const;
};



class MagicalContainer::AscendingIterator {
private:
    const MagicalContainer* magic_container;
    size_t index = 0;
    AscendingIterator(const MagicalContainer& container, size_t index)
    :magic_container(&container), index(index){}
    void throwOnOverIncrementation() const;

public:
    AscendingIterator(const MagicalContainer& container);
    AscendingIterator(const AscendingIterator& other);
    ~AscendingIterator();
    AscendingIterator& operator=(const AscendingIterator& other);
    bool operator==(const AscendingIterator& other) const;
    bool operator!=(const AscendingIterator& other) const;
    bool operator>(const AscendingIterator& other) const;
    bool operator<(const AscendingIterator& other) const;
    AscendingIterator begin() const;
    AscendingIterator end() const;
    int operator*() const;
    AscendingIterator& operator++();
    void throwOnDiffContainer(const AscendingIterator& other) const{
        if (this->magic_container != other.magic_container) {
            throw std::invalid_argument("both of the container are not the same");
        }
    }
};


class MagicalContainer::SideCrossIterator {
private:
    const MagicalContainer* magic_container;
    size_t index = 0;
    size_t offset = 0;
    SideCrossIterator(const MagicalContainer& container, size_t index, size_t offset)
    :magic_container(&container), index(index), offset(offset){}
    void throwOnOverIncrementation() const;

public:
    SideCrossIterator(const MagicalContainer& container);
    SideCrossIterator(const SideCrossIterator& other);
    ~SideCrossIterator();
    SideCrossIterator& operator=(const SideCrossIterator& other);
    bool operator==(const SideCrossIterator& other) const;
    bool operator!=(const SideCrossIterator& other) const;
    bool operator>(const SideCrossIterator& other) const;
    bool operator<(const SideCrossIterator& other) const;
    int getIndex();
    int getOffSet();
    void incIndex();
    void IncOffset();
    SideCrossIterator begin() const;
    SideCrossIterator end() const;
    int operator*() ;
    SideCrossIterator& operator++();
    void throwOnDiffContainer(const SideCrossIterator& other)const{
        if (this->magic_container != other.magic_container) {
            throw std::invalid_argument("both of the container are not the same");
        }
    }
};


class MagicalContainer::PrimeIterator {
private:
    const MagicalContainer* magic_container;
    size_t index = 0;
    PrimeIterator(const MagicalContainer& container, size_t index)
    :magic_container(&container), index(index){}
    void throwOnOverIncrementation() const;

public:
    PrimeIterator(const MagicalContainer& container);
    PrimeIterator(const PrimeIterator& other);
    ~PrimeIterator();
    PrimeIterator& operator=(const PrimeIterator& other);
    bool operator==(const PrimeIterator& other) const;
    bool operator!=(const PrimeIterator& other) const;
    bool operator>(const PrimeIterator& other) const;
    bool operator<(const PrimeIterator& other) const;
    PrimeIterator begin() const;
    PrimeIterator end() const;
    int operator*() const;
    PrimeIterator& operator++();
    void throwOnDiffContainer(const PrimeIterator& other) const{
        if (this->magic_container != other.magic_container) {
            throw std::invalid_argument("both of the container are not the same");
        }
    }
};
}

#endif // MAGICALCONTAINER
