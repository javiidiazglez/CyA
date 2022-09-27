#include <cstdio>
#include <vector>
#include <random>
#include <iostream>

#include "sorted_vector_t.hpp"

#define LIMIT 999
#define SIZE   80

using namespace std;

int main(void)
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(-LIMIT, LIMIT);

    CyA::sorted_vector_t v;

    cout << "\nNumeros aleatorios\n"<<endl;

    for(int i = 0; i < SIZE; i++)
        v.push_back(distribution(generator));

    cout << v << endl;

    cout << "\nMerge sort menor a mayor\n"<<endl;

    v.merge_sort();
    cout << v << endl;

    cout << "\nMerge interativo\n"<<endl;

    v.merge_sort_ite();

    cout << v << endl;

    cout << "\n-----------------------------------------------------"<<endl;


	return 0;
}
