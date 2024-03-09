
#include "PmergeMe.hpp"

std::vector<unsigned int> merge_insert_sort(std::vector<unsigned int> vec)
{
    if (vec.size() <= 1)
        return vec;
    size_t size = vec.size();
    bool is_odd = size % 2;
    size = is_odd ? size - 1 : size;
    std::vector<unsigned int> S;

    size_t smallest_in_S = vec[1] > vec[0] ? vec[1] : vec[0];
    size_t index_of_the_smallest = 0;
    size_t pair_of_the_smallest_in_S = vec[1] > vec[0] ? vec[0] : vec[1];
    for (size_t i = 1; i < size; i += 2)
    {
        if (vec[i] < vec[i - 1])
            std::swap(vec[i], vec[i - 1]);
        if (vec[i] < smallest_in_S)
        {
            pair_of_the_smallest_in_S = vec[i - 1];
            index_of_the_smallest = i - 1;
            smallest_in_S = vec[i];
        }
        S.push_back(vec[i]);
    }
      
    S = merge_insert_sort(S);

    std::vector<unsigned int>::iterator it;

    it = S.begin();
    S.insert(it, pair_of_the_smallest_in_S);

    for (size_t i = 0; i < size; i += 2)
    {
        if (i == index_of_the_smallest)
            continue;
        it = std::upper_bound(S.begin(), S.end(), vec[i]);
        S.insert(it, vec[i]);
    }

    if (is_odd)
    {
        it = std::upper_bound(S.begin(), S.end(), vec[size]);
        S.insert(it, vec[size]);
    }
    return (S);
}

std::deque<unsigned int> merge_insert_sort(std::deque<unsigned int> d)
{
    if (d.size() <= 1)
        return d;
    size_t size = d.size();
    bool is_odd = size % 2;
    size = is_odd ? size - 1 : size;
    std::deque<unsigned int> S;

    size_t smallest_in_S = d[1] > d[0] ? d[1] : d[0];
    size_t index_of_the_smallest = 0;
    size_t pair_of_the_smallest_in_S = d[1] > d[0] ? d[0] : d[1];
    for (size_t i = 1; i < size; i += 2)
    {
        if (d[i] < d[i - 1])
            std::swap(d[i], d[i - 1]);
        if (d[i] < smallest_in_S)
        {
            pair_of_the_smallest_in_S = d[i - 1];
            index_of_the_smallest = i - 1;
            smallest_in_S = d[i];
        }
        S.push_back(d[i]);
    }
      
    S = merge_insert_sort(S);

    std::deque<unsigned int>::iterator it;
    S.push_front(pair_of_the_smallest_in_S);

    for (size_t i = 0; i < size; i += 2)
    {
        if (i == index_of_the_smallest)
            continue;
        it = std::upper_bound(S.begin(), S.end(), d[i]);
        S.insert(it, d[i]);
    }

    if (is_odd)
    {
        it = std::upper_bound(S.begin(), S.end(), d[size]);
    	S.insert(it, d[size]);
    }

    return (S);
}

