#include <iostream> 
#include<vector>
using namespace std;

/// Longest Increasing Subsequence
// Kompleksitas Waktu O(n^2)

int LIS(vector<int> vec)
{
	int maxindex = 0; // menunjukkan posisi dari lis
	
	// first pair menunjukkan panjang lis untuk angka tersebut. second pair menunjukkan angka sebelumnya yang membuat lis.
	vector<pair<int , int>> lis(vec.size(), make_pair(1,0));
	
	int temp_maxindex = maxindex;
	for(int i=1; i<vec.size(); i++){
		if(vec.at(maxindex) < vec.at(i)){	// jika angka saat ini lebih besar dari angka lis sebelumnya, angka saat ini menjadi angka lis baru 
			lis.at(i).first = lis.at(maxindex).first + 1; 
			lis.at(i).second = maxindex; 
			maxindex = i;
			continue;
		} 
		
		for(int k=0; k<i; k++){ // temukan lis sebelumnya yang lebih kecil dari angka saat ini
			if(vec.at(i) > vec.at(k) && lis.at(i).first <= (lis.at(k).first+1)){
				lis.at(i).first = lis.at(k).first+1;
				lis.at(i).second = k;
			}
			if(lis.at(maxindex).first < lis.at(k).first ) maxindex = k;
		}
		
	}
	
	return lis.at(maxindex).first ;
}

int main(int argc, char *argv[]){
	vector<int> vec =   {4, 1, 13, 7, 0, 2, 8, 11, 3};    

	cout<<LIS(vec)<<'\n';
	
	return 0;
}
