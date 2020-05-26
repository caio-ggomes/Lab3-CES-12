
#include <mysortfunctions.h>

// you only need to mantain the headers. You can create aux funcs, objects, or create a generic quicksort that can work with different functions to select the pivot.
int first_element(std::vector<int> &v, int begin, int end){troca(v, begin, end); return end;}

int median3(std::vector<int> &v, int begin, int end){
    int pivot1 = begin, pivot2 = (begin+end)/2, pivot3 = end;
    if((v[pivot1] >= v[pivot2] && v[pivot1] <= v[pivot3])||(v[pivot1] >= v[pivot3] && v[pivot1] <= v[pivot2])) troca(v, pivot1, end);
    else if((v[pivot2] >= v[pivot1] && v[pivot2] <= v[pivot3])||(v[pivot2] >= v[pivot3] && v[pivot2] <= v[pivot1])) troca(v, pivot2, end);
    else troca(v, pivot3, end);
    return end;
}

int partition(std::vector<int> &v, int begin, int end, int pivot_function(std::vector<int>&, int, int)){
    int pivot = v[pivot_function(v, begin, end)];
    int i = begin - 1;
    for(int j = begin; j < end; ++j){
        if(v[j] <= pivot){++i; troca(v, i, j);}
    }
    troca(v, i + 1, end);
    return i + 1;
}

void quicksort_2recursion(std::vector<int> &v, int begin, int end, SortStats &stats, int pivot_function (std::vector<int>&, int, int)){
    stats.recursive_calls++;
    stats.custom1++;
    if(begin<end){
        int pivot = partition(v, begin, end, pivot_function);
        quicksort_2recursion(v, begin, pivot - 1, stats, pivot_function);
        if(stats.custom1 > stats.depth_recursion_stack) stats.depth_recursion_stack = stats.custom1;
        stats.custom1--;
        quicksort_2recursion(v, pivot + 1, end, stats, pivot_function);
        if(stats.custom1 > stats.depth_recursion_stack) stats.depth_recursion_stack = stats.custom1;
        stats.custom1--;
    }
}

void quicksort_1recursion(std::vector<int> &v, int begin, int end, SortStats &stats, int pivot_function (std::vector<int>&, int, int)){
    stats.recursive_calls++; stats.custom1++;
    int pivot;
    while(begin<end){
        pivot = partition(v, begin, end, pivot_function);
        quicksort_1recursion(v, begin, pivot - 1, stats, pivot_function);
        if(stats.custom1 > stats.depth_recursion_stack) stats.depth_recursion_stack = stats.custom1;
        stats.custom1--;
        begin = pivot + 1;
    }
}

/// the most comon quicksort, with 2 recursive calls
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 0;
    quicksort_2recursion(v, 0, v.size()-1, stats, median3);
}// function myquicksort_2recursion_medianOf3

/// quicksort with one recursive call
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 0;
    quicksort_1recursion(v, 0, v.size()-1, stats, median3);
} // function myquicksort_1recursion_medianOf3

/// quicksort with fixed pivot 
/// be sure to compare with equivalent implementation 
/// e.g., if you do 1 recursive call, compare with the 1recursion version
void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 0;
    quicksort_2recursion(v, 0, v.size()-1, stats, first_element);
} // myquicksort_fixedPivot


