
#include "PmergeMe.hpp"

// PmergeMe::PmergeMe()
// {
// }

// PmergeMe::~PmergeMe()
// {
// }

// void PmergeMe::split_pairs()
// {
//     int i = 0;

//     for (; i < (int) v.size() - 1; i += 2)
//     {
//         std::pair<int, int> p = std::make_pair(v[i], v[i + 1]);
//         pv.push_back(p);
//     }
//     if (v.size() % 2 == 1)
//         loner = v[v.size() - 1];
// }

// void PmergeMe::sort_each_pairs()
// {
//     for (int i = 0; i < (int) pv.size(); i++)
//     {
//         if (pv[i].first < pv[i].second)
//             std::swap(pv[i].first, pv[i].second);
//     }
// }

// void PmergeMe::sort_pairs(int start, int end)
// {
//     if (start >= end)
//         return ;

//     // std::cout << "sorting " << start << " - " << end << std::endl;

//     int mid = start + (end - start) / 2;
//     sort_pairs(start, mid);
//     sort_pairs(mid + 1, end);
//     merge_sort(start, mid, end);
// }

// void PmergeMe::merge_sort(int start, int mid, int end)
// {
//     // std::cout << "merging " << start << " - " << mid << " - " << end << std::endl;
//     int e = mid + 1;
//     for (int s = start; s <= mid && e <= end; s++)
//     {
//         // std::cout << "r/l: [" << s << "] " << pv[s].first << " / [" << e << "] " << pv[e].first << std::endl;
//         if (pv[s] >= pv[e])
//         {
//             // std::cout << "--- swap: [" << s << "] " << pv[s].first << " <- [" << e << "] " << pv[e].first << std::endl;
//             std::swap(pv[s], pv[e]);
//             for (int tmp_end = e; tmp_end < end && pv[tmp_end] > pv[tmp_end + 1]; tmp_end++)
//             {
//                 // std::cout << "--- bubble swap: [" << tmp_end << "] " << pv[tmp_end].first << " <-> [" << tmp_end + 1 << "] " << pv[tmp_end + 1].first << std::endl;
//                 std::swap(pv[tmp_end], pv[tmp_end + 1]);
//             }
//         }
//     }
// }

// void PmergeMe::generate_chain_pend()
// {
//     for (int i = 0; i < (int) pv.size(); i++)
//     {
//         chain.push_back(pv[i].first);
//     }
//     for (int i = 1; i < (int) pv.size(); i++)
//     {
//         pend.push_back(pv[i].second);
//     }
//     chain.insert(chain.begin(), pv[0].second);
// }

// void PmergeMe::generate_justin()
// {
//     justin.push_back(0);
//     int i = 1;

//     int order = (std::pow(2, i) - std::pow(-1, i)) / 3;
//     int last_order = (std::pow(2, i - 1) - std::pow(-1, i - 1)) / 3;

//     while (i++)
//     {
//         order = (std::pow(2, i) - std::pow(-1, i)) / 3;
//         last_order = (std::pow(2, i - 1) - std::pow(-1, i - 1)) / 3;

//         // std::cout << "order " << order << " - " << last_order << std::endl;
//         if (last_order > (int) pend.size())
//             break;

//         if (order >= (int) pend.size())
//             order = pend.size() - 1;

//         justin.push_back(order);

//         while (--order > last_order)
//         {
//             justin.push_back(order);
//         }
//     }
// }

// int PmergeMe::find_place(int nb)
// {
//     // binary search in chain
//     int high = chain.size() - 1;
//     int low = 0;
//     int mid = 0;
//     while (low <= high)
//     {
//         mid = (high + low) / 2;
        
//         if (nb > chain[mid - 1] && nb < chain[mid])
//             break ;

//         if (nb < chain[mid])
//             high = mid - 1;
//         else
//             low = mid + 1;
//     }
//     return (mid);
// }

// void PmergeMe::push_inplace()
// {
//     int pos = 0;

//     for (int i = 0; i < (int) justin.size(); i++)
//     {
//         int order = justin[i];
//         pos = find_place(pend[order]);
//         // std::cout << "[" << order << "] = " << pend[order] << " ... pos -> " << pos << std::endl;
//         chain.insert(chain.begin() + pos, pend[order]);
//     }

//     // std::cout << "push loner" << std::endl;
//     // if loner
//     if (v.size() % 2 == 1)
//     {
//         pos = find_place(loner);
//         chain.insert(chain.begin() + pos, loner);
//     }
// }

// void PmergeMe::merge_sort(int start, int mid, int end)
// {
//     std::cout << "merging " << start << " - " << mid << " - " << end << std::endl;

//     int ns = mid + 1;
//     int ne = end;

//     int s = start;
//     int e = mid + 1;
//     int k = start;

//     for ( ; s < ns && e < ne + 1; k++)
//     {
//         std::cout << "r/l: [" << s << "] " << pv[s].first << " / [" << e << "] " << pv[e].first << std::endl;
//         if (pv[s] >= pv[e])
//         {
//             std::cout << "--- swap: [" << s << "] " << pv[s].first << " <- [" << e << "] " << pv[e].first << std::endl;
//             std::swap(pv[s], pv[e]);
//             e++;
//         }
//         else
//         {
//             // std::swap(pv[s], pv[e]);
//             s++;
//         }
//     }

//     std::cout << "s = " << s << std::endl;
//     std::cout << "e = " << e << std::endl;
//     std::cout << "k = " << k << std::endl;

//     for (; s < ns; ++s)
//     {
//         std::cout << "k/s: [" << k << "] " << pv[k].first << " / [" << s << "] " << pv[s].first << std::endl;
//         if (pv[k] <= pv[s])
//         {
//             std::cout << "--- swap: [" << k << "] " << pv[k].first << " <- [" << s << "] " << pv[s].first << std::endl;
//             std::swap(pv[k], pv[s]);
//             k++;
//         }
//     }
//     for (; e < ne; ++e)
//     {
//         std::cout << "k/e: [" << k << "] " << pv[k].first << " / [" << e << "] " << pv[e].first << std::endl;
//         if (pv[k] >= pv[e])
//         {
//             std::cout << "--- swap: [" << k << "] " << pv[k].first << " <- [" << e << "] " << pv[e].first << std::endl;
//             std::swap(pv[k], pv[e]);
//             k++;
//         }
//     }
// }

// void PmergeMe::sort_pairs()
// {
//     std::cout << "sorting" << std::endl;
//     // divide vector to pairs of 2 then 4. 8. 16 ...
//     for (int div = 1; div < (int) pv.size() - 1; div *= 2)
//     {
//         std::cout << "div = " << div << std::endl;
//         for (int pair = 0; pair < (int) pv.size(); pair += div)
//         {
//             std::cout << "pair [" << pair << "] : ";
//             for (int i = 0; i < div; ++i)
//                 std::cout << pv[pair + i].first << " ";
//             std::cout << std::endl;
//         }

//         // loop over and compaire all pair
//         for (int pair = 0; pair < (int) pv.size() - 1; pair += div)
//         {
//             // std::cout << "swaping [" << pair + div - 1 << "] ?? [" << pair + (div * 2) - 1 << "]" << std::endl;
//             // std::cout << "swaping " << pv[pair + div - 1].first << " ?? " << pv[pair + (div * 2) - 1].first << std::endl;
//             // if (pv[pair + div - 1] > pv[pair + (div * 2) - 1])
//             if (pv[pair].first > pv[pair + div].first)
//             {
//                 std::cout << "swaping " << pair << " -> " << pair + div << std::endl;
//                 // swap all membres of the pair
//                 for (int l = 0; l < div && pair + div + l < (int) pv.size(); ++l)
//                 {
//                     std::swap(pv[pair + l], pv[pair + div + l]);
//                 }
//             }
//         }
//     }
// }

// void PmergeMe::sort_pairs()
// {
//     // sort 
//     for (int i = 0; i < (int) pv.size() - 1; i++)
//     {
//         bool swaped = false;
//         for (int j = 0; j < (int) pv.size() - i - 1; ++j)
//         {
//             if (pv[j].first > pv[j + 1].first)
//             {
//                 std::swap(pv[j], pv[j + 1]);
//                 swaped = true;
//             }
//         }
//         if (swaped == false)
//             break ;
//     }
// }
