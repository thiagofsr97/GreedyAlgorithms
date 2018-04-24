//
// Created by thiagofsr on 23/04/18.
//

#ifndef GREEDYALGORITHMS_HEAP_H
#define GREEDYALGORITHMS_HEAP_H
#define CMP(a,b) ((a) > (b))


#include <cstdio>
#include <algorithm>
#include <iostream>

enum HeapLabel{MAX ,MIN};
template <class Type>
class Heap {
private:
    Type *heapTable;
    unsigned long size;
    unsigned long length;
    void Swap(int a, int b);
    HeapLabel isMaxHeap;
public:
    ~Heap();
    Type GetTop();
    Heap(unsigned long size,const Type* heap,HeapLabel heapLabel);
    Heap(unsigned long size,HeapLabel heapLabel);
    void Heapify(int node);
    int GetParent(int);
    int GetLeftChild(int);
    int GetRightChild(int);
    bool IsEmpty();
    bool IsFull();
    unsigned long GetSize();
    unsigned long GetLenght();
    void BuildHeapfied();
    const Type & GetHeap();

    int Insert(Type);
    Type ExtractTop(bool*);
    void ClearHeap();
};


/**
 *  @file    Heap.cṕp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    03/05/2018
 *  @version 1.0
 *
 *  @brief Implementation of a Maximum and Minimum Heap.
 *
 */

#include "Heap.h"

/***
 * Initialize the heap array by copying an already existing
 * array and also determines either the heap is of maximum
 * or minimum.
 *
 * @param [in] size how many elements the heap array will hold.
 * @param [in] *table pointer to the already existing array of elements.
 * @param [in] label enumerator value to identify if it's a Maximum or
 * Minimum heap.
 * @return none
 */

template<class Type>
Heap<Type>::Heap(unsigned long size, const Type *heap, HeapLabel heapLabel) {
    this->heapTable = new Type[size];
    std::copy(heap,heap + size,this->heapTable);
    this->size = size;
    this->length = size;
    isMaxHeap = heapLabel;

}

/***
 * Initialize the heap array with its size and sets size to 0.
 * Also determines either the heap is of maximum
 * or minimum.
 *
 * @param [in] size how many elements the heap array will hold.
 * @param [in] label enumerator value to identify if it's a Maximum or
 * Minimum heap.
 * @return none
 */

template<class Type>
Heap<Type>::Heap(unsigned long size, HeapLabel heapLabel) {
    this->heapTable = new Type[size];
    this->size = 0;
    this->length = size;
    isMaxHeap = heapLabel;
}

/***
 * Destruction overload to make sure
 * the allocation of the heap will be done.
 * @param none.
 * @return none
 */
template <class Type>
Heap<Type>::~Heap(){delete []this->heapTable; }

/***
 * Utilitary function to swap two elements in the array.
 * @param [in] a index to first element.
 * @param [in] b index to second element.
 * @return none
 */
template<class Type>
void Heap<Type>::Swap(int a, int b) {
    Type aux;
    aux = heapTable[b];
    heapTable[b] = heapTable[a];
    heapTable[a] = aux;

}

/***
 * Given a certain index, it will return this node parent, if exists.
 * Note: the heap abstraction works with 1 indexed arrays. A adaption was
 * made to make it work for 0 indexed arrays.
 * @param [in] i index of the current node.
 * @return -1 if parent doesn't exists or heap is empty. Parent index if exists.
 */
template <class Type>
int Heap<Type>::GetParent(int i) {
    if(IsEmpty())
        return -1;
    return (i%2 == 0)? (i/2)-1:(i/2);
}

/***
 * Given a certain index, it will return this node left child, if exists.
 * Note: the heap abstraction works with 1 indexed arrays. A adaption was
 * made to make it work for 0 indexed arrays.
 * @param [in] i index of the current node.
 * @return -1 if parent doesn't exists or heap is empty. Left child index if exists.
 */
template <class Type>
int Heap<Type>::GetLeftChild(int i) {return IsEmpty()? (-1):(2*(i+1))-1;}
/***
 * Given a certain index, it will return this node right child, if exists.
 * Note: the heap abstraction works with 1 indexed arrays. A adaption was
 * made to make it work for 0 indexed arrays.
 * @param [in] i index of the current node.
 * @return -1 if parent doesn't exists or heap is empty. Right child index if exists.
 */
template <class Type>
int Heap<Type>::GetRightChild(int i) {return IsEmpty()? (-1):2*(i+1);}

/***
 * Utilitary function to check if heap is empty.
 * @param none.
 * @return true if is empty or false if not.
 */
template <class Type>
bool Heap<Type>::IsEmpty() {return this->size == 0? true:false;}
/***
 * Utilitary function to check if heap is full.
 * @param none.
 * @return true if is full or false if not.
 */
template <class Type>
bool Heap<Type>::IsFull() { return this->size == length? true:false;}
/***
 * Utilitary function to check heap current size.
 * @param none.
 * @return size of the heap.
 */
template <class Type>
unsigned long Heap<Type>::GetSize() {return this->size;}

/***
 * Utilitary function to check heap's lenght (maximum size).
 * @param none.
 * @return lenght of the heap.
 */
template <class Type>
unsigned long Heap<Type>::GetLenght() { return this->length;}

/***
 * Exchange positions of nodes (elements) in the array, mainting
 * the condition of either maximum or minimum heap.
 * The process consists in given a certain node, check if its value
 * is greater (maximum) or smaller (minimum) than its children.
 * If the condition is not accepted, then exchanges will be made
 * until it reaches the condition or a leap is found.
 * @param [in] node index of node which will be heapfied.
 * @return none.
 */
template <class Type>
void Heap<Type>::Heapify(int node) {

    int left, right, aux;

    left = GetLeftChild(node);
    right = GetRightChild(node);

    if(isMaxHeap == MAX){
        if(left < size && CMP(heapTable[left],heapTable[node]))
            aux = left;
        else
            aux = node;

        if(right < size && CMP(heapTable[right],heapTable[aux]))
            aux = right;

    }else{
        if(left < size && CMP(heapTable[node],heapTable[left]))
            aux = left;
        else
            aux = node;
        if(right < size && CMP(heapTable[aux],heapTable[right]))
            aux = right;
    }

    if(aux != node) {
        Swap(aux, node);
        Heapify(aux);
    }

}

/***
 * Given any array of elements, this method will turn it into a
 * maximum or minimum heap. The process consists in running a loop
 * from half the heap size until its first element. This happens
 * given the fact that the leaps do not need to be heapfied.
 * @param none.
 * @return none.
 */
template <class Type>
void Heap<Type>::BuildHeapfied() {

    if(GetSize() == 0) return;

    for(int i = (GetSize()/2) - 1; i>=0;i--)
        Heapify(i);
}

/***
 * Inserts an element in the heap by mainting its condition
 * of maximum or minimum heap.
 * @param [in] element value of the node.
 * @return -1 if heap is full or 0 if insertion was a sucess.
 */
template <class Type>
int Heap<Type>::Insert(Type element){
    if(IsFull())
        return -1;
    heapTable[size++] = element;
    int current,parent;
    current = size-1;
    if(isMaxHeap == MAX){
        while( (parent = GetParent(current)) >-1 && CMP(heapTable[current],heapTable[parent])){

            Swap(current,parent);
            current = parent;


        }
    }else{
        while( (parent = GetParent(current)) >= 0 && CMP(heapTable[parent],heapTable[current])){
            Swap(current,parent);
            current = parent;
        }
    }
    return 0;

}


/***
 * Extracts an element from the heap by mainting its condition
 * of maximum or minimum heap.
 * @param [out] sucess flag to indicate sucess or failure from operation.
 * @return -1 if heap is empty or value if extraction was a sucess.
 */
template<class Type>
Type Heap<Type>::ExtractTop(bool *sucess){
    if(IsEmpty()){
        if(sucess != nullptr)
            *sucess = false;
        return nullptr;
    }
    if(sucess != nullptr)
        *sucess = true;
    Type top = heapTable[0];
    Swap(0,size - 1);
    size--;
    Heapify(0);

    return top;

}

/***
 * Utilitary function to get a copy of the heap.
 * @param none.
 * @return constant pointer to heap's array.
 */
template<class Type>
const Type& Heap<Type>::GetHeap() {

    return *heapTable;
}
/***
  * Utilitary function to clear a heap by deleting
  * the dynamic allocation of the array and settings
  * the heap's properties to default values.
  * @param none.
  * @return none.
  */
template <class Type>
void Heap<Type>::ClearHeap() {
    this->length = 0;
    this->size = 0;
    delete []this->heapTable;
}

template<class Type>
Type Heap<Type>::GetTop() {
    if(IsEmpty())
        return nullptr;
    return heapTable[0];
}


#endif //GREEDYALGORITHMS_HEAP_H
