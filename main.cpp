//Alexander Urbanyak

#include <iostream>
#include <list>

int get_max(std::list<int> my_list);

void radix(std::list<int>* my_list);

int main(){
    int my_array[] = {11, 7, 8, 19, 24, 82, 0, 5, 16, 23, 12, 20, 4, 45, 66};
    std::list<int> my_list (my_array, my_array + sizeof(my_array) / sizeof(int));;

    std::cout << "Unsorted list:\t";
    for (std::list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';

    radix(&my_list);

    std::cout << "Sorted list:\t";
    for (std::list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}

int get_max(std::list<int> my_list){
    int max = 0;

    while(!my_list.empty()){
        if(my_list.front() > max){
            max = my_list.front();
        }
        my_list.pop_front();
    }
    return max;
}

void radix(std::list<int>* my_list){
    std::list<int> list1;
    std::list<int> list2;
    int max = get_max(*my_list);
    int divisor = 1;
    int size = my_list->size();

    while(max > divisor){
        for(int i = 0; i < size; i++){
            if((my_list->front() / divisor) % 2 == 0){
                list1.push_back(my_list->front());
            }
            else{
                list2.push_back(my_list->front());
            }
            my_list->pop_front();
        }

        divisor = 2 * divisor;
        while (!list1.empty()){
            my_list->push_back(list1.front());
            list1.pop_front();
        }
        while (!list2.empty()){
            my_list->push_back(list2.front());
            list2.pop_front();
        }
    }
}
