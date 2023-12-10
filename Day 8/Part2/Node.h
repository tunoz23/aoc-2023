#pragma once
#include <chrono>
#include <iostream>
#include <string>
using std::string;
struct Node
{
	
	string val;
	Node*  left;
	Node*  right;

	Node(string _val): val(_val), left(nullptr), right(nullptr) {};
	Node(string _val,Node* _left, Node* _right): val(_val), left(_left), right(_right) {};
};



struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<double> duration = (std::chrono::duration<double>)(0);
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        duration *= 1000.f;
        std::cout << "it took -> " << duration.count() << "ms\n";
    }
};