#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main(){
	map<int, int> pelda;
		pelda.insert(pair<int, int>(1,40));
		pelda.insert(pair<int, int>(2,30));
		pelda.insert(pair<int, int>(3,60));
		pelda.insert(pair<int, int>(4,20));
		pelda.insert(pair<int, int>(5,50));
		pelda.insert(pair<int, int>(6,70));
		pelda.insert(pair<int, int>(7,10));

	map <int,int> :: iterator itr;
	cout<<"\nPelda map: \n";
	cout<<"\tKulcs\tElem\n";
	for(itr=pelda.begin(); itr != pelda.end(); ++itr)
		cout<<'\t' <<itr->first<<'\t'<<itr->second<<'\n';
	cout<<endl;
}