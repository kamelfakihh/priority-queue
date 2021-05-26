#ifndef PRIORITY_QUEUE_MINPQ
#define PRIORITY_QUEUE_MINPQ

#include <vector>

template <typename item>
class MinPQ {

public:

    MinPQ();                                    // construct an empty queue
    MinPQ(std::vector<item> &content);           // construct a queue from a vector
    MinPQ(item content[], int nb_of_items);     // construct a queue from an array

    void insert(item it);                       // insert an item to the end of the queue
    item delMin();                              // remove the minimum item 
    int  size();
    bool isEmpty();

private:

    void swim(int k);                           // moves item upwards in the tree to maintain heap order
    void sink(int k);                           // moves item downwards in the tree to maintain heap order

    bool less(int n1, int n2);                  // check if n1 < n2
    void exchange(int n1, int n2);              // exchange items at index n1 and n2

    std::vector<item> content;                  // index of item represent its position in the binary heap 

};

template <typename item>
MinPQ<item>::MinPQ() : content(std::vector<item>()) {}

template <typename item>
MinPQ<item>::MinPQ(std::vector<item> &c) : content(std::vector<item>()) 
{

    for (std::vector<int>::iterator i = std::begin(c); i != std::end(c); i++){

        this->insert(i);
    }
}

template <typename item>
MinPQ<item>::MinPQ(item c[], int n) : content(std::vector<item>()) 
{
    for(unsigned int i=0; i<n; i++){

        this->insert(c[i]);
    }
}

template <typename item>
void MinPQ<item>::insert(item it){

    content.push_back(it);      // insert item at the back
    swim(size()-1);             // move it to its position in the heap order
}

template <typename item>
item MinPQ<item>::delMin(){

    item Min = content[0];
    exchange(0, size()-1);         // exchange first and last item
    content.pop_back();
    sink(0);                       // move the item currently in Min pos to its position in heap order
    return Min; 
}

template <typename item>
void MinPQ<item>::swim(int k){

    // if parent's value is less than the item 
    // exchange an item (k) with its parent (k/2)
    // (root item does not have a parent)

    while(k>0 && less(k/2, k)){

        exchange(k, k/2);
        k = k/2;
    }
}

template <typename item>
void MinPQ<item>::sink(int k){

    // if child's value is greater than the item 
    // exchange an item (k) with its greatest child (2k or 2k+1)
    // (a leaf does not have any childs)
    int j;

    while( 2*k <= this->size()-1){

        // assumes that first child is the largest
        j = 2*k;    
        
        // compare both childs at 2k and 2k+1
        // select largest       
        if( j < this->size() - 1 && less(j, j+1) ){
            j+=1;
        }

        // check if child node is larger than current item
        if(!less(k , j)) break;

        exchange(k, j);
        k = j;
    }
}

template <typename item>
bool MinPQ<item>::less(int n1, int n2){

    return content[n1] < content[n2];
}

template <typename item>
void MinPQ<item>::exchange(int n1, int n2){

    item temp = content[n1];
    content[n1] = content[n2];
    content[n2] = temp;
}

template <typename item>
int MinPQ<item>::size(){

    return content.size();
}

template <typename item>
bool MinPQ<item>::isEmpty(){

    return content.size() == 0;
}

#endif