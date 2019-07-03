#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) x.begin(), x.end()
#define f(i,s,n) for(int i=s;i<n;i++)
#define fe(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i>n;i--)
#define fre(i,s,n) for(int i=s;i>=n;i--)
const int MOD = 998244353;
template <typename T,typename U, typename V,typename W>
auto operator+=(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
} 
template <typename T,typename U, typename V,typename W>                            
auto operator+(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
}
template <typename T> T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}
int partition(int left, int right, vi &a, int pivot)
{
	int j = left, i = left;
    swap(a[right], a[pivot]);
	while(i < right)
	{
		if(a[i] <= a[right])
			swap(a[i], a[j++]);
		i++;
	}
    swap(a[j], a[right]);
	return j;
}
int get_optimal_pivot(int left, int right, vi &a)
{
	int sample_size = 5;
	int i = left;
	while(i <= right)
	{
		f(j, i + 1, min(i + sample_size, right + 1))
		{
			int k = j;
			while(k > i && a[k - 1] > a[k])
			{
				swap(a[k], a[k - 1]);
				k--;
			}
		}	
		swap(a[left + ((i - left) / sample_size)], a[min(i + (right - i + 1) / 
			2 ,i + (sample_size / 2))]);
		i += sample_size;
	}
    int end = left + ((right - left + 1)/sample_size) - 1; 
    f(i, left + 1, end + 1)
    {
        int j = i;
        while(j > left && a[j - 1] > a[j])
        {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
   return left + ((right - left + 1)/sample_size) / 2;
}
int median_of_n_elements(int left, int right, vi &a)
{
	if(left == right)
		return a[left];
	int pivot = get_optimal_pivot(left, right, a);
    pivot = partition(left, right, a, pivot);
   int pos = a.size() / 2;
	if(pivot < pos)
		return median_of_n_elements(pivot + 1, right, a);
	else if(pivot > pos)
		return median_of_n_elements(left, pivot - 1, a);
	else
		return a[pivot];
}
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    int mid = median_of_n_elements(0, n - 1, nums);
    cout<<mid<<endl;
    #define A(i) nums[(1+2*(i)) % (n | 1)]
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
}
};