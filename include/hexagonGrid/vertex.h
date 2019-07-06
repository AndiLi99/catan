#ifndef VERTEX
#define VERTEX
enum class Corner{L, R};

struct Vertex{
	int a;
	int b;
	Corner c;
	Vertex(int a, int b, Corner c): a{a}, b{b}, c{c} {}
};

//https://stackoverflow.com/questions/16792751/hashmap-for-2d3d-coordinates-i-e-vector-of-doubles
struct VertexHash{
    size_t operator()(const Vertex &v) const{
    size_t h1 = std::hash<int>()(v.a);
    size_t h2 = std::hash<int>()(v.b);
    size_t h3 = std::hash<Corner>()(v.c);
    return (h1 ^ (h2 << 1)) ^ h3;
    }
};

struct VertexEquals{
  bool operator()( const Vertex& lhs, const Vertex& rhs ) const{
    return (lhs.a == rhs.a) && (lhs.b == rhs.b) && (lhs.c == rhs.c);
  }
};

#endif
