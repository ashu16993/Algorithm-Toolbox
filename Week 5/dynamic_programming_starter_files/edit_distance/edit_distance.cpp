#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
int edit_distance(const string &str1, const string &str2) {
	//write your code here
	int edit_distance;
	std::vector<std::vector<long long>> distance;
	distance.resize((str1.length()+1), std::vector<long long>((str2.length()+1), 0));  
	
	const char *arr_cstr1 = str1.c_str();
	const char *arr_cstr2 = str2.c_str();
	
    for(long long i =0;i<=str1.length();i++){
        distance[i][0] = i;
    }
    
    for(long long i =0;i<=str2.length();i++){
        distance[0][i] = i;
    }
    
	for(long long i =1;i<=str1.length();i++){
		for(long long j=1;j<=str2.length();j++){
			int insertion = distance[i][j-1]+1;
			int deletion = distance[i-1][j]+1;
			int mismatch = distance[i-1][j-1]+1;
			int match = distance[i-1][j-1];
            //std::cout<<arr_cstr1[i-1]<<" "<<arr_cstr2[j-1]<<'\n';
			if(arr_cstr1[i-1]==arr_cstr2[j-1])
				distance[i][j]=std::min(insertion,std::min(deletion,match));
			else
				distance[i][j]=std::min(insertion,std::min(deletion,mismatch));
		}  
	}
    
    /*for(long long i =0;i<=str1.length();i++){
		for(long long j=0;j<=str2.length();j++){
            std::cout<<distance[i][j]<<" ";
        }
        std::cout<<'\n';
    }*/
  edit_distance = distance[str1.length()][str2.length()];
  return edit_distance;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
