#ifndef CHAIN_HPP_
#define CHAIN_HPP_

#include <vector>
#include <string_view>
#include <algorithm>

enum class Material : char
{
    IRON = 'I',
    COPPER = 'C',
};


class Chain 
{
public:
    Chain() : _chain({}) {}

    void add(std::size_t index, Material material) 
    {
        const auto ring = _chain.begin() + index;
        _chain.insert(ring, material);
    }

    void remove(std::size_t index) 
    {
        const auto ring = _chain.begin() + index;
        _chain.erase(ring);
    }

    std::string_view toString() {
        return (char*)_chain.data();
    }


private:
    std::vector<Material> _chain;
};


#endif // !CHAIN_HPP_