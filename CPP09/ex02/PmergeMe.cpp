#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}


bool PmergeMe::isValidInput(const std::string& str) {
    if (str.empty()) return false;

    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }

    long num = std::atol(str.c_str());
    return num > 0 && num <= 2147483647;
}

double PmergeMe::getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

void PmergeMe::processInput(int argc, char** argv) {
    if (argc < 2) {
        throw std::runtime_error("Error: No input provided");
    }

    for (int i = 1; i < argc; ++i) {
        if (!isValidInput(argv[i])) {
            throw std::runtime_error("Error: Invalid input");
        }

        int num = std::atoi(argv[i]);
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }

    if (_vectorData.size() > 3000) {
        std::cout << "Warning: Processing more than 3000 elements" << std::endl;
    }
}

void PmergeMe::sort_vec(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    _merge_insertion_sort(vec, 1);
}

void PmergeMe::sort_deque(std::deque<int>& deque) {
    if (deque.size() <= 1) return;
    _merge_insertion_sort(deque, 1);
}

void PmergeMe::sortAndDisplay() {
    // Display unsorted sequence
    std::cout << "Before : ";
    if(_vectorData.size() > 5)
    {
        for (size_t i = 0; i < 5; ++i) {
            std::cout << _vectorData[i];
            if (i < _vectorData.size() - 1) std::cout << " ";
        }
        std::cout << "[...]";
    }
    else{
        for (size_t i = 0; i < _vectorData.size(); ++i) {
            std::cout << _vectorData[i];
            if (i < _vectorData.size() - 1) std::cout << " ";
        }
    }
    std::cout << std::endl;

    // Sort with vector and measure time
    std::vector<int> vectorCopy = _vectorData;
    my_compare_count = 0; // Reset comparison count
    double startTime = getTime();
    sort_vec(vectorCopy);
    double endTime = getTime();
    double vectorTime = endTime - startTime;
    // std::cout << "Comparisons made in vector: " << my_compare_count << std::endl;

    // Sort with deque and measure time
    std::deque<int> dequeCopy = _dequeData;
    my_compare_count = 0; // Reset comparison count
    startTime = getTime();
    sort_deque(dequeCopy);
    endTime = getTime();
    double dequeTime = endTime - startTime;
    // std::cout << "Comparisons made in deque: " << my_compare_count << std::endl;

    // Display sorted sequence
    std::cout << "After  : ";
    if(vectorCopy.size() > 5)
    {
        for (size_t i = 0; i < 5; ++i) {
            std::cout << vectorCopy[i];
            if (i < vectorCopy.size() - 1) std::cout << " ";
        }
        std::cout << "[...]";
    }
    else{
        for (size_t i = 0; i < vectorCopy.size(); ++i) {
            std::cout << vectorCopy[i];
            if (i < vectorCopy.size() - 1) std::cout << " ";
        }
    }

    std::cout << std::endl;

    // Display timing information
    std::cout << "Time to process a range of " << _vectorData.size()
              << " elements with std::vector : " << std::fixed << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size()
              << " elements with std::deque : " << std::fixed << dequeTime << " us" << std::endl;
}
