#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef pair<int,int> pt;
typedef pair<long long ,long long> ptl;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;  
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define F first
#define S second
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
int b, l, d;
vector <int> book_score, n, t, m;
vector<vector<int>> id;
vector <int> lib_str;
vector<int> scoresV1;
vector<double> scoresV2;	
bool compareV1(const int& libA, const int& libB)
{
	return scoresV1[libA] > scoresV1[libB];
}
vector <int> getLibSeqV1()		//avg score * signuptime {Wastage factor}
{	
	vector<int> libToSort; // initialize with 
							//initial library positions
	for(int i=0; i<l; i++)
		libToSort.push_back(i);
	
	for(int lib=0; lib<l; lib++)
	{
		int totScore=0;
		for(int j=0; j<n[lib]; j++)
			totScore+=   book_score[ id[lib][j] ];
		// float days = ceil(n[lib] / m[lib]);
		// float score = (totScore/days)*t[lib];
		scoresV1.push_back(totScore); 
	}

	sort(libToSort.begin(), libToSort.end(), compareV1);

	return libToSort;	
}
bool compareV2(const int& libA, const int& libB ){
	return scoresV2[libA] > scoresV2[libB];
}

vector<int> getLibSeqV2()    //strong to weak  // uses  sum of (score/frequency) divided by total time taken by that library
{
	vector<int> libToSort; // initialize with 
									//initial library positions
	for(int i=0; i<l; i++)
		libToSort.push_back(i);
	
	vector<int> bookFreq(b,0);
	
	for(int lib=0; lib< l; lib++)		// building freq array
	{
		for(int j=0; j < n[lib]; j++)
			bookFreq[ id[lib][j]] +=1;
	}

	for(int lib=0; lib<l; lib++)
	{	double libScore=0;
		for(int j=0; j < n[lib]; j++)
		{	int book_id = id[lib][j];
			libScore += 1/(double)(bookFreq[ book_id ]);
		}
		libScore = (libScore/ (double)(t[lib]))*m[lib];
		scoresV2.push_back(libScore);

	}

	sort(libToSort.begin(), libToSort.end(), compareV2);
	return libToSort;



}

ll getScoreByFreq(int score, int freq)
{
	ll temp = ((double)score / (double)freq) * 100000;
	return temp;
}
int buildMap(unordered_map <int,int> &lib_cap, vi &signup_lib)
{
	int lib_id;
	int cap = 0;
	f(i, 0, signup_lib.size())
	{
		lib_id = signup_lib[i];
		lib_cap[lib_id] = m[lib_id];
		cap += m[lib_id];
	}
	return cap;
}
int buildAns(vi &lib_seq)
{
	vi freq(b, 0);
	vector<bool> flag(b, false);
	vector <set<pair<int,int>>> curr_book_lib(b);
	set <pair<ll, int>> avail; 	//<score/freq, book_id>
	int x = 0;
	int pro_id = lib_seq[x++];
	int pro_timer = t[pro_id];
	map <int, vi> ans;
	vi signup_lib;
	unordered_map <int, int> lib_cap;
	f(i, 0, d)
	{
		if(pro_timer == 0)
		{
			signup_lib.pb(pro_id);
			f(j, 0, id[pro_id].size())
			{
				int book_id = id[pro_id][j];
				if(flag[book_id])
					continue;
				
				curr_book_lib[book_id].insert(mp(lib_str[pro_id], pro_id));
				
				freq[book_id]++;
				if(freq[book_id] > 1)
				{
					avail.erase(
						avail.lb(
							mp(getScoreByFreq(book_score[book_id], freq[book_id] - 1), book_id)
						)
					);
				}
				avail.insert(
					mp(getScoreByFreq(book_score[book_id], freq[book_id]), book_id)
				);
			}
			if(x < lib_seq.size())
			{
				pro_id  = lib_seq[x++];
				pro_timer = t[pro_id];
			}
		}
		pro_timer--;

		int cap = buildMap(lib_cap, signup_lib);
		
		set <pair<ll, int>> :: reverse_iterator it = avail.rbegin();
		vi future_erase;
		while(cap > 0 && it != avail.rend())
		{
			// if(avail.empty())
			// 	break;
			int book_id = (*it).S;
			for(set<pair<int,int>> :: iterator j = curr_book_lib[book_id].begin(); j != curr_book_lib[book_id].end(); j++)
			{
				int lib_id = (*j).S;
				if(lib_cap[lib_id] > 0)
				{
					lib_cap[lib_id]--;
					ans[lib_id].pb(book_id);
					flag[book_id] = true;
					future_erase.pb(book_id);
					// avail.erase(
					// 	avail.lb(
					// 		mp(getScoreByFreq(book_score[book_id], freq[book_id]), book_id)
					// 	)
					// );
					cap--;
					break;
				}
			}
			it++;
		}
		f(j, 0, future_erase.size())
		{
			int book_id = future_erase[j]; 
			avail.erase(
				avail.lb(
					mp(getScoreByFreq(book_score[book_id], freq[book_id]), book_id)
				)
			);
		}
	}
	cout<<ans.size()<<endl;
	f(i, 0, lib_seq.size())
	{
		int lib_id = lib_seq[i];
		if(ans.find(lib_id) == ans.end())
			continue;
		cout<<lib_id<<" "<<ans[lib_id].size()<<endl;
		f(j, 0, ans[lib_id].size())
		{
			cout<<ans[lib_id][j]<<" ";
		}
		cout<<endl;
	}
}
void solution()
{
	cin>>b>>l>>d;
	book_score.resize(b);
	f(i, 0, b)
	{
		cin>>book_score[i];;
	}
	n.resize(l);
	t.resize(l);
	m.resize(l);
	id.resize(l);
	int temp;
	f(i, 0, l)
	{
		cin>>n[i]>>t[i]>>m[i];
		f(j, 0, n[i])
		{
			cin>>temp;
			id[i].pb(temp);
		}
	}
	vi lib_seq = getLibSeqV2();
	lib_str.resize(l);
	// cout<<"lib_seq"<<endl;
	f(i, 0, lib_seq.size())
	{
		// cout<<lib_seq[i]<<" ";
		lib_str[lib_seq[i]] = i;
	}
	// cout<<endl;
	buildAns(lib_seq);
}
void testCase()
{
	int t = 1;
	// cin>>t;
	f(i, 0, t)
	{
		solution();
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   