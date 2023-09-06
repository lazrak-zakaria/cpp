#include "PmergeMe.hpp"
#include <sstream>
#include <climits>
#include <time.h> 
#include <iomanip>

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }
    return result;
}

bool    parse(int ac, char **av, std::vector<unsigned int> &answer)
{
    std::vector<std::vector<std::string> > vec;

    int i = 1;
    while (i < ac)
        vec.push_back(split(av[i++], ' '));
    for (size_t j = 0; j < vec.size(); ++j)
    {
        size_t size = vec[j].size();
        for (size_t k = 0; k < size; ++k)
        {
            size_t size_s = vec[j][k].size();
            size_t t;
            for (t = 0; t < size_s; ++t)
            {
                if (!isdigit(vec[j][k][t]))
                    return 0;
            }
			for (t = 0; vec[j][k][t] == '0'; ++t)
				;
            if (vec[j][k].substr(t).length() > 11) return 0;
            long long a = atoll(vec[j][k].c_str());
            if (a > UINT_MAX)
                return 0;
            else
                answer.push_back(a);
        }
    }
    return 1;
}


int main(int ac, char **av)
{
    clock_t t;
    if (ac == 1)
    {
        std::cout << "the programe must take arguments\n";
        return 0;
    }
    std::vector<unsigned int> vec;

    if (!parse(ac, av , vec))
    {
        std::cout << "Error\n";
        return (1);
    }


    std::deque<unsigned int> d(vec.begin(), vec.end());



    t = clock();
    std::vector<unsigned int> vec1 = merge_insert_sort(vec);
    t = clock() - t;
    float tm1 = static_cast<float> (t) /  CLOCKS_PER_SEC;
    
    t = clock();
    std::deque<unsigned int> d1 = merge_insert_sort(d);
    t = clock() - t;
    float tm2 = static_cast<float> (t) /  CLOCKS_PER_SEC;

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    std::cout << "After:  ";
    for (size_t i = 0; i < vec1.size(); ++i)
        std::cout << vec1[i] << " ";
    std::cout << "\n" << std::fixed;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
        << tm1 << " sec\n";
    std::cout << "Time to process a range of " << vec.size() << " elements with std::deque  : " 
        << tm2 << " sec\n";


    return 0;
}

	// if (std::is_sorted(d1.begin(), d1.end()))
    // 	std::cout << "Sorted\n";
	// if (std::is_sorted(vec1.begin(), vec1.end()))
   	// 	std::cout << "Sorted\n";
