#include "../include/Geo2d/BoundingBox.h"
#include "../include/Geo2d/Vector2d.h"



namespace Geo2d{
    // constructor
    BoundingBox::BoundingBox(Vector2d tl, Vector2d br)
        : topLeft{tl}
        , bottomRight{br}
    {}


    // checks if 2 bounding boxes overlap
    bool BoundingBox::intersects(const BoundingBox& other) const {
        if (bottomRight.x < other.topLeft.x ||  // this box is left of other
            topLeft.x > other.bottomRight.x ||  // this box is right of other
            topLeft.y < other.bottomRight.y ||  // this box is below other 
            bottomRight.y > other.topLeft.y     // this box is above other
        ) { return false; }

        return true;
    }
    // static method to check if two bounding boxes overlap
    bool BoundingBox::intersects(const BoundingBox& box1, const BoundingBox& box2){
        return box1.intersects(box2);
    }
}