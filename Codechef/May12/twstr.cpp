// Solution using: Trie

#include <iostream>
#include <string>
#define  sz(V)    (int)V.size()
#define  ln(S)    (int)S.length()
using namespace std;
const int BLN = 1000000000;
const int MAXN = 1000;

int n, q;
string s[MAXN];
int v[MAXN];
string t;

struct node {
	int highid;
	int highv;
	node *children[27];
	
	node (int highid = -1, int highv = -BLN) : highid(highid), highv(highv) {
		for (int i = 0; i < 27; i++)
			children[i] = NULL;
	}
};

class Trie {
	private:
		int MAXTRIE;
		node *nodes;
		int sznodes;
		node *root;
	public:
		Trie() {
			MAXTRIE = 1000000;
			nodes = new node[MAXTRIE];
			sznodes = 1;
			root = &nodes[0];
		}
		void insert(string s, int v, int id) {
			node *cur = root;
			for (int i = 0; i < ln(s); i++) {
				int tmp = (s[i] == '-' ?'z'-'a'+1 :s[i]-'a');
				if (cur->children[tmp] == NULL)
					cur->children[tmp] = &nodes[sznodes++];
				cur = cur->children[tmp];
				
				if (cur->highv < v) {
					cur->highv = v;
					cur->highid = id;
				}
			}
		}
		void printVIP(string s) {
			node *cur = root;
			for (int i = 0; i < ln(s); i++) {
				int tmp = (s[i] == '-' ?'z'-'a'+1 :s[i]-'a');
				cur = cur->children[tmp];
				
				if (cur == NULL)
					break;
			}
			
			cout << (cur == NULL || cur->highid == -1 ?string("NO") :(::s[cur->highid])) << "\n";
		}
};

Trie tr;

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> v[i];
		tr.insert(s[i], v[i], i);
	}
	
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		cin >> t;
		tr.printVIP(t);
	}
	
	return 0;
}
