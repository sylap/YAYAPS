# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <functional> // greater<int>()
# include <vector>
# include <string>
# include <queue>
# include <stack>
# include <list>
# include <map>
# include <set>
# include <cstdio>
# include <cstdlib>
# include <cmath>
# include <ctime>
# include <cstring>
# include <cctype>
# include <climits> // LLONG_MAX , LLONG_MIN , INT_MAX , INT_MIN

# define  all(A)		(A).begin() , (A).end()
# define  rall(A)		(A).rbegin() , (A).rend()
# define  sz(A)			(int)(A).size()
# define  pb			push_back
# define  mp			make_pair
# define  frt			first
# define  scd			second
# define  rsz(A,X)		(A).resize(X)
# define  ln(A)			(int)(A).length()
# define  mmmset(X, A)	memset((x), (a), sizeof(x))

# define FOR(i, a, b)  \
		for (int i=a; i<b; i++)
# define FORD(i, a, b)  \
		for (int i=a-1; i>=b; i--)
# define  REP(i,n)  \
		for( int i=0 ; i<n ; i++ )
# define  REPD(i,n)  \
		for( int i=n-1 ; i>=0 ; i-- )
# define  REK(IDFR,EXPRESSION,CHANGE)  \
		for( int IDFR ; EXPRESSION ; CHANGE )
# define  TR(it,container)  \
		for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
# define  present(container, element) (container.find(element) != container.end()) 
# define  cpresent(container, element) (find(all(container),element) != container.end()) 

#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;

time_t st=clock();
using namespace std;

template <class stl>
void DBGSTL (stl a) { // for deque, vector , set
	cout<<"\tDEBUG:\n\t";
	TR(i,a){
		cerr<<*i<<" ";
	}
	cerr<<"\n";
	return;
}

typedef long long i64;

typedef		vector<int>		vi;
typedef		vector<vi>		vvi;
typedef		pair<int,int>	pii;
typedef		vector<pii>		vpii;
typedef		vector<vpii>	vvpii;
typedef		vector<i64>		vll;
typedef		vector<vll>		vvll;
typedef		pair<i64,i64>	pll;
typedef		vector<pll> 	vpll;
typedef		vector<vpll>	vvpll;
typedef		vector<string>	vs;
typedef		vector<vs>		vvs;
typedef		vector<bool>	vb;
typedef		vector<vb>		vvb;
typedef		vector<char>	vc;
typedef		vector<vc>		vvc;

i64 gcd( i64 a , i64 b )
{    return ( b==0 ?a :gcd(b,a%b) );    }
i64 lcm( i64 a , i64 b )
{    return a/gcd(a,b)*b;    }

//                   up       down      left     right                              up_l     down_r     up_r      down_l
//int dir[8][2]={ {-1,+0} , {+1,+0} , {+0,-1} , {+0,+1} /* add diagonals --> */ , {-1,-1} , {+1,+1} , {-1,+1} , {+1,-1} };

int res=8;
int d[4][4];

void rotate(int id,int tt)
{
	switch(id)
	{
		case 1:
			d[0][1]=(d[0][1]-1+tt)%4+1;
			d[1][3]=(d[1][3]-1+tt)%4+1;
			d[2][0]=(d[2][0]-1+tt)%4+1;
			d[3][2]=(d[3][2]-1+tt)%4+1;
			break;
		
		case 2:
			d[0][2]=(d[0][2]-1+tt)%4+1;
			d[1][0]=(d[1][0]-1+tt)%4+1;
			d[2][3]=(d[2][3]-1+tt)%4+1;
			d[3][1]=(d[3][1]-1+tt)%4+1;
			break;
		
		case 3:
			d[1][1]=(d[1][1]-1+tt)%4+1;
			d[1][2]=(d[1][2]-1+tt)%4+1;
			d[2][1]=(d[2][1]-1+tt)%4+1;
			d[2][2]=(d[2][2]-1+tt)%4+1;
			break;
		
		case 4:
			d[0][0]=(d[0][0]-1+tt)%4+1;
			d[0][3]=(d[0][3]-1+tt)%4+1;
			d[3][0]=(d[3][0]-1+tt)%4+1;
			d[3][3]=(d[3][3]-1+tt)%4+1;
			break;
		
		default:
			cout<<"GO CRAZY GO CRAZY !! )))";
			break;
	}
}

bool solved()
{
	return
	(
	d[0][0]==d[0][1] && d[0][1]==d[1][0] && d[1][0]==d[1][1] &&
	d[0][2]==d[0][3] && d[0][3]==d[1][2] && d[1][2]==d[1][3] &&
	d[2][0]==d[2][1] && d[2][1]==d[3][0] && d[3][0]==d[3][1] &&
	d[2][2]==d[2][3] && d[2][3]==d[3][2] && d[3][2]==d[3][3]
	);
}

void recurse(int id,int tt,int sum)
{
	rotate(id,tt);
	
	sum+=( tt%2 ?1 :tt );
	
	if( id<4 )
	{
		recurse(id+1,0,sum);
		recurse(id+1,1,sum);
		recurse(id+1,2,sum);
		recurse(id+1,3,sum);
	}
	
	else
	if ( solved() && res>sum )
	res=sum;
	
	rotate(id,(4-tt)%4);
}

int main()
{
	REP(i,4)
	REP(j,4)
	cin>>d[i][j];
	
	recurse(1,0,0);
	recurse(1,1,0);
	recurse(1,2,0);
	recurse(1,3,0);
	
	cout<<res;
	
	/*
	cout<<clock()-st;
	getchar();
	getchar();
	*/
	return 0;
}
