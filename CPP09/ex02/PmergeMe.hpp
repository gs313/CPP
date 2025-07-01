#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

static int my_compare_count = 0;

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;

    template <typename T> void _merge_insertion_sort(T& container, int pair_level);
    template <typename T> void _swap_pair(typename T::iterator it, int pair_level);

    bool isValidInput(const std::string& str);
    double getTime();

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void processInput(int argc, char** argv);
    void sortAndDisplay();
    void sort_vec(std::vector<int>& vec);
    void sort_deque(std::deque<int>& deque);



};


template <typename T> bool _comp(T lv, T rv) {
    my_compare_count++;
    return *lv < *rv;
}

template <typename T> T next(T it, int steps) {
    std::advance(it, steps);
    return it;
}

template <typename T> void PmergeMe::_swap_pair(typename T::iterator it, int pair_level) {
    typename T::iterator start = next(it, -pair_level + 1);
    typename T::iterator end = next(start, pair_level);
    while (start != end) {
        std::iter_swap(start, next(start, pair_level));
        start++;
    }
}

template <typename T> void PmergeMe::_merge_insertion_sort(T& container, int pair_level) {
    typedef typename T::iterator Iterator;

    int pair_units_nbr = container.size() / pair_level;
    if (pair_units_nbr < 2)
        return;

    bool is_odd = pair_units_nbr % 2 == 1;

    Iterator start = container.begin();
    Iterator last = next(container.begin(), pair_level * (pair_units_nbr));
    Iterator end = next(last, -(is_odd * pair_level));

    int jump = 2 * pair_level;
    for (Iterator it = start; it != end; std::advance(it, jump)) {
        Iterator this_pair = next(it, pair_level - 1);
        Iterator next_pair = next(it, pair_level * 2 - 1);
        if (_comp(next_pair, this_pair)) {
            _swap_pair<T>(this_pair, pair_level);
        }
    }
    _merge_insertion_sort(container, pair_level * 2);


    std::vector<Iterator> main;
    std::vector<Iterator> pend;

    main.insert(main.end(), next(container.begin(), pair_level - 1));
    main.insert(main.end(), next(container.begin(), pair_level * 2 - 1));

    for (int i = 4; i <= pair_units_nbr; i += 2) {
        pend.insert(pend.end(), next(container.begin(), pair_level * (i - 1) - 1));
        main.insert(main.end(), next(container.begin(), pair_level * i - 1));
    }

    if (is_odd) {
        pend.insert(pend.end(), next(end, pair_level - 1));
    }


    size_t Jacobsthal[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};

    int prev_jacobsthal = Jacobsthal[1]; // J(1) = 1
    int inserted_numbers = 0;
    for (int k = 2;; k++) {

        int curr_jacobsthal = Jacobsthal[k]; // J(k) = Jacobsthal[k]
        int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
        int offset = 0;
        if (jacobsthal_diff > static_cast<int>(pend.size()))
            break;
        int nbr_of_times = jacobsthal_diff;
        typename std::vector<Iterator>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
        typename std::vector<Iterator>::iterator bound_it =
            next(main.begin(), curr_jacobsthal + inserted_numbers);
        while (nbr_of_times) {
            typename std::vector<Iterator>::iterator idx =
                std::upper_bound(main.begin(), bound_it, *pend_it, _comp<Iterator>);
            typename std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
            nbr_of_times--;
            pend_it = pend.erase(pend_it);
            std::advance(pend_it, -1);
            offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
            bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
        }
        prev_jacobsthal = curr_jacobsthal;
        inserted_numbers += jacobsthal_diff;
        offset = 0;
    }

    for (ssize_t i = pend.size() - 1; i >= 0; i--) {
        typename std::vector<Iterator>::iterator curr_pend = next(pend.begin(), i);
        typename std::vector<Iterator>::iterator curr_bound =
            next(main.begin(), main.size() - pend.size() + i + is_odd);
        typename std::vector<Iterator>::iterator idx =
            std::upper_bound(main.begin(), curr_bound, *curr_pend, _comp<Iterator>);
        main.insert(idx, *curr_pend);
    }

    std::vector<int> copy;
    copy.reserve(container.size());
    for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++) {
        for (int i = 0; i < pair_level; i++) {
            Iterator pair_start = *it;
            std::advance(pair_start, -pair_level + i + 1);
            copy.insert(copy.end(), *pair_start);
        }
    }
    Iterator container_it = container.begin();
    typename std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end()) {
        *container_it = *copy_it;
        container_it++;
        copy_it++;
    }
}

#endif
