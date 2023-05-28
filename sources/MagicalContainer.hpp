#ifndef MAGICALCONTAINER
#define MAGICALCONTAINER

#include <vector>
class MagicalContainer {

private:
    std::vector<int> container;
    bool isPrime(int n) const;
    
public:
    void addElement(int new_val);
    void removeElement(int element);
    int size() const;
    class AscendingIterator;
    class SideCrossIterator;
    class PrimeIterator;
};


class AscendingIterator {
private:
    const MagicalContainer& container;
    int index;
    AscendingIterator(const MagicalContainer& container, int index)
        :container(container), index(index){}

public:
    AscendingIterator(const MagicalContainer& container);
    AscendingIterator(const AscendingIterator& other);
    ~AscendingIterator();
    AscendingIterator& operator=(const AscendingIterator& other);
    bool operator==(const AscendingIterator&other) const;
    bool operator!=(const AscendingIterator&other) const;
    bool operator>(const AscendingIterator&other) const;
    bool operator<(const AscendingIterator&other) const;
    AscendingIterator begin() const;
    AscendingIterator end() const;
    int operator*() const;
    AscendingIterator& operator++();
};


class SideCrossIterator {
private:
    const MagicalContainer& container;
    int index;
    bool fromStart;
    SideCrossIterator(const MagicalContainer& container, int index, bool fromStart)
        :container(container), index(index), fromStart(fromStart){}

public:
    SideCrossIterator(const MagicalContainer& container);
    SideCrossIterator(const SideCrossIterator& other);
    ~SideCrossIterator();
    SideCrossIterator& operator=(const SideCrossIterator& other);
    bool operator==(const SideCrossIterator& other) const;
    bool operator!=(const SideCrossIterator& other) const;
    bool operator>(const SideCrossIterator& other) const;
    bool operator<(const SideCrossIterator& other) const;
    SideCrossIterator begin() const;
    SideCrossIterator end() const;
    int operator*() const;
    SideCrossIterator& operator++();
};


class PrimeIterator {
private:
    const MagicalContainer& container;
    int index;
    PrimeIterator(const MagicalContainer& container, int index)
        :container(container), index(index){}

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
};


#endif // MAGICALCONTAINER
