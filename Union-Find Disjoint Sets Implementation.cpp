#define REP(i, j) for (int i=0 ; i<j ; i++)
int _sc;

void initSet(int N) {
    REP(i, N) p[i] = i; _sc=N;
}

int findSet(int i) {
	return p[i] == i ? i : (p[i] = findSet(p[i]));
}

bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}

void unionSet(int i, int j) {
	if (!isSameSet(i, j)) p[findSet(i)] = findSet(j), _sc--;
}