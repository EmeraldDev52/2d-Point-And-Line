#include "BoundingBox.h"

//constructor
BoundingBox::BoundingBox(double minX, double maxX, double minY, double maxY)
    : minX(minX)
    , maxX(maxX)
    , minY(minY)
    , maxY(maxY) 
{}

// checks if 2 bounding boxes overlap
bool BoundingBox::intersects(const BoundingBox& other) const {
    return !(other.minX > maxX || other.maxX < minX || 
             other.minY > maxY || other.maxY < minY);
}
static bool intersects(const BoundingBox& box1, const BoundingBox& box2){
    return box1.intersects(box2);
}
