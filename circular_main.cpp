#include <iostream>
#include "tester.h"
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray(int _capacity = 10);
    virtual ~CircularArray(){
        delete[] array;
    }
    void push_front(T data){
        if(is_full()) {rezise();}
        array[prev(front)] = data;
    }
    void push_back(T data){
        if(is_full()) {rezise();}
        array[next(back)] = data;
    }
    void insert(T data, int pos){ // <- falta implementar
        if(is_full()) {rezise();}
        if(pos < 0 || pos > size()) {std::cout << "The position is not valid" << std::endl; return;}
        
    }
    T pop_front(){
        if(is_empty()) {return -1;}
        int temp=front;
        if(front == back) {front = back = -1; return array[temp];}
        next(front);
        return array[temp];
    T pop_back(){
        if(is_empty()) {return -1;}
        int temp = back; 
        if(front == back) {front = back = -1; return array[temp];}
        prev(back);
        return array[temp];
    }
    bool is_full(){
        if((front == 0 && back == capacity -1) || (front == back + 1)) return true;
        return false;
    }
    bool is_empty(){
        return (front == -1 && back == -1);
    }
    int size(){
        return (back - front + capacity + 1) % capacity;
   
    void clear(){
        front = back = -1;
    }
    T& operator[](int index){
        return array[(front + index) % capacity];
    }
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" "){
        string result{};
        int start=front;
        int end=back;
        if(is_empty()) return result;
        if(front == -1) start = 0;
        if(end == -1) end = capacity - 1;
        int times = (end - start + capacity + 1) % capacity;
        for(int i = 0; i < times; i++){
            result += std::to_string(array[(start + i) % capacity]) + sep;
        }
        return result;
    }

private:
    int next(int& index){return (index + 1) % this->capacity;}
    int prev(int& index){
        if(index == -1){
            index = capacity - 1;
            return index;
        }
        return (index - 1 + this->capacity) % this->capacity;}
};

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;//empty
}



int main() {
//    CircularArray<int>* array = new CircularArray<int>(7);
//    ASSERT(array->is_empty() == true, "The function is_empty is not working");
//    array->push_back(6);
//    array->push_back(3);
//    array->push_back(7);
//    array->push_back(8);
//    array->push_back(1);
//    ASSERT(array->is_empty() == false, "The function is_empty is not working");
//    ASSERT(array->is_full() == false, "The function is_full is not working");
//    array->push_front(10);
//    array->push_front(2);       
//    ASSERT(array->is_full() == true, "The function is_full is not working");
//    ASSERT(array->to_string() == "2 10 6 3 7 8 1 ", "The function push_front is not working");
//    array->pop_front(); 
//    array->pop_front(); 
//    array->pop_front(); 
//    array->push_back(15);
//    array->push_back(9);
//    array->push_back(4);         
//    ASSERT(array[0] == 3 && array[6] == 4, "The operator [] is not working");    
//    ASSERT(array->is_sorted() == false, "The function is_sorted is not working");
//    array->sort();
//    ASSERT(array->to_string() == "1 3 4 7 8 9 15 ", "The function sort is not working");
//    array->reverse();
//    ASSERT(array->to_string() == "15 9 8 7 4 3 1 ", "The function reverse is not working");   
//    array->insert(10, 1);       
//   array->pop_back();  
//    ASSERT(array->size() == 7, "The function size is not working");   
//    delete array;
    return 0;
}
