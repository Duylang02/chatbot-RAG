#include<iostream>

using namespace std;

int n;
int a[1000][1000] = {0};
pair<int, int> toaThanhs[100];
bool visited[1000] = {false};
int path[1000];
int pathLength = 0;
bool check = false;
int soHieu;
int soPhao;
int soLienKet;
int ans = 0;
int reset(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			a[i][j] = 0;
		}
		visited[i]= false;
		
	}
}
/*
1
7
0 1 3
1 2 3
1 2 2 
3 4
2 3 2
0 5
3 1 4
0 1 5 6
4 2 2
1 6
5 3 2
2 3
6 1 2
3 4
*/
void dfs(int u, int parent, int start){
	visited[u] = true;
	path[pathLength++] = u;
	
	for (int v= 0; v < n; v++){
		if (a[u][v] == 1){
			if (v == start && pathLength > 2){
				
				check = true;
				return;
			}else if (!visited[v]){
				dfs(v,u,start);
				if (check) return;
			}
		}
	}
	visited[u] = false;
	pathLength --;
}

void Sort(){
	pair<int, int> tmp;
	for (int i = 0; i < n; i++){
		for (int j = i+ 1; j < n; j++){
			if (toaThanhs[i].first > toaThanhs[j].first){
				tmp = toaThanhs[i];
				toaThanhs[i] = toaThanhs[j];
				toaThanhs[j] = tmp;
			}
		}
	}
}
int detecCycle(){
	for (int i = 0; i < n; i++){
		check = false;
		pathLength = 0;
		dfs(i, -1, i);	
		if (check == true){
			path[pathLength] = i;

			int dem = 10000000;
			int dinh1, dinh2;
			for (int j = 0; j < pathLength; j++){
				
				int min = toaThanhs[path[j]].second + toaThanhs[path[j+1]].second;
				if (min < dem) {
					dem = min;
					dinh1 = toaThanhs[path[j]].first;
					dinh2 = toaThanhs[path[j + 1]].first;
				}
			}
			a[dinh1][dinh2] = a[dinh2][dinh1] = 0;
			ans += dem;
//			cout <<endl;
//			for (int h = 0; h < n; h++){
//				for (int k = 0; k < n; k++){
//					cout << a[h][k] <<" ";
//				}
//				cout << endl;
//			}
			i--;
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	int test; cin >> test;
	for (int tc = 0; tc < test; tc++){
		cin >> n;
		
		for (int i = 0; i < n; i++){
			
			cin >> soHieu;
			cin >> soPhao;
			cin >> soLienKet;
			pair<int, int> toa_thanh;
			toa_thanh.first = soHieu;
			toa_thanh.second = soPhao;
			toaThanhs[i] = toa_thanh;
			for (int j = 0; j < soLienKet; j++){
				int tmp; cin >> tmp;
				a[soHieu][tmp] = 1;
			}
			
		}
		Sort();

		detecCycle();
		cout << ans <<endl;
	} 
}
