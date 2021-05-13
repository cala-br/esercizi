#include <iostream>
#include "chain.hpp"

int main() {
    
    Chain chain;

    chain.add(0, Material::IRON);
    chain.add(1, Material::IRON);
    chain.add(2, Material::IRON);
    chain.add(3, Material::COPPER);
    chain.add(3, Material::IRON);
    chain.add(3, Material::COPPER);

    std::cout << chain.toString();
}