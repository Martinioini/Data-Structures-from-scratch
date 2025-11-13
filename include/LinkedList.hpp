#pragma once
#include <cstddef>
#include <stdexcept>

template<typename T>

class LinkedList{

    struct Node{
        T data;
        Node* next;
        Node(const T& val, Node* el = nullptr) : data(val), next(el) {}
    };

    private:
    
        Node* head_;
        Node* tail_;
        std::size_t size_;
    
    public:

        LinkedList() : head_(nullptr), tail_(nullptr), size_(0){}

        LinkedList(std::initializer_list<T> values) : head_(nullptr), tail_(nullptr), size_(0){
            for(const T& val: values){
                push_back(val);
            }
        }

        LinkedList(const LinkedList& other): head_(nullptr), tail_(nullptr), size_(0){

            Node* curr = other.head_;
            while(curr){
                push_back(curr->data);
                curr = curr->next;
            }
        }

        LinkedList& operator=(const LinkedList& other) {

            if (this == &other)
                return *this;

            Node* curr = head_;
            while (curr) {
                Node* next = curr->next;
                delete curr;
                curr = next;
            }
            head_ = tail_ = nullptr;
            size_ = 0;

            curr = other.head_;
            while (curr) {
                push_back(curr->data);  
                curr = curr->next;
            }

            return *this;
        }


        ~LinkedList(){
            if(size_ == 0){
                return;
            }
            Node* curr = head_;
            while(curr){
                Node* next = curr->next;
                delete curr;
                curr = next;
            }
        }

        void push_back(const T &elem){

            if(!head_){
                Node* newNode = new Node{elem};
                head_ = newNode;
                tail_ = newNode;  
            }
            else{
                Node* newNode = new Node{elem};
                tail_->next = newNode;
                tail_ = newNode;
            }
            size_++;
        }

        void push_front(const T &elem){
            
            if (!head_)
            {
                Node* newNode = new Node{elem, head_};
                head_ = newNode;
                tail_ = newNode;
            }
            
            else{
                Node* newNode = new Node{elem, head_};
                head_ = newNode;
            }
            size_++;
        }

        const T& get_top(){

            if(size_ == 0){
                throw std::out_of_range("Empty List");
            }
            return head_->data;
        }

        const T& get_last(){

            if(size_ == 0){
                throw std::out_of_range("Empty List");
            }
            return tail_->data;
        }
};
