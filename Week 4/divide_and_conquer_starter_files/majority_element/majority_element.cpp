#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

std::pair<int,int> get_majority_element_recur(vector<int> &a, int left, int right){
    if(left == right){
//        std::cout<<"Last Node: "<<a[left]<<"\n\n";
        return std::make_pair(a[left], 1);
    }
    int mid = (left + right) / 2;
//    std::cout<<"Left, Right, Mid: "<<left<<" "<<right<<" "<<mid<<"\n\n";
    std::pair<int,int> firstResult,secondResult;
    std::pair<int,int> firstHalf = get_majority_element_recur(a, left, mid);
    std::pair<int,int> secondHalf = get_majority_element_recur(a, mid + 1 , right);
//    std::cout<<"firstHalf: "<<firstHalf.first<<" "<<firstHalf.second<<"\n\n";
//    std::cout<<"secondHalf: "<<secondHalf.first<<" "<<secondHalf.second<<"\n\n";
//    std::cout<<"Left, Right, Mid: "<<left<<" "<<right<<" "<<mid<<"\n\n";
    if(firstHalf.second > 0){
        int fcount = 0;
        for(int i =  mid+1; i <= right; ++i){
            if(firstHalf.first == a[i])
                fcount += 1;
        }
        if(fcount == 0)
            firstResult = std::make_pair(-1 , 0);
        else
            firstResult = std::make_pair(firstHalf.first , (firstHalf.second + fcount));
    }
    else
        firstResult = std::make_pair(-1 , 0);
    if(secondHalf.second > 0){
        int scount = 0;
        for(int j = left; j <= mid; ++j){
            if(secondHalf.first == a[j])
                scount += 1;
        }
        if(scount == 0)
            secondResult = std::make_pair(-1,0);
        else
            secondResult = std::make_pair(secondHalf.first , (secondHalf.second + scount));
    }
    else
        secondResult = std::make_pair(-1 , 0);
//    std::cout<<"FirstResult: "<<firstResult.first<<" "<<firstResult.second<<"\n\n";
//    std::cout<<"SecondResult: "<<secondResult.first<<" "<<secondResult.second<<"\n\n";
    if(firstResult.second == 0 && secondResult.second == 0)
        return std::make_pair(-1 , 0);
    else{
        if(firstResult.second > 0 && secondResult.second == 0)
            return firstResult;
        if(secondResult.second > 0 && firstResult.second == 0)
            return secondResult;
        if(firstResult.second > 0 && secondResult.second > 0){
            int majority = (right - left) / 2;
            if(firstResult.second > majority && secondResult.second < majority)
                return firstResult;
            if(secondResult.second > majority && firstResult.second < majority)
                return secondResult;
            if(secondResult.second > majority && firstResult.second > majority)
                return firstResult;
            else
                return std::make_pair(-1,0);
        }
    }
}

int get_majority_element(vector<int> &a, int left, int right) {
  std::pair<int,int> finalResult;
  finalResult = get_majority_element_recur(a, left, right);
//  std::cout<<"Final Result: "<<finalResult.first<<" "<<finalResult.second<<"\n\n";
    if(finalResult.second > a.size()/2)
        return 1;
    else
        return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
