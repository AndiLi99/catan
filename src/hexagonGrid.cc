#include "hexagonGrid.h"
#include <vector>
#include <queue>

HexagonGrid::HexagonGrid(int radius){
    std::vector<Hexagon> hexes = getPointyTopHexOrder(radius);
    validHexagons.insert(hexes.begin(), hexes.end());

    for (Hexagon hex: validHexagons){
        std::vector<Edge> edges = hex.borders();
        validEdges.insert(edges.begin(), edges.end());
    }
    for (Hexagon hex: validHexagons){
        std::vector<Vertex> vertices = hex.corners();
        validVertices.insert(vertices.begin(), vertices.end());
    }
    std::cout << "number of valid edges" << validEdges.size() << std::endl;

}

std::vector<Hexagon> HexagonGrid::getPointyTopHexOrder(int radius){
    std::vector<Hexagon> results;
    for (int z = -radius; z <=radius; ++z){
        for (int x = std::max(-radius, -z-radius); x <= std::min(radius, -z+radius); ++x){
            int y = -z-x;
            results.emplace_back(Hexagon(x, y, z));
        }
    }
    return results;
}

std::vector<Vertex> HexagonGrid::getPointyTopVertexOrder(int radius){
    std::vector<Hexagon> hexes = getPointyTopHexOrder(radius+1);
    std::deque<Vertex> verticesR;
    std::deque<Vertex> verticesL;
    for (Hexagon hex: hexes){
        Vertex v1 = hex.corner(Corner::R);
        if (validVertices.find(v1) != validVertices.end()){
            verticesR.push_back(v1);
        }
        Vertex v2 = hex.corner(Corner::L);
        if (validVertices.find(v2) != validVertices.end()){
            verticesL.push_back(v2);
        }
    }
    std::vector<Vertex> ret;
    int width = radius+1;
    bool up = true;
    Corner c = Corner::L;
    do {
        std::cout << width << std::endl;
        switch (c){
            case Corner::L:
                for (int i = 0; i < width; ++i){
                    ret.push_back(verticesL.front());
                    verticesL.pop_front();
                }
                if (width == (radius+1)*2){
                    up = false;
                }
                up? ++width: --width;
                c = Corner::R;
            break;
            case Corner::R:
                for (int i = 0; i < width; ++i){
                    ret.push_back(verticesR.front());
                    verticesR.pop_front();
                }
                c = Corner::L;
            break;
            
        }
    } while(!(width == 3 && c == Corner::L));
    return ret;
}

std::vector<Edge> HexagonGrid::getPointyTopEdgeOrder(int radius){
    std::vector<Hexagon> hexes = getPointyTopHexOrder(radius+1);
    std::deque<Edge> edgesW;
    std::deque<Edge> edgesNE;
    for (Hexagon hex: hexes){
        Edge e1 = hex.border(Side::W);
        if (validEdges.find(e1) != validEdges.end()){
            edgesW.push_back(e1);
        }
        Edge e2 = hex.border(Side::N);
        if (validEdges.find(e2) != validEdges.end()){
            edgesNE.push_back(e2);
        }
        Edge e3 = hex.border(Side::E);
        if (validEdges.find(e3) != validEdges.end()){
            edgesNE.push_back(e3);
        }
    }
    std::vector<Edge> ret;
    int width = radius+1;
    bool up = true;
    bool vertical_road = false;
    do {
        std::cout << width << std::endl;
        if (vertical_road)
        {
            for (int i = 0; i < width; ++i){
                ret.push_back(edgesW.front());
                edgesW.pop_front();
            }
            if (width == (radius+1)*2){
                up = false;
            }
            if (!up) --width; 
            vertical_road = !vertical_road;
        }
        else
        {
            for (int i = 0; i < width*2; ++i){
                ret.push_back(edgesNE.front());
                edgesNE.pop_front();
            }
            if (up) ++width;
            vertical_road = !vertical_road;
        } 
    } while(!(width == 3 && vertical_road));
    return ret;
}