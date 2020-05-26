
#include <mysortfunctions.h>


void merge(int begin, int middle, int end, std::vector<int> &ov, std::vector<int> &v){
    int iterator = begin, iterator1 = begin, iterator2 = middle+1;
    while(iterator<=end){
        if(iterator1>middle) ov[iterator++] = v[iterator2++];
        else if(iterator2>end) ov[iterator++] = v[iterator1++];
        else{
            if(v[iterator1]<=v[iterator2]) ov[iterator++] = v[iterator1++];
            else ov[iterator++] = v[iterator2++];
        }
    }
    for(int j = begin; j <= end; ++j) v[j] = ov[j];
}

void merge_recursive(int begin, int end, std::vector<int> &ov, std::vector<int> &v, SortStats &stats){
    stats.recursive_calls++;
    stats.custom1++;
    if(begin<end){
        int middle = (begin+end)/2;
        merge_recursive(begin, middle, ov, v, stats);
        if(stats.depth_recursion_stack < stats.custom1) stats.depth_recursion_stack = stats.custom1;
        stats.custom1--;
        merge_recursive(middle+1, end, ov, v, stats);
        if(stats.depth_recursion_stack < stats.custom1) stats.depth_recursion_stack = stats.custom1;
        stats.custom1--;
        merge(begin, middle, end, ov, v);
    }
}

void mymergesort_recursive(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 0;
    std::vector<int> ordered_vector(v.size());
    merge_recursive(0, v.size()-1, ordered_vector, v, stats);
}

void mymergesort_iterative(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
	int begin = 0, end = v.size() - 1;
    std::vector<int> ordered_vector(v.size());
    int from, mid, to;
    for (int s = 1; s <= end - begin; s = (s << 1))
	{
		for (int i = begin; i < end; i += (s << 1))
		{
			from = i;
			mid = i + s - 1;
			to = std::min(i + (s << 1) - 1, end);
			merge(from, mid, to, ordered_vector, v);
		}
	}    
}
    
