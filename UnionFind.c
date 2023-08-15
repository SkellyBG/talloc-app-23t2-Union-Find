struct UnionFindRep {
	int *parent;
	int size;
};

typedef struct UnionFindRep *UnionFind;

UnionFind UnionFindNew(int size) {
	UnionFind uf = malloc(sizeof(struct UnionFindRep));
	uf->parent = malloc(sizeof(int) * size);
	uf->size = size;
	for (int i = 0; i < size; i++) {
		uf->parent[i] = i;
	}
	return uf;
}

void UnionFindFree(UnionFind uf) {
	free(uf->parent);
	free(uf);
}

void UnionFindUnion(UnionFind uf, int v1, int v2) {
	uf->parent[UnionFindRoot(uf, v1)] = UnionFindRoot(uf, v2);
}

int UnionFindRoot(UnionFind uf, int v) {
	if (uf->parent[v] != v) {
		uf->parent[v] = UnionFindRoot(uf, uf->parent[v]);
	}
	return uf->parent[v];
}