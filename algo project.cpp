#include<fstream>
#include<bits/stdc++.h>
using namespace std;
class Longest_common_subsequence{
	private:
		string str1;
		string str2;
		int length1;
		int length2;
	public:
		Longest_common_subsequence(string str1,string str2)
		{
			this->str1=str1;
			this->str2=str2;
		}
		LCS()
		{
			length1=str1.length();
			length2=str2.length();
			char array1[length1 + 1];
			char array2[length2 + 1];
			int lcs[length1 + 1][length2 + 1];
			int i,j;
			strcpy(array1,str1.c_str());
			strcpy(array2,str2.c_str());
			for( i=0;i<=length1 ;i++)
			{
				for(j=0; j<=length2 ;j++)
				{
					if(i==0 || j==0)
					{
						lcs[i][j]=0;
					}
					else if(array1[i-1]==array2[j-1])
					{
						lcs[i][j]= 1 + lcs[i-1][j-1];
					}
					else
					{
						lcs[i][j]= max(lcs[i-1][j],lcs[i][j-1]);
					}
				}
			}
			int l=lcs[length1][length2];
			char lcsStr[l+1];
			lcsStr[l+1]='\0';
			i=length1;
			j=length2;
			while(i> 0 && j>0)
			{
				if(array1[i-1]==array2[j -1] )
				{
					lcsStr[l-1]=array1[i-1];
					i--;
					j--;
					l--;
				}
				else if(lcs[i-1][j] > lcs[i][j-1])
				{
					i--;
				}
				else
				{
					j--;
				}
			}
			cout<<"length of LCS "<<lcs[length1][length2]<<"\n";
			cout<<"longest common subsequence = "<<lcsStr;

		}
		int max(int a,int b )
		{
			if(a<b)
			{
				return b;
			}
			else
			{
				return a;
			}
		}
};
class shortest_common_supersequence{
	private:
		string X;
		string Y;
		int l1,l2;
		public:
			shortest_common_supersequence(string str1,string str2)
			{
				this->X=str1;
				this->Y=str2;
			}
		string printShortestSuperSeq() 
		{ 
			int m = X.length(); 
			int n = Y.length(); 


			int dp[m + 1][n + 1]; 

 
			for (int i = 0; i <= m; i++) 
			{ 
			for (int j = 0; j <= n; j++) 
			{ 
 
			if(i == 0) 
				dp[i][j] = j; 
			else if(j == 0) 
				dp[i][j] = i; 
			else if(X[i - 1] == Y[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1]; 
			else
				dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]); 
			} 
		} 
			int index = dp[m][n]; 

			string str; 

			int i = m, j = n; 
			while (i > 0 && j > 0) 
			{ 
		
			if (X[i - 1] == Y[j - 1]) 
			{ 
			str.push_back(X[i - 1]); 
 
			i--, j--, index--; 
		} 
 
		else if (dp[i - 1][j] > dp[i][j - 1]) 
		{ 

			str.push_back(Y[j - 1]); 

			j--, index--; 
		} 
		else
		{ 
		
			str.push_back(X[i - 1]); 

			i--, index--; 
		} 
	} 

	while (i > 0) 
	{ 
		str.push_back(X[i - 1]); 
		i--, index--; 
	} 

	while (j > 0) 
	{ 
		str.push_back(Y[j - 1]); 
		j--, index--; 
	} 

	reverse(str.begin(), str.end()); 
	return str; 
} 
};
class Edit_Distance{
	private:
	string string1;
	string string2;
	
	public:
		Edit_Distance(string string1,string string2)
		{
			this->string1=string1;
			this->string2=string2;
		}
		ED()
		{
		int	l1=string1.length();
		int	l2=string2.length();
		cout<<"edit distance =  "<<editDist(string1,string2,l1,l2);
		}
int min(int x, int y, int z) { 
if(x<y && x<z)
{
	return x;
}
else if(y<x && y<z)
{
	return y;
}
else
{
	return z;
}
}
	int editDist(string str1, string str2, int m, int n)
{

	if (m == 0)
		return n;

	
	if (n == 0)
		return m;
		
	if (str1[m - 1] == str2[n - 1])
		return editDist(str1, str2, m - 1, n - 1);

	return 1
		+ min(editDist(str1, str2, m, n - 1),editDist(str1, str2, m - 1, n),editDist(str1, str2, m - 1,	n - 1) 
			);
}
};
class Longest_increasing_subsequence{
		private:
			string str;
		public:
		Longest_increasing_subsequence(string str)
		{
			this->str=str;
		}
		func()
		{
			int array[30]={0};
			int i,j=0;
			for(i=0;str[i]!='\0';i++)
			{
				if(str[i]==' ')
				{
					j++;
				}
				else
				{
					array[j]=array[j]*10 + (str[i]-48);
				}
			}
			cout<<"max "<< LIS(array,30);
		}
	int	LIS(int array[],int size)
		{
			int max=1;
			_LIS(array,size,&max);
			return max;
		}
	int	_LIS(int array[],int size,int *max_ref)
		{
			if(size==1)
			{
				return 1;
			}
			int res,max_ending_here=1;
			for(int i=1;i<size;i++)
			{
				res=_LIS(array,i,max_ref);
				if(array[i-1] < array[size-1] && res+1 > max_ending_here)
				{
					max_ending_here=res+1;
				}
			}
			if(*max_ref < max_ending_here)
			{
				*max_ref=max_ending_here;
			}
			return max_ending_here;
		}
};
class matrix_chain_multiplication{
	private:
		string str;
	public:
		matrix_chain_multiplication(string str)
		{
			this->str=str;
		}
		MCM()
		{
			int array[20]={0};
			int i,j=0;
			for(i=0;str[i]!='\0';i++)
			{
				if(str[i]==' ')
				{
					j++;
				}
				else
				{
					array[j]=array[j]*10 + (str[i]-48);
				}
			}
			int mini;
			mini=MatrixChainOrder(array,1,19);
			cout<<"minimum numbers oof multiplication = "<<mini<<"\n";
			
		}
		int MatrixChainOrder(int p[], int i, int j) 
       { 
			if (i == j) 
			{
		
				//cout<<i<<" ";
				return 0; 
			}
			int k; 
			int min = INT_MAX;
			int count; 

 
			for (k = i; k < j; k++) 
			{ 
				count = MatrixChainOrder(p, i, k) 
				+ MatrixChainOrder(p, k + 1, j) 
				+ p[i - 1] * p[k] * p[j]; 

				if (count < min) 
				min = count; 
			} 


			return min; 
		} 
};
class word_break{
	private:
	string str1;
	string str2;
	public:
		word_break(string str1,string str2)
		{
			this->str1=str1;
			this->str2=str2;
		}
		spilt()
		{
			int length=str1.length();
			int count=0;
			string word="";
			for(auto x : str1)
			{
				if(x == ' ')
				{
					count++;
				}
			}
			string dictionary[count+1];
			int i=0;
			for (auto x : str1) 
			{
				if (x == ' ')
				{
					dictionary[i]=word;
					i++;
					word="";
				}
				else 
				{
					word = word + x;
				}
			}
			dictionary[i]=word;
			int s = sizeof(dictionary)/sizeof(dictionary[0]);
     		for(int i=0;i<s;i++)
	 		{
	 		 	cout<<dictionary[i]<<"\n";
	  		}
			bool res;
			wordBreak(dictionary,str2)? cout <<"Yes Present \n": cout << "Not Present\n";
		}
		
	bool dictionaryContains(string dictionary[],string str2) 
      { 
      int size = sizeof(dictionary)/sizeof(dictionary[0]); 
      for (int i = 0; i < size; i++) 
        if (dictionary[i].compare(str2) == 0) 
           return true; 
    		return false; 
	  } 
	  bool wordBreak(string dictionary[],string str2) 
	{ 
    int size = str2.size(); 
    if (size == 0)  return true; 

    for (int i=1; i<=size; i++) 
    { 
        if (dictionaryContains( dictionary,str2.substr(0, i) ) && wordBreak( dictionary,str2.substr(i, size-i) ) ) 
            return true; 
    }  
    return false; 
    } 
};
class rod_Cutting{
	private:
		int t[9][9];
	public:
		rod_cutting();
		
	int un_kp(int price[], int length[],  
                    int Max_len, int n) 
{ 
  
   
    if (n == 0 || Max_len == 0)  
    { 
        return 0; 
    } 
  
     
    if (length[n - 1] <= Max_len)  
    { 
        t[n][Max_len] 
            = max(price[n - 1] 
                      + un_kp(price, length, 
                           Max_len - length[n - 1], n), 
                  un_kp(price, length, Max_len, n - 1)); 
    } 
    else 
    { 
        t[n][Max_len] 
            = un_kp(price, length,  
                              Max_len, n - 1); 
    } 
    return t[n][Max_len]; 
} 
	int max(int a,int b )
		{
			if(a<b)
			{
				return b;
			}
			else
			{
				return a;
			}
		}
};
class coinchange{
	private:
	
	
	public:
		void count( int S[], int m, int n ) 
{ 
    int i, j, x, y; 
    int table[n + 1][m]; 
    
    for (i = 0; i < m; i++) 
    {
    	 table[0][i] = 1;
	} 
  
 
    for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        {  
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
            y = (j >= 1) ? table[i][j - 1] : 0;  
            table[i][j] = x + y; 
        } 
    } 
    cout<< table[n][m - 1]<<"\n"; 
} 
};
class knapsack_problem{
	private:
		int wt[10];
		int val[10];
		int n;
		int W;
		public:
			knapsack_problem (int wt[],int val[],int W)
			{
				this->n=10;
				this->W=W;
				for(int i=0;i<n;i++)
				{
					this->wt[i]=wt[i];
					this->val[i]=val[i];
				}
			}
			void knapSack() 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
    for (i = 0; i <= n; i++)  
    { 
        for (w = 0; w <= W; w++)  
        { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
            {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],K[i - 1][w]); 
            }
			else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  		cout<<"The maximum total value can be "<<K[n][W]<<"\n"; 
} 
		int max(int a,int b )
		{
			if(a<b)
			{
				return b;
			}
			else
			{
				return a;
			}
		}
			
};
class partition_problem{
	private:
	public:
			partition_problem()
	{
		
	}
		bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
    	cout << "Can not be divided into"
             << " two subsets of equal sum";
    	return false;
	}
 
    bool part[sum / 2 + 1][n + 1];
 

    for (i = 0; i <= n; i++)
        part[0][i] = true;
 
    for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;
 
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
    }
    if(part[sum / 2][n]==true)
    {
    	cout << "Can be divided into two subsets of equal "
                "sum\n";
	}
	else
	{
		cout << "Can not be divided into"
             << " two subsets of equal sum";
	}
 }
};

int main()
{
	int select;
	int select_case;
	int line_no;
	char choice;
	string str1;
	string str2;
	string str;
	int i,total_weight;
	fstream fin;
	ifstream myfile;
	choice='y';
	while(choice!='n' && (choice=='y'|| choice=='Y')) 
	{
	cout<< "select the algorithm number that you want to execute\n";
	cout<<"1. longest common subsequence\n";
	cout<<"2. shortest common supersequence\n";
	cout<<"3. Levenshtein Distance (edit-distance)\n";
	cout<<"4. Longest Increasing Subsequence\n";
	cout<<"5. Matrix Chain Multiplication (Order finding /paranthesization)\n";
	cout<<"6. 0-1-knapsack-problem\n";
	cout<<"7. Partition-problem\n";
	cout<<"8. Rod Cutting Problem\n";
	cout<<"9. Coin-change-making-problem\n";
	cout<<"10. Word Break Problem\n";
	cin>>select;
	switch(select)
	{
		case 1:
			cout<< "input file of the selected algorithm\n";
			myfile.open("input1.txt",ios::in);
			if(myfile.is_open())
			{
				while(!myfile.eof())
				{
					getline(myfile,str1);
					cout<<str1;
					cout<<"\n";
				}
			}
			myfile.close();
			cout<<"select the test case that you want to execute "<<"\n";
				cin>>select_case;
				myfile.open("input1.txt",ios::in);	
					for(line_no=1;line_no<=34;line_no++)
					{
						if(select_case==1 && line_no==2)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Longest_common_subsequence l1(str1,str2);
							l1.LCS();
							break;
						}
						else if(select_case==2 && line_no==5)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Longest_common_subsequence l1(str1,str2);
							l1.LCS();
							break;
						}
						else if(select_case==3 && line_no==8)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Longest_common_subsequence l1(str1,str2);
							l1.LCS();
							break;
						}
						else if(select_case==4 && line_no==11)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Longest_common_subsequence l1(str1,str2);
							l1.LCS();
							break;
						}
						else if(select_case==5 && line_no==14)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Longest_common_subsequence l1(str1,str2);
							l1.LCS();
							break;
						}
						else if(select_case==6 && line_no==17)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Longest_common_subsequence l1(str1,str2);
							l1.LCS();
							break;
						}
						else if(select_case==7 && line_no==20)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Longest_common_subsequence l1(str1,str2);
							l1.LCS();
							break;
						}
						else if(select_case==8 && line_no==23)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Longest_common_subsequence l1(str1,str2);
							l1.LCS();
							break;
						}
						else if(select_case==9 && line_no==26)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Longest_common_subsequence l1(str1,str2);
							l1.LCS();
							break;
						}
						else if(select_case==10 && line_no==29)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Longest_common_subsequence l1(str1,str2);
							l1.LCS();
							break;
						}
						getline(myfile,str1);
					}
				
				myfile.close();
			break;
		case 2:
			cout<< "input file of the selected algorithm\n";
			myfile.open("input1.txt",ios::in);
			if(myfile.is_open())
			{
				while(!myfile.eof())
				{
					getline(myfile,str1);
					cout<<str1;
					cout<<"\n";
				}
			
			}
			myfile.close();
			cout<<"select the test case that you want to execute "<<"\n";
				cin>>select_case;
				myfile.open("input1.txt",ios::in);	
					for(line_no=1;line_no<=34;line_no++)
					{
						if(select_case==1 && line_no==2)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							shortest_common_supersequence s1(str1,str2);
							string s;
							s=s1.printShortestSuperSeq();
							cout<<"shortest common supersequence is "<<s<<"\n";
							int length=s.length();
							cout<<"length of supersequence is "<<length<<"\n";
							break;
						}
						else if(select_case==2 && line_no==5)
						{
							getline(myfile,str1);
							getline(myfile,str2);
								shortest_common_supersequence s1(str1,str2);
							string s;
							s=s1.printShortestSuperSeq();
							cout<<"shortest common supersequence is "<<s<<"\n";
							int length=s.length();
							cout<<"length of supersequence is "<<length<<"\n";
							break;
						}
						else if(select_case==3 && line_no==8)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							shortest_common_supersequence s1(str1,str2);
							string s;
							s=s1.printShortestSuperSeq();
							cout<<"shortest common supersequence is "<<s<<"\n";
							int length=s.length();
							cout<<"length of supersequence is "<<length<<"\n";
							break;
						}
						else if(select_case==4 && line_no==11)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							shortest_common_supersequence s1(str1,str2);
							string s;
							s=s1.printShortestSuperSeq();
							cout<<"shortest common supersequence is "<<s<<"\n";
							int length=s.length();
							cout<<"length of supersequence is "<<length<<"\n";
							break;
						}
						else if(select_case==5 && line_no==14)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							shortest_common_supersequence s1(str1,str2);
							string s;
							s=s1.printShortestSuperSeq();
							cout<<"shortest common supersequence is "<<s<<"\n";
							int length=s.length();
							cout<<"length of supersequence is "<<length<<"\n";
							break;
						}
						else if(select_case==6 && line_no==17)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							shortest_common_supersequence s1(str1,str2);
							string s;
							s=s1.printShortestSuperSeq();
							cout<<"shortest common supersequence is "<<s<<"\n";
							int length=s.length();
							cout<<"length of supersequence is "<<length<<"\n";
							break;
						}
						else if(select_case==7 && line_no==20)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							shortest_common_supersequence s1(str1,str2);
							string s;
							s=s1.printShortestSuperSeq();
							cout<<"shortest common supersequence is "<<s<<"\n";
							int length=s.length();
							cout<<"length of supersequence is "<<length<<"\n";
							break;
						}
						else if(select_case==8 && line_no==23)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							shortest_common_supersequence s1(str1,str2);
							string s;
							s=s1.printShortestSuperSeq();
							cout<<"shortest common supersequence is "<<s<<"\n";
							int length=s.length();
							cout<<"length of supersequence is "<<length<<"\n";
							break;
						}
						else if(select_case==9 && line_no==26)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							shortest_common_supersequence s1(str1,str2);
							string s;
							s=s1.printShortestSuperSeq();
							cout<<"shortest common supersequence is "<<s<<"\n";
							int length=s.length();
							cout<<"length of supersequence is "<<length<<"\n";
							break;
						}
						else if(select_case==10 && line_no==29)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							shortest_common_supersequence s1(str1,str2);
							string s;
							s=s1.printShortestSuperSeq();
							cout<<"shortest common supersequence is "<<s<<"\n";
							int length=s.length();
							cout<<"length of supersequence is "<<length<<"\n";
							break;
						}
						getline(myfile,str1);
					}
				
				myfile.close();
			break;
		case 3:
			cout<< "input file of the selected algorithm\n";
			myfile.open("input5.txt",ios::in);
			if(myfile.is_open())
			{
				while(!myfile.eof())
				{
					getline(myfile,str1);
					cout<<str1;
					cout<<"\n";
				}
			
			}
			myfile.close();
			cout<<"select the test case that you want to execute "<<"\n";
				cin>>select_case;
				myfile.open("input5.txt",ios::in);	
					for(line_no=1;line_no<=34;line_no++)
					{
						if(select_case==1 && line_no==2)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Edit_Distance e1(str1,str2);
							e1.ED();
							break;
						}
						else if(select_case==2 && line_no==5)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Edit_Distance e1(str1,str2);
							e1.ED();
							break;
						}
						else if(select_case==3 && line_no==8)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Edit_Distance e1(str1,str2);
							e1.ED();
							break;
						}
						else if(select_case==4 && line_no==11)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Edit_Distance e1(str1,str2);
							e1.ED();
						}
						else if(select_case==5 && line_no==14)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Edit_Distance e1(str1,str2);
							e1.ED();
							break;
						}
						else if(select_case==6 && line_no==17)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Edit_Distance e1(str1,str2);
							e1.ED();
							break;
						}
						else if(select_case==7 && line_no==20)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Edit_Distance e1(str1,str2);
							e1.ED();
							break;
						}
						else if(select_case==8 && line_no==23)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Edit_Distance e1(str1,str2);
							e1.ED();
							break;
						}
						else if(select_case==9 && line_no==26)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Edit_Distance e1(str1,str2);
							e1.ED();
							break;
						}
						else if(select_case==10 && line_no==29)
						{
							getline(myfile,str1);
							getline(myfile,str2);
							Edit_Distance e1(str1,str2);
							e1.ED();
							break;
						}
						getline(myfile,str1);
					}
				
				myfile.close();
			break;
		case 4:
			cout<< "input file of the selected algorithm\n";
			myfile.open("input2.txt",ios::in);
			if(myfile.is_open())
			{
				while(!myfile.eof())
				{
					getline(myfile,str1);
					cout<<str1<<"\n";
				}
			}
			myfile.close();
			cout<<"select the test case that you want to execute \n";
			cin>>select_case;
			myfile.open("input2.txt",ios::in);
			for(line_no=1;line_no<=20;line_no++)
			{
				if(select_case==1 && line_no==2)
				{
					getline(myfile,str1);
					Longest_increasing_subsequence l1(str1);
					l1.func();
					break;
				}
				if(select_case==2 && line_no==4)
				{
					getline(myfile,str1);
					Longest_increasing_subsequence l1(str1);
					l1.func();
					break;
				}
				if(select_case==3 && line_no==6)
				{
					getline(myfile,str1);
					Longest_increasing_subsequence l1(str1);
					l1.func();
					break;
				}
				if(select_case==4 && line_no==8)
				{
				    getline(myfile,str1);
					Longest_increasing_subsequence l1(str1);
					l1.func();
					break;
				}
				if(select_case==5 && line_no==10)
				{
					getline(myfile,str1);
					Longest_increasing_subsequence l1(str1);
					l1.func();
					break;
				}
				if(select_case==6 && line_no==12)
				{
					getline(myfile,str1);
					Longest_increasing_subsequence l1(str1);
					l1.func();
					break;
				}
				if(select_case==7 && line_no==14)
				{
					getline(myfile,str1);
					Longest_increasing_subsequence l1(str1);
					l1.func();
					break;
				}
				if(select_case==8 && line_no==16)
				{
					getline(myfile,str1);
					Longest_increasing_subsequence l1(str1);
					l1.func();
					break;
				}
				if(select_case==9 && line_no==18)
				{
					getline(myfile,str1);
					Longest_increasing_subsequence l1(str1);
					l1.func();
					break;
				}
				if(select_case==10 && line_no==20)
				{
					getline(myfile,str1);
					Longest_increasing_subsequence l1(str1);
					l1.func();
					break;
				}
				getline(myfile,str1);
			}
			myfile.close();
		    break;
		case 5:
			cout<< "input file of the selected algorithm\n";
			myfile.open("input2.txt",ios::in);
			if(myfile.is_open())
			{
				while(!myfile.eof())
				{
					getline(myfile,str1);
					cout<<str1<<"\n";
				}
			}
			myfile.close();
			cout<<"select the test case that you want to execute \n";
			cin>>select_case;
			myfile.open("input2.txt",ios::in);
			for(line_no=1;line_no<=20;line_no++)
			{
				if(select_case==1 && line_no==2)
				{
					getline(myfile,str1);	
						matrix_chain_multiplication m1(str1);
						m1.MCM();
					
					break;
				}
				if(select_case==2 && line_no==4)
				{
					getline(myfile,str1);
					matrix_chain_multiplication m1(str1);
					m1.MCM();
					break;
				}
				if(select_case==3 && line_no==6)
				{
					getline(myfile,str1);
						matrix_chain_multiplication m1(str1);
						m1.MCM();
					break;
				}
				if(select_case==4 && line_no==8)
				{
				    getline(myfile,str1);
					matrix_chain_multiplication m1(str1);
					m1.MCM();
					break;
				}
				if(select_case==5 && line_no==10)
				{
					getline(myfile,str1);
					matrix_chain_multiplication m1(str1);
					m1.MCM();
					break;
				}
				if(select_case==6 && line_no==12)
				{
					getline(myfile,str1);
					matrix_chain_multiplication m1(str1);
					m1.MCM();
					break;
				}
				if(select_case==7 && line_no==14)
				{
					getline(myfile,str1);
					matrix_chain_multiplication m1(str1);
					m1.MCM();
					break;
				}
				if(select_case==8 && line_no==16)
				{
					getline(myfile,str1);
					matrix_chain_multiplication m1(str1);
					m1.MCM();
					break;
				}
				if(select_case==9 && line_no==18)
				{
					getline(myfile,str1);
					matrix_chain_multiplication m1(str1);
					m1.MCM();
					break;
				}
				if(select_case==10 && line_no==20)
				{
					getline(myfile,str1);
					matrix_chain_multiplication m1(str1);
					m1.MCM();
					break;
				}
				getline(myfile,str1);
			}
			myfile.close();
		    break;
		case 6:
			cout<< "input file of the selected algorithm\n";
			myfile.open("input3.txt",ios::in);
			if(myfile.is_open())
			{
				while(!myfile.eof())
				{
					getline(myfile,str);
					cout<<str<<"\n";
				}
			}
			myfile.close();
			cout<<"select the test case that you want to execute \n";
			cin>>select_case;
			int i,j;
			int n1,n2;
			myfile.open("input3.txt",ios::in);
			for(line_no=1;line_no <= 40;line_no++)
			{
			
				if(select_case==1 && line_no==2)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					myfile>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					knapsack_problem k1(weights,values,total_weight);
					k1.knapSack();
					break;
				}
				if(select_case==2 && line_no==6)
				{
						getline(myfile,str1);
					getline(myfile,str2);
					myfile>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					knapsack_problem k1(weights,values,total_weight);
					k1.knapSack();
					break;
				}
				if(select_case==3 && line_no==10)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					myfile>>total_weight;
					j=0;
					int weights[10]={0};
					int values[10]={0};
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					knapsack_problem k1(weights,values,total_weight);
					k1.knapSack();
					break;
				}
				if(select_case==4 && line_no==14)
				{
					getline(myfile,str1);
					j=0;
					getline(myfile,str2);
					myfile>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					knapsack_problem k1(weights,values,total_weight);
					k1.knapSack();
					break;
				}
				if(select_case==5 && line_no==18)
				{
						getline(myfile,str1);
					getline(myfile,str2);
					myfile>>total_weight;
					j=0;
					int weights[10]={0};
					int values[10]={0};
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					knapsack_problem k1(weights,values,total_weight);
					k1.knapSack();
					break;
				}
				if(select_case==6 && line_no==22)
				{
						getline(myfile,str1);
					getline(myfile,str2);
					myfile>>total_weight;
					int weights[10]={0};
					j=0;
					int values[10]={0};
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					knapsack_problem k1(weights,values,total_weight);
					k1.knapSack();
					break;
				}
				if(select_case==7 && line_no==26)
				{
						getline(myfile,str1);
					getline(myfile,str2);
					j=0;
					myfile>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					knapsack_problem k1(weights,values,total_weight);
					k1.knapSack();
					break;
				}
				if(select_case==8 && line_no==30)
				{
						getline(myfile,str1);
					getline(myfile,str2);
					myfile>>total_weight;
					j=0;
					int weights[10]={0};
					int values[10]={0};
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					knapsack_problem k1(weights,values,total_weight);
					k1.knapSack();
					break;
				}
				if(select_case==9 && line_no==34)
				{
						getline(myfile,str1);
					getline(myfile,str2);
					myfile>>total_weight;
					int weights[10]={0};
					j=0;
					int values[10]={0};
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					knapsack_problem k1(weights,values,total_weight);
					k1.knapSack();
					break;
				}
				if(select_case==10 && line_no==38)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					myfile>>total_weight;
					j=0;
					int weights[10]={0};
					int values[10]={0};
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					knapsack_problem k1(weights,values,total_weight);
					k1.knapSack();
					break;
				}
				getline(myfile,str);
		}
			myfile.close();
			break;
		case 7:
			cout<< "input file of the selected algorithm\n";
			myfile.open("input2.txt",ios::in);
			if(myfile.is_open())
			{
				while(!myfile.eof())
				{
					getline(myfile,str1);
					cout<<str1<<"\n";
				}
			}
			myfile.close();
			cout<<"select the test case that you want to execute \n";
			cin>>select_case;
			myfile.open("input2.txt",ios::in);
			for(line_no=1;line_no<=20;line_no++)
			{
				if(select_case==1 && line_no==2)
				{
					getline(myfile,str1);
					int array[10]={0};
					int i,j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
						for(i=0;i<6;i++)
					{
						cout<<array[i]<<" ";
					}
					cout<<"\n";
					partition_problem p1;
					cout<<p1.findPartiion(array,6);
					break;
				}
				if(select_case==2 && line_no==4)
				{
					getline(myfile,str1);
					int array[30]={0};
					int i,j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					partition_problem p1;
					cout<<p1.findPartiion(array,30);
					break;
				}
				if(select_case==3 && line_no==6)
				{
						getline(myfile,str1);
					int array[30]={0};
					int i,j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					partition_problem p1;
					cout<<p1.findPartiion(array,30);
					break;
				}
				if(select_case==4 && line_no==8)
				{
				    	getline(myfile,str1);
					int array[30]={0};
					int i,j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					partition_problem p1;
					cout<<p1.findPartiion(array,30);
					break;
				}
				if(select_case==5 && line_no==10)
				{
						getline(myfile,str1);
					int array[30]={0};
					int i,j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					partition_problem p1;
					cout<<p1.findPartiion(array,30);
					break;
				}
				if(select_case==6 && line_no==12)
				{
					getline(myfile,str1);
					int array[30]={0};
					int i,j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					partition_problem p1;
					cout<<p1.findPartiion(array,30);
					break;
				}
				if(select_case==7 && line_no==14)
				{
						getline(myfile,str1);
					int array[30]={0};
					int i,j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					partition_problem p1;
					cout<<p1.findPartiion(array,30);
					break;
				}
				if(select_case==8 && line_no==16)
				{
						getline(myfile,str1);
					int array[30]={0};
					int i,j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					partition_problem p1;
					cout<<p1.findPartiion(array,30);
					break;
				}
				if(select_case==9 && line_no==18)
				{
						getline(myfile,str1);
					int array[30]={0};
					int i,j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					partition_problem p1;
					cout<<p1.findPartiion(array,30);
					break;
				}
				if(select_case==10 && line_no==20)
				{
					getline(myfile,str1);
					int array[30]={0};
					int i,j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					partition_problem p1;
					cout<<p1.findPartiion(array,30);
					break;
				}
				getline(myfile,str1);
			}
			myfile.close();
			break;
		case 8:
			cout<< "input file of the selected algorithm\n";
			fin.open("input8.txt",ios::in);
			if(fin.is_open())
			{
				while(!fin.eof())
				{
					getline(fin,str1);
					cout<<str1<<"\n";
				}
			}
			fin.close();
			cout<<"select the test case that you want to execute "<<"\n";
			cin>>select_case;
			fin.open("input8.txt",ios::in);
			for(line_no=1;line_no <= 40;line_no++)
			{
				if(select_case==1 && line_no==2)
				{
						getline(fin,str1);
					getline(fin,str2);
					fin>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					rod_Cutting r1;
				cout << "Maxmum obtained value  is "<<r1.un_kp(values,weights,total_weight,total_weight)<<"\n";
					break;
				}
				if(select_case==2 && line_no==6)
				{
					getline(fin,str1);
					getline(fin,str2);
					fin>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					rod_Cutting r1;
				cout << "Maxmum obtained value  is "<<r1.un_kp(values,weights,total_weight,total_weight)<<"\n";
					break;
				}
				if(select_case==3 && line_no==10)
				{
						getline(fin,str1);
					getline(fin,str2);
					fin>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					rod_Cutting r1;
				cout << "Maxmum obtained value  is "<<r1.un_kp(values,weights,total_weight,total_weight)<<"\n";
					break;
				}
				if(select_case==4 && line_no==14)
				{
						getline(fin,str1);
					getline(fin,str2);
					fin>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					rod_Cutting r1;
				cout << "Maxmum obtained value  is "<<r1.un_kp(values,weights,total_weight,total_weight)<<"\n";
					break;
				}
				if(select_case==5 && line_no==18)
				{
						getline(fin,str1);
					getline(fin,str2);
					fin>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					rod_Cutting r1;
				cout << "Maxmum obtained value  is "<<r1.un_kp(values,weights,total_weight,total_weight)<<"\n";
					break;
				}
				if(select_case==6 && line_no==22)
				{
					getline(fin,str1);
					getline(fin,str2);
					fin>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					rod_Cutting r1;
				cout << "Maxmum obtained value  is "<<r1.un_kp(values,weights,total_weight,total_weight)<<"\n";
					break;
				}
				if(select_case==7 && line_no==26)
				{
						getline(fin,str1);
					getline(fin,str2);
					fin>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					rod_Cutting r1;
				cout << "Maxmum obtained value  is "<<r1.un_kp(values,weights,total_weight,total_weight)<<"\n";
					break;
				}
				if(select_case==8 && line_no==30)
				{
					getline(fin,str1);
					getline(fin,str2);
					fin>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					rod_Cutting r1;
				cout << "Maxmum obtained value  is "<<r1.un_kp(values,weights,total_weight,total_weight)<<"\n";
					break;
				}
				if(select_case==9 && line_no==34)
				{
						getline(fin,str1);
					getline(fin,str2);
					fin>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					rod_Cutting r1;
				cout << "Maxmum obtained value  is "<<r1.un_kp(values,weights,total_weight,total_weight)<<"\n";
					break;
				}
				if(select_case==10 && line_no==38)
				{
						getline(fin,str1);
					getline(fin,str2);
					fin>>total_weight;
					int weights[10]={0};
					int values[10]={0};
					j=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
						}
						else
						{
							weights[j]=weights[j]*10 + (str1[i]-48);
						}
					}
					j=0;
					for(i=0;str2[i]!='\0';i++)
					{
						if(str2[i]==' ')
						{
							j++;
						}
						else
						{
							values[j]=values[j]*10 + (str2[i]-48);
						}
					}	
					n1=sizeof(weights)/sizeof(int);
					n2=sizeof(values)/sizeof(int);
					for(i=0;i<n1;i++)
					{
						cout<<weights[i]<<" ";
					}
					cout<<"\n";
						for(i=0;i<n2;i++)
					{
						cout<<values[i]<<" ";
					}
					cout<<"\n";
					cout<<total_weight<<"\n";
					rod_Cutting r1;
				cout << "Maxmum obtained value  is "<<r1.un_kp(values,weights,total_weight,total_weight)<<"\n";
					break;
				}
				getline(fin,str);
			}
			fin.close();
			fflush(stdin);
			fflush(stdin);
			break;
		case 9:
			cout<< "input file of the selected algorithm\n";
			myfile.open("input6.txt",ios::in);
			if(myfile.is_open())
			{
				while(!myfile.eof())
				{
					getline(myfile,str1);
					cout<<str1<<"\n";
				}
			}
			myfile.close();
			cout<<"select the test case that you want to execute \n";
			cin>>select_case;
			int N;
			myfile.open("input6.txt",ios::in);
			for(line_no=1;line_no<=20;line_no++)
			{
				if(select_case==1 && line_no==2)
				{
						getline(myfile,str1);
					myfile>>N;
					int array[30]={0};
					int i,j=0,n1=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
							n1++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					n1++;
					for(i=0;i<n1;i++)
					{
						cout<<array[i]<<" ";
					}
					cout<<"\n";
					coinchange c1;
					c1.count(array,n1,N);
					break;
				}
				if(select_case==2 && line_no==5)
				{
						getline(myfile,str1);
					myfile>>N;
					int array[30]={0};
					int i,j=0,n1=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
							n1++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					n1++;
					for(i=0;i<n1;i++)
					{
						cout<<array[i]<<" ";
					}
					cout<<"\n";
					coinchange c1;
					c1.count(array,n1,N);
					break;
				}
				if(select_case==3 && line_no==8)
				{
				getline(myfile,str1);
					myfile>>N;
					int array[30]={0};
					int i,j=0,n1=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
							n1++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					n1++;
					for(i=0;i<n1;i++)
					{
						cout<<array[i]<<" ";
					}
					cout<<"\n";
					coinchange c1;
					c1.count(array,n1,N);
					break;
				}
				if(select_case==4 && line_no==11)
				{
				    	getline(myfile,str1);
					myfile>>N;
					int array[30]={0};
					int i,j=0,n1=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
							n1++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					n1++;
					for(i=0;i<n1;i++)
					{
						cout<<array[i]<<" ";
					}
					cout<<"\n";
					coinchange c1;
					c1.count(array,n1,N);
					break;
				}
				if(select_case==5 && line_no==14)
				{
					getline(myfile,str1);
					myfile>>N;
					int array[30]={0};
					int i,j=0,n1=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
							n1++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					n1++;
					for(i=0;i<n1;i++)
					{
						cout<<array[i]<<" ";
					}
					cout<<"\n";
					coinchange c1;
					c1.count(array,n1,N);
					break;
				}
				if(select_case==6 && line_no==17)
				{
					getline(myfile,str1);
					myfile>>N;
					int array[30]={0};
					int i,j=0,n1=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
							n1++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					n1++;
					for(i=0;i<n1;i++)
					{
						cout<<array[i]<<" ";
					}
					cout<<"\n";
					coinchange c1;
					c1.count(array,n1,N);
					break;
				}
				if(select_case==8 && line_no==23)
				{
					getline(myfile,str1);
					myfile>>N;
					int array[30]={0};
					int i,j=0,n1=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
							n1++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					n1++;
					for(i=0;i<n1;i++)
					{
						cout<<array[i]<<" ";
					}
					cout<<"\n";
					coinchange c1;
					c1.count(array,n1,N);
					break;
				}
				if(select_case==9 && line_no==26)
				{
						getline(myfile,str1);
					myfile>>N;
					int array[30]={0};
					int i,j=0,n1=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
							n1++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					n1++;
					for(i=0;i<n1;i++)
					{
						cout<<array[i]<<" ";
					}
					cout<<"\n";
					coinchange c1;
					c1.count(array,n1,N);
					break;
				}
				if(select_case==10 && line_no==29)
				{
						getline(myfile,str1);
					myfile>>N;
					int array[30]={0};
					int i,j=0,n1=0;
					for(i=0;str1[i]!='\0';i++)
					{
						if(str1[i]==' ')
						{
							j++;
							n1++;
						}
						else
						{
							array[j]=array[j]*10 + (str1[i]-48);
						}
					}
					n1++;
					for(i=0;i<n1;i++)
					{
						cout<<array[i]<<" ";
					}
					cout<<"\n";
					coinchange c1;
					c1.count(array,n1,N);
					break;
				}
				getline(myfile,str1);
			}
			myfile.close();
			break;
		case 10:
			cout<< "input file of the selected algorithm\n";
			myfile.open("input4.txt",ios::in);
			if(myfile.is_open())
			{
				while(!myfile.eof())
				{
					getline(myfile,str1);
					cout<<str1<<"\n";
				}
			}
			myfile.close();
			cout<<"select the test case that you want to execute "<<"\n";
			cin>>select_case;
			myfile.open("input4.txt",ios::in);
			for(line_no=1;line_no<=30;line_no++)
			{
				if(select_case==1 && line_no==2)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					word_break b1(str1,str2);
					b1.spilt();
					break;
				}
				if(select_case==2 && line_no==5)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					word_break b1(str1,str2);
					b1.spilt();
					break;
				}
				if(select_case==3 && line_no==8)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					word_break b1(str1,str2);
					b1.spilt();
					break;
				}
				if(select_case==4 && line_no==11)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					word_break b1(str1,str2);
					b1.spilt();
					break;
				}
				if(select_case==5 && line_no==14)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					word_break b1(str1,str2);
					b1.spilt();
					break;
				}
				if(select_case==6 && line_no==17)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					word_break b1(str1,str2);
					b1.spilt();
					break;
				}
				if(select_case==7 && line_no==20)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					word_break b1(str1,str2);
					b1.spilt();
					break;
				}
				if(select_case==8 && line_no==23)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					word_break b1(str1,str2);
					b1.spilt();
					break;
				}
				if(select_case==9 && line_no==26)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					word_break b1(str1,str2);
					b1.spilt();
					break;
				}
				if(select_case==10 && line_no==29)
				{
					getline(myfile,str1);
					getline(myfile,str2);
					word_break b1(str1,str2);
					b1.spilt();
					break;
				}
				getline(myfile,str);
			}
			myfile.close();
			break;
	}
	cout<<"\n"<<"Do you want to run more algorithms ? if YES press y if NO press n \n";
	cin>>choice;
	if(choice=='n')
	{
		cout<<"finished.........!"<<"\n";
	}
}
}
