#ifndef PRIORITY_QUEUE_MAXPQ
#define PRIORITY_QUEUE_MAXPQ

#include "PriorityQueue/PriorityQueue.h"

#include <vector>

template <typename item>
class MaxPQ : public PriorityQueue<item> {

public:

    MaxPQ();                                            // construct an empty queue
    MaxPQ(std::vector<item> &content);                  // construct a queue from a vector
    MaxPQ(item content[], int nb_of_items);             // construct a queue from an array

    item delMax();                                      // calls parent del() method 

private:

    bool compare(int n1, int n2) override;              // check if n1 > n2

};

template <typename item>
MaxPQ<item>::MaxPQ() : PriorityQueue<item>() {}

template <typename item>
MaxPQ<item>::MaxPQ(std::vector<item> &c) : PriorityQueue<item>(c) 
{

}

template <typename item>
MaxPQ<item>::MaxPQ(item c[], int n) : PriorityQueue<item>(c, n)
{
    
}

template <typename item>
item MaxPQ<item>::delMax(){

    return this->del();
}

template <typename item>
bool MaxPQ<item>::compare(int n1, int n2){

    return this->content[n1] > this->content[n2];
}


#endif