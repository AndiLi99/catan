/*
    Returns the positive modulo of i mod n.
 */
inline int positive_modulo(int i, int n) {
    return (i % n + n) % n;
}