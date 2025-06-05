#include "BoundingBox.h"

//constructor
BoundingBox::BoundingBox(Point2d topLeft, Point2d bottomRight)
    : topLeft(topLeft)
    , bottomRight(bottomRight)
{}

// checks if 2 bounding boxes overlap
bool BoundingBox::intersects(const BoundingBox& other) const {
    if (bottomRight.m_x < other.topLeft.m_x ||  // this box is left of other
        topLeft.m_x > other.bottomRight.m_x ||  // this box is right of other
        topLeft.m_y < other.bottomRight.m_y ||  // this box is below other 
        bottomRight.m_y > other.topLeft.m_y     // this box is above other
    ) { return false; }
    
    return true;
}
static bool intersects(const BoundingBox& box1, const BoundingBox& box2){
    return box1.intersects(box2);
}
