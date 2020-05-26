#include <queue>
#include <mysortfunctions.h>


void myradixsort(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    std::vector<std::queue<int>> rows(16);
    int selector = 0xF;
    for(int i = 0; (1 << (i << 2)) < v.size(); ++i){
        for(int j = 0; j < v.size(); ++j) rows[(v[j] & selector)>>(i << 2)].push(v[j]);
        int counter = 0;
        for(int j = 0; j < 16; ++j){
            while(!rows[j].empty()){
                v[counter] = rows[j].front();
                rows[j].pop();
                counter++;
            }
        }
        selector = selector << 4;
    }
}
