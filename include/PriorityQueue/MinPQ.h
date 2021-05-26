#ifndef PRIORITY_QUEUE_MINPQ
#define PRIORITY_QUEUE_MINPQ

#include "PriorityQueue/PriorityQueue.h"
    
#include <vector>

template <typename item>
class MinPQ : public PriorityQueue<item> {

public:

    MinPQ();                                        // construct an empty queue
    MinPQ(std::vector<item> &content);              // construct a queue from a vector
    MinPQ(item content[], int nb_of_items);         // construct a queue from an array

    item delMin();                                  // calls parent del() protetced method (name hiding)

private:

    bool compare(int n1, int n2);                   // check if n1 < n2

};

template <typename item>
MinPQ<item>::MinPQ() : PriorityQueue<item>() {}

template <typename item>
MinPQ<item>::MinPQ(std::vector<item> &c) : PriorityQueue<item>(c) 
{

}

template <typename item>
MinPQ<item>::MinPQ(item c[], int n) : PriorityQueue<item>(c, n)
{

}

template <typename item>
item MinPQ<item>::delMin(){


    return this->del();
}

template <typename item>
bool MinPQ<item>::compare(int n1, int n2){

    return this->content[n1] < this->content[n2];
}

#endif