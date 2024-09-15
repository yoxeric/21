
#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <cmath>

#include <unistd.h>

#include <sys/time.h>
#include <ctime>
#include <iomanip> 

template <typename T, typename T2>
class PmergeMe
{
    private:

    public:
        // std::deque<int> dq;
        // std::deque< std::pair<int, int> > pdq;
        // std::deque<int> dq_justin;
        // std::deque<int> dq_chain;
        // std::deque<int> dq_pend;

        // std::vector<int> v;
        // std::vector< std::pair<int, int> > pv;
        // std::vector<int> justin;
        // std::vector<int> chain;
        // std::vector<int> pend;

        T v;
        T2 pv;
        T justin;
        T chain;
        T pend;

        int loner;

        // void split_pairs();
        // void sort_pairs(int start, int end);
        // void merge_sort(int start, int mid, int end);
        // void sort_each_pairs();
        // void generate_justin();
        // void generate_chain_pend();
        // int find_place(int nb);
        // void push_inplace();

        // PmergeMe();
        // ~PmergeMe();


        PmergeMe()
        {
        }

        ~PmergeMe()
        {
        }

        void split_pairs()
        {
            int i = 0;

            for (; i < (int) v.size() - 1; i += 2)
            {
                std::pair<int, int> p = std::make_pair(v[i], v[i + 1]);
                pv.push_back(p);
            }
            if (v.size() % 2 == 1)
                loner = v[v.size() - 1];
        }

        void sort_each_pairs()
        {
            for (int i = 0; i < (int) pv.size(); i++)
            {
                if (pv[i].first < pv[i].second)
                    std::swap(pv[i].first, pv[i].second);
            }
        }

        void sort_pairs(int start, int end)
        {
            if (start >= end)
                return ;

            // std::cout << "sorting " << start << " - " << end << std::endl;

            int mid = start + (end - start) / 2;
            sort_pairs(start, mid);
            sort_pairs(mid + 1, end);
            merge_sort(start, mid, end);
        }

        void merge_sort(int start, int mid, int end)
        {
            // std::cout << "merging " << start << " - " << mid << " - " << end << std::endl;
            int e = mid + 1;
            for (int s = start; s <= mid && e <= end; s++)
            {
                // std::cout << "r/l: [" << s << "] " << pv[s].first << " / [" << e << "] " << pv[e].first << std::endl;
                if (pv[s] >= pv[e])
                {
                    // std::cout << "--- swap: [" << s << "] " << pv[s].first << " <- [" << e << "] " << pv[e].first << std::endl;
                    std::swap(pv[s], pv[e]);
                    for (int tmp_end = e; tmp_end < end && pv[tmp_end] > pv[tmp_end + 1]; tmp_end++)
                    {
                        // std::cout << "--- bubble swap: [" << tmp_end << "] " << pv[tmp_end].first << " <-> [" << tmp_end + 1 << "] " << pv[tmp_end + 1].first << std::endl;
                        std::swap(pv[tmp_end], pv[tmp_end + 1]);
                    }
                }
            }
        }

        void generate_chain_pend()
        {
            for (int i = 0; i < (int) pv.size(); i++)
            {
                chain.push_back(pv[i].first);
            }
            for (int i = 1; i < (int) pv.size(); i++)
            {
                pend.push_back(pv[i].second);
            }
            chain.insert(chain.begin(), pv[0].second);
        }

        void generate_justin()
        {
            justin.push_back(0);
            int i = 1;

            int order = (std::pow(2, i) - std::pow(-1, i)) / 3;
            int last_order = (std::pow(2, i - 1) - std::pow(-1, i - 1)) / 3;

            while (i++)
            {
                order = (std::pow(2, i) - std::pow(-1, i)) / 3;
                last_order = (std::pow(2, i - 1) - std::pow(-1, i - 1)) / 3;

                // std::cout << "order " << order << " - " << last_order << std::endl;
                if (last_order > (int) pend.size())
                    break;

                if (order >= (int) pend.size())
                    order = pend.size() - 1;

                justin.push_back(order);

                while (--order > last_order)
                {
                    justin.push_back(order);
                }
            }
        }

        int find_place(int nb)
        {
            // binary search in chain
            int high = chain.size() - 1;
            int low = 0;
            int mid = 0;
            while (low <= high)
            {
                mid = (high + low) / 2;
                
                if (nb > chain[mid - 1] && nb < chain[mid])
                    break ;

                if (nb < chain[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return (mid);
        }

        void push_inplace()
        {
            int pos = 0;

            for (int i = 0; i < (int) justin.size(); i++)
            {
                int order = justin[i];
                pos = find_place(pend[order]);
                // std::cout << "[" << order << "] = " << pend[order] << " ... pos -> " << pos << std::endl;
                chain.insert(chain.begin() + pos, pend[order]);
            }

            // std::cout << "push loner" << std::endl;
            // if loner
            if (v.size() % 2 == 1)
            {
                pos = find_place(loner);
                chain.insert(chain.begin() + pos, loner);
            }
        }
};