#ifndef EDGE
#define EDGE
enum Side{W, N, E};

struct Edge {
	int a;
	int b;
	Side s;
	Edge(int a, int b, Side s): a{a}, b{b}, s{s} {}
};

#endif
