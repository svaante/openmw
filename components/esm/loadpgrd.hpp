#ifndef _ESM_PGRD_H
#define _ESM_PGRD_H

#include "esm_reader.hpp"

namespace ESM
{

/*
 * Path grid.
 */
struct Pathgrid
{
    struct DATAstruct
    {
        int x, y; // Grid location, matches cell for exterior cells
        short s1; // ?? Usually but not always a power of 2. Doesn't seem
                  // to have any relation to the size of PGRC.
        short s2; // Number of path points.
    }; // 12 bytes

    struct Point // path grid point
    {
        int x, y, z; // Location of point
        int unknown; // Possibly flag for coloring/user-placed vs auto-generated
    }; // 16 bytes

    struct Edge // path grid edge
    {
        int v0, v1; // index of points connected with this edge
    }; // 8 bytes

    std::string cell; // Cell name
    DATAstruct data;

    typedef std::vector<Point> PointList;
    PointList points;

    typedef std::vector<Edge> EdgeList;
    EdgeList edges;

    void load(ESMReader &esm);
};
}
#endif
