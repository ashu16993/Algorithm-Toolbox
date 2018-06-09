#include <iostream>
#include <vector>

using std::vector;

int lcs( vector<int> &X, vector<int> &Y,vector<int> &Z, int m, int n ,int o)
{
	//int L[m+1][n+1];
	//vector<std::vector<std::vector<long long>>> LCS;
	
	vector<vector<vector<long long> > > LCS (m+1,vector<vector<long long> >(n+1,vector <long long>(o+1,0)));
	
	//LCS.resize(m+1, std::vector<long long>(n+1, 0));  
	/*
	for(int i=0;i<=m;i++)
		LCS[i][0][0]=0;
	for(int i=0;i<=n;i++)
		LCS[0][i][0]=0;
	for(int k =0;k<=o;k++)
		LCS[0][0][k]=0;
	*/
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=n; j++)
		{
			for(int k=1;k<=o;k++){
				if (X[i-1] == Y[j-1] && Y[j-1]==Z[k-1])
					LCS[i][j][k] = LCS[i-1][j-1][k-1] + 1;
                else
                    LCS[i][j][k] = std::max(LCS[i-1][j][k],std::max(LCS[i][j-1][k],LCS[i][j][k-1]));
					/*if(X[i-1] == Y[j-1])
					LCS[i][j][k] = LCS[i-1][j-1][k] + 1;
                else
                    LCS[i][j][k] = std::max(LCS[i-1][j][k],LCS[i][j-1][k]);
                
                if(X[i-1] == Z[k-1])
					LCS[i][j][k] = LCS[i-1][j][k-1] + 1;
                else
                    LCS[i][j][k] = std::max(LCS[i-1][j][k],LCS[i][j][k-1]);
                
				if(Y[j-1] == Z[k-1])
					LCS[i][j][k] = LCS[i][j-1][k-1] + 1;
				else
                    LCS[i][j][k] = std::max(LCS[i][j-1][k],LCS[i][j][k-1]);
                */
                
			}
			
		}
	}
	return LCS[m][n][o];
}



int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  
	int lcs1 = lcs(a,b,c,a.size(),b.size(),c.size());
	//int lcs2 = lcs(a,c,a.size(),c.size());
	//int lcs3 = lcs(c,b,c.size(),b.size());
  
  return lcs1;
  //return std::min(std::min(lcs1, lcs2), lcs3);
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
