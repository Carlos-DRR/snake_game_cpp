template <class T>

class Node{
    private:
        T info;
        Node *next;

    public:
        Node(T info){
            this->info = info;
            this->next = nullptr;
        }

        T getInfo(){
            return info;
        }

        void setInfo(T info){
            this->info = info;
        }

        Node *getNext(){
            return next;
        }

        void setNext(Node * next){
            this->next = next;
        }
};