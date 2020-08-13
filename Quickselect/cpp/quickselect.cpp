#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>

class orderStatistics {
    typedef int value_type;
    typedef std::vector<int> collection_type;
    typedef collection_type::const_iterator const_iterator_type;
    typedef collection_type::iterator iterator_type;

    private:
        std::random_device random_dev;
        std::mt19937 random_generator;
        std::vector<int> arr;
        int order;
    public:
        orderStatistics(const_iterator_type begin, const_iterator_type end, int order):  random_generator(random_dev()){
            // initializes the arr vector with copying the data from the supplied begin and end iterator
            // initializes the random_generator object with the random_dev

            std::copy(begin, end, std::back_inserter(arr));
            this->order = order;
        }

        iterator_type random_it(iterator_type begin, iterator_type end){
            // creates a uniform distribution from 0 and length of the array between begin and end
            // generates a random displacement integer between that range 
            // if an array arr is of 10 elements
            // the thing is, std::distance(arr.begin(), arr.end()) would be 10. 
            // and random generator generates between 0 and std::distance inclusively, hence between and including 0 and 10
            // thus, the end should be shifted left once before calling random_it
            // adding delta shift to begin gives us the iterator to the random cell

            std::uniform_int_distribution<> dist(0, std::distance(begin, end));
            std::size_t delta = dist(random_generator);
            return begin + delta;
        }
        std::size_t length() const {
            return arr.size();
        }

        void print(){
            std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl;
        }
        iterator_type random_partition(iterator_type begin, iterator_type end) {
            // uses a randomly selected iterator to swap with the last element 
            // refer to random_it docs to understand how end iterator is used

            std::swap(*random_it(begin, end), *end);
            iterator_type last_less = begin;
            for(auto it = begin; it != end; ++it){
                if(*it <= *end){
                    std::swap(*it, *last_less);
                    ++last_less;
                }
            }
            std::swap(*last_less, *end);
            return last_less;
        }
        
        int quickselect(iterator_type begin, iterator_type end, int order) {
                // end iterator points to the last element instead of the address after the last element (needs to be specified)

                iterator_type random_iter = random_partition(begin, end);
                
                std::size_t delta = std::distance(begin, random_iter);
               
                if (delta == order) {
                    return *random_iter;
                }
                else if (order < delta) {
                    return quickselect(begin, random_iter-1, order);
                }
                else {
                    return quickselect(random_iter, end, order - delta);
                }
        }

        void quickselect_helper() {
            std::cout << order << "-th order statistics: " << quickselect(arr.begin(), arr.end()-1, order-1) << std::endl;
        }
};
    


int main() {
    int order;
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    while (true) {
        std::cout << "Enter which order statistic you want to find: ";
        std::cin >> order;
        if (order > std::distance(v.begin(), v.end()) || order <= 0) std::cout << "Enter a valid order" << std::endl;
        else break;
    }
    
    // order should be between 1 and arr.size() 
    
    // std::shuffle(v.begin(), v.end(), gen);
    orderStatistics oStat(v.begin(), v.end(), order);
    oStat.quickselect_helper();
    return 0;
};