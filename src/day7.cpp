#include "includes/adventofcode.hpp"
#include "includes/helpers.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <sstream>
#include <tuple>

std::string day7p1(std::vector<std::vector<std::string>> input)
{
    std::unordered_map<std::string, std::string> memory;
    std::string tracking = input[0][0];
    for(const auto &vec: input)
    {
        for(size_t index=3; index < vec.size(); index++)
        {
            memory[vec[index]] = vec[0];
            while(memory[tracking] != "")
            {
                tracking = memory[tracking];
            }
        }
    }
    return tracking;
}

//here I am saying that an actual tree data structure is needlessly complex
//for this puzzle. But as I started implementing the tree in an unordered
//map, my head just started to hurt
//
//The implementation is easy, but the questions of "what do I do when this happens"
//becomes a bit too much to implement, especially for something I'm supposed to be
//doing for fun
//
//I'll skip this part for now
//
//TODO(mikeb) Implement Day 7 part 2
// long day7p2(std::vector<std::vector<std::string>> input)
// {
//     // building an actual tree is way too complex of a solution
//     // especially because the tree is not ordered in any way
//     // we could implement a tree like data structure using
//     // unordered maps
//     std::unordered_map<std::string, std::vector<std::string> > nodes;
//     std::unordered_map<std::string, std::string> reverse_map;
//     std::unordered_map<std::string, long> sizes;
//     std::string str_weight;
//     long weight;
//     std::string root;
// 
//     for(const auto &vec: input)
//     {
//         //find the size
//         str_weight = vec[1].substr(1,vec.size()-2);
//         std::istringstream ss (str_weight);
//         ss >> weight;
// 
//         sizes[vec[0]] = weight;
// 
//         //build the tree
//         for(size_t index=3; index < vec.size(); index++)
//         {
//             //add the current index to the tree
//             nodes[vec[0]].push_back(vec[index]);
// 
//             //find the root node
//             reverse_map[vec[index]] = vec[0];
//             while(reverse_map[root] != "")
//             {
//                 root = reverse_map[root];
//             }
//         }
//     }
// 
//     auto sum_children = [nodes, sizes, &sum_children](std::string current_node) {
//         const auto &children = nodes[current_node];
//         if(children.size() == 0)
//         {
//             return make_tuple(sizes[current_node], false);
//         }
//         //size_2 is only used if there's a conflict
//         std::tuple<long, bool> ans = sum_children(children[0]);
//         if(std::get<1>(ans))
//         {
//             return ans;
//         }
//         long size_1 = std::get<0>(ans);
//         long size_2;
//         size_t index=1;
//         do {
//             ans = sum_children(children[index]);
//             if(std::get<1>(ans)) {
//                 return ans;
//             }
//             size_2 = std::get<0>(ans);
//             index++;
//         } while (size_1 == size_2 && index < children.size());
//         if(size_1 == size_2)
//         {
//             return make_tuple(size_1 * children.size() + sizes[current_node], false);
//         }
//         if(index != 1)
//         {
//             return size_1;
//         }
//     }
// }
