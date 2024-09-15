
#include "PmergeMe.hpp"

template <typename T>
void print_vector(T v)
{
    for (int i = 0; i < (int) v.size(); ++i)
    {
        std::cout << v[i] << " " ;
    }
    std::cout << std::endl;
}

template <typename T>
void print_pair(std::vector<std::pair<int, int> > pv)
{
    for (int i = 0; i < (int) pv.size(); ++i)
    {
        std::cout << "[" << i << "] = " << pv[i].first << " - " << pv[i].second << std::endl;
    }
}

void deque_sort(int ac, char **av)
{
    PmergeMe< std::deque<int> , std::deque< std::pair<int, int> > > pm;

    for (int i = 1; i < ac; i++)
    {
        pm.v.push_back(std::stoi(av[i]));
    }


    // std::cout << "Before : ";
    // print_vector< std::deque<int> >(pm.v);

    pm.split_pairs();

    // std::cout << "pairs :"<< std::endl;
    // print_pair< std::deque<std::pair<int, int> > >(pm.pv);
    // std::cout << "loner = " << loner << std::endl;

    pm.sort_each_pairs();

    // std::cout << "each sorted pairs :"<< std::endl;
    // print_pair< std::deque<std::pair<int, int> > >(pm.pv);

    pm.sort_pairs(0, (int) pm.pv.size() - 1);

    // std::cout << "sorted pairs :"<< std::endl;
    // print_pair< std::deque<std::pair<int, int> > >(pm.pv);
    // print_vector< std::deque<int> >(pm.v);

    pm.generate_chain_pend();

    // std::cout << "chain : ";
    // print_vector< std::deque<int> >(pm.chain);
    // std::cout << "pend : ";
    // print_vector< std::deque<int> >(pm.pend);
    // std::cout << "chain gen" << std::endl;

    pm.generate_justin();

    // std::cout << "justin : ";
    // print_vector< std::deque<int> >(pm.justin);

    pm.push_inplace();

    // std::cout << "After : ";
    // print_vector< std::deque<int> >(pm.chain);
    
}

int vector_sort(int ac, char **av)
{
    PmergeMe< std::vector<int> , std::vector< std::pair<int, int> > > pm;

    for (int i = 1; i < ac; i++)
    {
        pm.v.push_back(std::stoi(av[i]));
    }


    std::cout << "Before : ";
    print_vector< std::vector<int> >(pm.v);

    pm.split_pairs();

    // std::cout << "pairs :"<< std::endl;
    // print_pair< std::vector<std::pair<int, int> > >(pm.pv);
    // std::cout << "loner = " << loner << std::endl;

    pm.sort_each_pairs();

    // std::cout << "each sorted pairs :"<< std::endl;
    // print_pair< std::vector<std::pair<int, int> > >(pm.pv);

    pm.sort_pairs(0, (int) pm.pv.size() - 1);

    // std::cout << "sorted pairs :"<< std::endl;
    // print_pair< std::vector<std::pair<int, int> > >(pm.pv);
    // print_vector< std::vector<int> >(pm.v);

    pm.generate_chain_pend();

    // std::cout << "chain : ";
    // print_vector< std::vector<int> >(pm.chain);
    // std::cout << "pend : ";
    // print_vector< std::vector<int> >(pm.pend);
    // std::cout << "chain gen" << std::endl;

    pm.generate_justin();

    // std::cout << "justin : ";
    // print_vector< std::vector<int> >(pm.justin);

    pm.push_inplace();

    std::cout << "After : ";
    print_vector< std::vector<int> >(pm.chain);
    
    return ((int) pm.chain.size());
}

int main(int ac, char **av)
{
    std::clock_t start = std::clock();

    int size = vector_sort(ac, av);

    std::clock_t end = std::clock();
    double vector_elapsed_time = double(end - start) / CLOCKS_PER_SEC;


    start = std::clock();

    deque_sort(ac, av);

    end = std::clock();
    double deque_elapsed_time = double(end - start) / CLOCKS_PER_SEC;


    // Set fixed notation and control decimal places
    // std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << size << " elements with std::vector : " << vector_elapsed_time * 1000 << " ms" << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::deque : " << deque_elapsed_time * 1000 << " ms" << std::endl;
}


