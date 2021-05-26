#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE


#include <vector>

template <typename item>
class PriorityQueue {

public:

    PriorityQueue();                                     // construct an empty queue
    PriorityQueue(std::vector<item> &content);           // construct a queue from a vector
    PriorityQueue(item content[], int nb_of_items);      // construct a queue from an array

    void insert(item it);                                // insert an item to the end of the queue
    int  size();
    bool isEmpty();

private:


    void swim(int k);                                   // moves item upwards in the tree to maintain heap order
    void sink(int k);                                   // moves item downwards in the tree to maintain heap order

    virtual bool compare(int n1, int n2)  = 0;          // compare items at n1 and n2
    void exchange(int n1, int n2);                      // exchange items at n1 and n2

protected:

    item del();                                         // remove the maximum/minimum item 
    std::vector<item> content;                          // index of item represent its position in the binary heap 

};

template <typename item>
PriorityQueue<item>::PriorityQueue() : content(std::vector<item>()) {}

template <typename item>
PriorityQueue<item>::PriorityQueue(std::vector<item> &c) : content(std::vector<item>()) 
{

    for (std::vector<int>::iterator i = std::begin(c); i != std::end(c); i++){

        this->insert(i);
    }
}

template <typename item>
PriorityQueue<item>::PriorityQueue(item c[], int n) : content(std::vector<item>()) 
{
    for(unsigned int i=0; i<n; i++){

        this->insert(c[i]);
    }
}

template <typename item>
void PriorityQueue<item>::insert(item it){

    content.push_back(it);      // insert item at the back
    swim(size()-1);             // move the item to its position in the heap order
}

template <typename item>
item PriorityQueue<item>::del(){

    item Del = content[0];
    exchange(0, size()-1);         // exchange first and last item
    content.pop_back();
    sink(0);                       // move the item currently in Min/Max pos to its position in heap order
    return Del; 
}

template <typename item>
void PriorityQueue<item>::swim(int k){

    // if parent's value is smaller/greate than the item 
    // exchange an item (k) with its parent (k/2)
    // (root item does not have a parent)

    while(k>0 && compare(k/2, k)){

        exchange(k, k/2);
        k = k/2;
    }
}

template <typename item>
void PriorityQueue<item>::sink(int k){

    // if child's value is greater/smaller than the item 
    // exchange an item (k) with its greatest/smallest child (2k or 2k+1)
    // (a leaf does not have any childs)
    int j;

    while( 2*k <= this->size()-1){

        // assumes that first child is the largest/smallest
        j = 2*k;    
        
        // compare both childs at 2k and 2k+1
        // select largest/smallest       
        if( j < this->size() - 1 && compare(j, j+1) ){
            j+=1;
        }

        // check if child node is larger/smaller than current item
        if(!compare(k , j)) break;

        exchange(k, j);
        k = j;
    }
}

template <typename item>
void PriorityQueue<item>::exchange(int n1, int n2){

    item temp = content[n1];
    content[n1] = content[n2];
    content[n2] = temp;
}

template <typename item>
int PriorityQueue<item>::size(){

    return content.size();
}

template <typename item>
bool PriorityQueue<item>::isEmpty(){

    return content.size() == 0;
}

#endif