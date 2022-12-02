#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
    bool haveVectorsSameValues(std::vector<int> v1,std::vector<int> v2)
    {
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());
        return v1 == v2;
    }

    bool isResultSubmitted(const std::vector<std::vector<int>> &results, const std::vector<int> &newResult)
    {
        for(auto result : results)
        {
            if(haveVectorsSameValues(result, newResult)) return true;
        }
        return false;
    }
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result{};
        for(size_t i = 0; i < nums.size(); i++)
        {
            for(size_t j = i+1; j < nums.size(); j++)
            {
                if(i==j) break;
                for(size_t k = j+1; k < nums.size(); k++)
                {
                    if(i == k || j == k) continue;
                    if((nums.at(i) + nums.at(j) + nums.at(k)) == 0)
                    {
                        std::vector<int> foundVector{nums.at(i), nums.at(j), nums.at(k)};
                        if(!isResultSubmitted(result, foundVector))
                        {
                            result.push_back(std::move(foundVector));
                        }
                        break;
                    }
                }
            }
        }
        return result;
    }
};

bool compareVectors(std::vector<int> v1, std::vector<int> v2)
{
    if(v1.size() != v2.size()) {return false;}
    return std::equal(v1.begin(), v1.end(), v2.begin());
}

bool compareVectorSets( std::vector<std::vector<int>> set1, std::vector<std::vector<int>> set2)
{
    if(set1.size() != set2.size()) {return false;}

    if(!std::any_of(set1.begin(), set1.end(),
    [set2](std::vector<int> vecToCompare)
    {
        for(auto vecToCompareTo : set2)
        {
            if(!compareVectors(vecToCompare, vecToCompareTo)) { return false; }
        }
        return true;
    }
    ))
    {
        return false;
    }
    
    return true;
}

int main()
{
    Solution s;
    std::vector<int> v1{-1,0,1,2,-1,-4};
    auto result = s.threeSum(v1);
    for(auto vec : result)
    {
        assert(compareVectors);
    }
    return 0;
}