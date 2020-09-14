#include<iostream>
#include <vector>
#include "WordSearch.hpp"

int main() {
	std::vector<std::vector<char>> vec{
		{'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A'}
	};

	Solution ws;

    std::cout << ws.exist(vec, "AAAAAAAAAAAAAAAA") << std::endl;
    std::cout << ws.exist(vec, "SEE") << std::endl;
    std::cout << ws.exist(vec, "ABCB") << std::endl;

	return 0;
}