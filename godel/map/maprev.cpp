#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>
using namespace std;

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &pelda)
{
    std::multimap<B,A> dst;
    std::transform(pelda.begin(), pelda.end(), std::inserter(dst, dst.begin()), flip_pair<A,B>);
    return dst;
}

int main(void)
{
    std::map<int, double> pelda;

    pelda.insert(pair<int, double>(1,40));
	pelda.insert(pair<int, double>(2,30));
	pelda.insert(pair<int, double>(3,60));
	pelda.insert(pair<int, double>(4,20));
	pelda.insert(pair<int, double>(5,50));
	pelda.insert(pair<int, double>(6,70));
	pelda.insert(pair<int, double>(7,10)); 

    std::multimap<double, int> dst = flip_map(pelda);

    map <double,int> :: iterator itr;
	cout<<"\nPelda map: \n";
	cout<<"\tElem\tKulcs\n";
	for(itr=dst.begin(); itr != dst.end(); ++itr)
		cout<<'\t' <<itr->first<<'\t'<<itr->second<<'\n';
	
	cout<<endl;
}