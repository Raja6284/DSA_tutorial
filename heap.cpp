#include <iostream>
using namespace std;

class heap{

    public:
    int arr[100];
    int size = 0;

    void insert(int val){
        //in the 0th index of array , we are not filling any thing;
        size = size+1;
        int index = size;
        arr[index] = val;
       
       
        while(index > 1){
            //parent of the node which at index position in the max heap

            int parent = index/2;   //1 based indexing

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deletefromHeap(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return;
        }

        arr[1] = size;
        size--;

        int index = 1;
        while(index < size){

            int left_index = 2*index;
            int right_index = 2*index+1;

            if(left_index < size && arr[index] < arr[left_index]){
                swap(arr[index],arr[left_index]);
                index = left_index;
            }
            else if(right_index < size && arr[index] < arr[right_index]){
                    swap(arr[index] , arr[right_index]);
                    index = right_index;
                }
                else{
                    return;
                }
            }
            
        }
    
    void print(){
     for(int i = 1; i<=size; i++){
        cout<<arr[i]<<" ";
     }
     cout<<endl;
}
};


int main(){
    
    heap h;
    h.insert(55);
    h.insert(63);
    h.insert(36);
    h.insert(45);
    h.insert(72);
    h.insert(60);

    h.print();

    h.deletefromHeap();
     h.print();
    h.deletefromHeap();
     h.print();
    h.deletefromHeap();
     h.print();
    h.deletefromHeap();
     h.print();
    h.deletefromHeap();
     h.print();
    h.deletefromHeap();
     h.print();
    h.deletefromHeap();
    h.print();


    return 0;
}